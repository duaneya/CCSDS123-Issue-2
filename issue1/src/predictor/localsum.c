#include "predictor.h"
#include "cliparser/cli.h"
#include <stdio.h>

/*
	Chapter 4.4 in CCSDS 123 Issue 2
*/

inline int32_t wideNeighborLocalSum(uint16_t * sample, uint16_t x, uint16_t y, uint16_t z, struct arguments * parameters) {
	if (x+y != 0) {
		if (y == 0 && x > 0){
			return 4 * sample[offset(x-1,y,z, parameters)];
		} else if (y > 0 && x > 0 && x < parameters->xSize-1) {
			return  sample[offset(x-1,y,z, parameters)] + sample[offset(x-1,y-1,z, parameters)] + sample[offset(x,y-1,z, parameters)] + sample[offset(x+1,y-1,z, parameters)];
		} else if (y > 0 && x == 0) {
			return  2 * (sample[offset(x+1,y-1,z, parameters)] + sample[offset(x,y-1,z, parameters)]);
		} else {
			return  sample[offset(x-1,y,z, parameters)] + sample[offset(x-1,y-1,z, parameters)] + 2 * sample[offset(x,y-1,z, parameters)];
		}
	} else {
		return 0;
	}
}

int32_t wideColumnLocalSum(uint16_t * sample, uint16_t x, uint16_t y, uint16_t z, struct arguments * parameters) {
	if(x+y != 0) {
		if(y > 0) {
			return  4 * sample[offset(x,y-1,z, parameters)];
		} else {
			return  4 * sample[offset(x-1,y,z, parameters)];
		}
	}
}
