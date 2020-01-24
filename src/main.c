
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

#include "cliparser/include/cli.h"
#include "predictor/include/predictor.h"
#include "encoder/include/encoder.h"
#include "utils/include/utilities.h"
#include <sys/time.h>


void insertTestData(uint32_t * sample, struct arguments * args){
	sample[offset(0,0,0, args)] = 255;
	sample[offset(1,0,0, args)] = 256;
	sample[offset(2,0,0, args)] = 257;
	sample[offset(3,0,0, args)] = 258;

	sample[offset(0,1,0, args)] = 254;
	sample[offset(1,1,0, args)] = 253;
	sample[offset(2,1,0, args)] = 256;
	sample[offset(3,1,0, args)] = 257;

	sample[offset(0,2,0, args)] = 258;
	sample[offset(1,2,0, args)] = 259;
	sample[offset(2,2,0, args)] = 253;
	sample[offset(3,2,0, args)] = 255;

	sample[offset(0,3,0, args)] = 256;
	sample[offset(1,3,0, args)] = 257;
	sample[offset(2,3,0, args)] = 258;
	sample[offset(3,3,0, args)] = 259;

	//
	sample[offset(0,0,1, args)] = 253;
	sample[offset(1,0,1, args)] = 254;
	sample[offset(2,0,1, args)] = 256;
	sample[offset(3,0,1, args)] = 257;

	sample[offset(0,1,1, args)] = 258;
	sample[offset(1,1,1, args)] = 259;
	sample[offset(2,1,1, args)] = 253;
	sample[offset(3,1,1, args)] = 258;

	sample[offset(0,2,1, args)] = 256;
	sample[offset(1,2,1, args)] = 253;
	sample[offset(2,2,1, args)] = 252;
	sample[offset(3,2,1, args)] = 251;

	sample[offset(0,3,1, args)] = 253;
	sample[offset(1,3,1, args)] = 254;
	sample[offset(2,3,1, args)] = 256;
	sample[offset(3,3,1, args)] = 257;
}

void writearary(uint32_t * sample, struct arguments * args) {
    FILE * file = fopen("test.bin", "w+b");

	for (int z = 0; z < args->zSize; z++)
	{
		for (int y = 0; y < args->ySize; y++)
		{
			for (int x = 0; x < args->xSize; x++)
			{
				fwrite(&sample[offset(x,y,z,args)], 1, 2, file);
			}

		}

	}

	fclose(file);
}


int main(int argc, char **argv) {
	double start;
	double computeTime=0, predictionTime = 0, encoderTime = 0;
	double readTime=0;
  	double writeTime=0;
	/*
		Parse arguments. --h to see what available arguments(declared in cli.c)
	*/
	struct arguments parameters;
	parseArguments(argc, argv, &parameters);

	/*
		LOSSLESS Compression:
	 */

	// IMAGE
	uint32_t * sample = malloc(parameters.xSize*parameters.ySize*parameters.zSize*sizeof(uint32_t));
	uint32_t * residuals = malloc(parameters.xSize*parameters.ySize*parameters.zSize*sizeof(uint32_t));
	/*
		PREDICTION SPECIFIC MALLOCS
	*/
	uint32_t * sampleRep = malloc(parameters.xSize*parameters.ySize*parameters.zSize*sizeof(uint32_t));

	int32_t * weights = malloc((parameters.mode != REDUCED ? parameters.precedingBands+3 : parameters.precedingBands) * sizeof(int32_t ));
	int32_t * diffVector = malloc((parameters.mode != REDUCED ? parameters.precedingBands+3 : parameters.precedingBands) * sizeof(int32_t ));
	/*
		ENCODING SPECIFIC MALLOCS
	*/
    uint16_t * counter = malloc(sizeof(uint16_t)*parameters.zSize);
    uint64_t * accumulator = malloc(sizeof(uint64_t)*parameters.zSize);

	FILE * residuals_file = fopen("Encoded.bin", "w+b");
	FILE * deltafile = fopen("Encoded.bin.delta", "wb");
	//insertTestData(sample, &parameters);
	//writearary(sample, &parameters);

	unsigned int numWrittenBits = 0;
	unsigned int totalWrittenBytes = 0;

	/*
		ACTUAL COMPUTATION/WRITING
	*/
	//printf("Det funker ikke\n");
	printf("Started reading %d\n", parameters.debugMode);
	readIntSamples(&parameters, parameters.fileName, sample);

	//hashFlushCodes();
	//hashCodeTableValues();

	printf("Computing \n");
	start = walltime();
	printf("begun \n");

 	for (uint16_t z = 0; z < parameters.zSize; z++) {
		counter[z] = 1 << parameters.initialY;
		accumulator[z] = ((counter[z] * ((3 * (1 << (parameters.initialK+6))) - 49)) >> 7);
		for (uint16_t y = 0; y < parameters.ySize; y++) {
			for (uint16_t x = 0; x < parameters.xSize; x++) {
				uint32_t tempResidual = predict(sample, x, y, z, &parameters, sampleRep, diffVector, weights, 0, 0, 0, 0, 0);
				// Currently only BSQ encoding mode
				fwrite((&tempResidual), 1, 4, deltafile);
				//encodeSampleAdaptive(tempResidual, counter, accumulator, x, y, z, &totalWrittenBytes, &numWrittenBits, residuals_file, &parameters);
				//encodeHybrid(tempResidual, counter, accumulator, x, y, z, &totalWrittenBytes, &numWrittenBits, residuals_file, &parameters);
			}
		}
		//encodeFinalStage(accumulator, z,  &totalWrittenBytes, &numWrittenBits, residuals_file, &parameters);
	}
	printf("begun \n");
	computeTime += walltime() - start;

	printf("\n");
	printf("Compute time:          %4.6f s\n",computeTime);
	printf("Average time per pixel(compute time/total pixels):          %7.4f ms\n",(computeTime*1e3)/(double)(parameters.xSize*parameters.ySize*parameters.zSize));
	printf("Average time per frame(compute time/z pixels):          %7.4f ms\n",(computeTime*1e3)/(double)(parameters.zSize));

	/*
		END OF COMPUTATION/WRITING
	*/

	fclose(residuals_file);
	fclose(deltafile);

	// Free up stuff
	free(accumulator);
	free(counter);
	free(sampleRep);
	free(sample);
 	free(weights);
	free(diffVector);

	return 0;
}
