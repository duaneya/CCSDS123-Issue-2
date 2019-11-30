#include <stdint.h>
char codeTable1[][128] = {
"000","001","002","003","004","005","006","007","008","009","00A","00X","01","02","030","031","032","033","034","035","036","037","038","039","03A","03X","040","041","042","043","044","045","046","047","048","049","04A","04X","05","06","07","08","09","0A","0X","10","11","12","130","131","132","133","134","135","136","137","138","139","13A","13X","14","150","151","152","153","154","155","156","157","158","159","15A","15X","160","161","162","163","164","165","166","167","168","169","16A","16X","17","18","19","1A","1X","20","21","22","230","231","232","233","234","235","236","237","238","239","23A","23X","24","250","251","252","253","254","255","256","257","258","259","25A","25X","26","27","28","29","2A","2X","3","4","5","6","7","8","9","A0","A1","A2","A3","A4","A5","A6","A7","A8","A9","AA","AX","X",
};
uint32_t outPutCodes1[] = {
0x73,0x0B,0x4B,0x9B,0x5B,0x137,0x0B7,0x11F,0x31F,0x63F,0x13F,0x53F,0x0E,0x1E,0xDB,0x3B,0xBB,0x1B7,0x077,0x177,0x0F7,0x09F,0x33F,0x57F,0xD7F,0x73F,0x7B,0xFB,0x07,0x1F7,0x00F,0x10F,0x29F,0x0BF,0x4BF,0x37F,0xB7F,0x2BF,0x1D,0x3D,0x13,0x53,0x0E7,0x1E7,0x2B,0x01,0x11,0x09,0x87,0x47,0xC7,0x08F,0x18F,0x19F,0x39F,0x6BF,0x1BF,0x77F,0xF7F,0x0FF,0x03,0x04F,0x14F,0x0CF,0x05F,0x25F,0x15F,0x5BF,0x8FF,0x4FF,0x03FF,0x13FF,0xCFF,0x1CF,0x02F,0x12F,0x35F,0x0DF,0x3BF,0x7BF,0x2FF,0xAFF,0x0BFF,0x1BFF,0x07FF,0xAB,0x6B,0x017,0x117,0x097,0x19,0x05,0x15,0x27,0xA7,0x67,0x0AF,0x1AF,0x2DF,0x1DF,0x07F,0x47F,0x6FF,0xEFF,0x1FF,0x23,0x06F,0x16F,0x0EF,0x3DF,0x03F,0x27F,0x67F,0x9FF,0x5FF,0x17FF,0x0FFF,0x1FFF,0x33,0xEB,0x1B,0x197,0x057,0x157,0x0,0x4,0x2,0xA,0x06,0x16,0x0D,0x0D7,0x1D7,0x037,0x1EF,0x3EF,0x01F,0x21F,0x23F,0x17F,0x0DFF,0x1DFF,0x97F,0x2D,
};
uint8_t bitSizes1[] = {
7, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 11, 5, 5, 8, 8, 8, 9, 9, 9, 9, 10, 11, 12, 12, 11, 8, 8, 8, 9, 9, 9, 10, 11, 11, 12, 12, 11, 6, 6, 7, 7, 9, 9, 8, 5, 5, 5, 8, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 6, 9, 9, 9, 10, 10, 10, 11, 12, 12, 13, 13, 12, 9, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 8, 8, 9, 9, 9, 5, 5, 5, 8, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 12, 6, 9, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 7, 8, 8, 9, 9, 9, 3, 3, 4, 4, 5, 5, 6, 9, 9, 9, 10, 10, 10, 10, 11, 12, 13, 13, 12, 6, 
};