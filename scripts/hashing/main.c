#include "uthash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct codeWord {
    char *inputCodeword; //Given ID
    int codeWordValue; //Name
    int bitSize; //length of name
    UT_hash_handle hh;
} codeWord;

struct codeWord *codeWords = NULL;

char inputCodes0[][128] = {
    "00", "010", "011", "012", "013", "014", "015", "016", "017", "018", "019", "01A", "01B", "01C", "01X", "020", "021", "022", "023", "024", "025", "026", "027",
    "028", "029", "02A", "02B", "02C", "02X", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0X", "1", "2", "3", "40", "41", "42", "43", "440", "441",
    "442", "443", "444", "445", "446", "447", "448", "449", "44A", "44B", "44C", "44X", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4X", "5", "6", "70", "71",
    "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7X", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8X", "9",
    "A", "B", "C", "X"
};

int outputCode0[] = {
    0x19, 0x57, 0xD7, 0x37, 0x0AF, 0x1AF, 0x06F, 0x16F, 0x03F, 0x23F, 0x17F, 0x57F, 0x1FF, 0x9FF, 0x37F, 0xB7, 0x77, 0xF7, 0x0EF, 0x1EF, 0x01F, 0x11F, 0x13F, 0x33F, 0x77F, 0x0FF, 0x5FF, 0xDFF, 0x4FF, 0x15, 0x35, 0x0D, 0x2D, 0x13, 0x53,
    0x3B, 0xBB, 0x00F, 0x10F, 0x7B, 0x0, 0x4, 0x2, 0x1D, 0x3D, 0x03, 0x23, 0x09F, 0x19F, 0x05F, 0x0BF, 0x2BF, 0x1BF, 0x3BF, 0x2FF, 0x6FF, 0x3FF, 0xBFF, 0x0FFF, 0x1FFF, 0x7FF, 0x33, 0x73, 0xFB, 0x07, 0x08F, 0x18F, 0x04F, 0x14F, 0x87,
    0x6, 0xE, 0x0B, 0x4B, 0x2B, 0x47, 0xC7, 0x27, 0xA7, 0x0CF, 0x1CF, 0x15F, 0x35f, 0x07F, 0x47F, 0x0DF, 0x6B, 0x1B, 0x5B, 0x67, 0xE7, 0x17, 0x97, 0x02F, 0x12F, 0x2DF, 0x1DF, 0x27F, 0x67F, 0x3DF, 0x01, 0x11, 0x05, 0x25, 0x09
};

int bitSize0[] = {
    5, 8, 8, 8, 9, 9, 9, 9, 10, 10, 11, 11, 12, 12, 11, 8, 8, 8, 9, 9, 9, 9, 10, 10, 11, 11, 12, 12, 11, 6, 6, 6, 6, 7, 7,
    8, 8, 9, 9, 8, 3, 3, 3, 6, 6, 6, 6, 9, 9, 9, 10, 10, 10, 10, 11, 11, 12, 12, 13, 13, 12, 7, 7, 8, 8, 9, 9, 9, 9, 8,
    4, 4, 7, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 11, 11, 10, 7, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 11, 11, 10, 5, 5, 6, 6, 5
};



int main(int argc, char const *argv[]) {

    printf("%ld \n", sizeof(inputCodes0) / sizeof(inputCodes0[0]));
    return 0;
}