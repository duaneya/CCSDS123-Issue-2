#include <stdint.h>

char codeTable3[][128] = {
"000","0010","0011","0012","0013","0014","0015","0016","001X","0020","0021","0022","0023","0024","0025","0026","002X","003","004","005","006","00X","01","02","03","04","05","06","0X","1","20","210","2110","2111","2112","2113","2114","2115","2116","211X","212","213","214","215","216","21X","220","2210","2211","2212","2213","2214","2215","2216","221X","222","223","224","225","226","22X","230","231","232","233","234","235","236","23X","24","25","26","2X","30","310","311","312","313","314","315","316","31X","320","321","322","323","324","325","326","32X","33","34","35","36","3X","40","410","411","412","413","414","415","416","41X","42","43","44","45","46","4X","5","60","61","62","63","64","65","66","6X","X",
};
uint32_t outPutCodes3[] = {
0x19,0x4B,0x17,0x97,0x0EF,0x1EF,0x37F,0x77F,0x9FF,0x2B,0x57,0xD7,0x01F,0x11F,0x0FF,0x4FF,0x5FF,0x43,0x23,0x18F,0x04F,0x14F,0x2,0xA,0x1E,0x01,0x2D,0x6D,0x6B,0x0,0x6,0x35,0x37,0x09F,0x19F,0x23F,0x13F,0xDFF,0x3FF,0x0FFF,0x63,0x3B,0xBB,0x2DF,0x1DF,0x1BF,0x0D,0xB7,0x05F,0x15F,0x33F,0x0BF,0xBFF,0x7FF,0x1FFF,0x13,0x7B,0xFB,0x3DF,0x03F,0x5BF,0x53,0x07,0x87,0x0CF,0x1CF,0x3BF,0x7BF,0xAFF,0x25,0xEB,0x1B,0x9B,0x11,0x33,0x47,0xC7,0x02F,0x12F,0x07F,0x47F,0x6FF,0x73,0x27,0xA7,0x0AF,0x1AF,0x27F,0x67F,0xEFF,0x1D,0x5D,0x077,0x177,0x0F7,0x09,0x0B,0x67,0xE7,0x06F,0x16F,0x17F,0x57F,0x1FF,0x15,0x3D,0x7D,0x1F7,0x00F,0x0DF,0x0E,0x03,0x5B,0xDB,0x10F,0x08F,0x2BF,0x6BF,0x2FF,0x05,
};
uint8_t bitSizes3[] = {
5, 7, 8, 8, 9, 9, 11, 11, 12, 7, 8, 8, 9, 9, 11, 11, 12, 7, 7, 9, 9, 9, 4, 4, 5, 5, 7, 7, 8, 2, 4, 6, 8, 9, 9, 10, 10, 12, 12, 13, 7, 8, 8, 10, 10, 11, 6, 8, 9, 9, 10, 10, 12, 12, 13, 7, 8, 8, 10, 10, 11, 7, 8, 8, 9, 9, 11, 11, 12, 6, 8, 8, 8, 5, 7, 8, 8, 9, 9, 11, 11, 12, 7, 8, 8, 9, 9, 11, 11, 12, 7, 7, 9, 9, 9, 5, 7, 8, 8, 9, 9, 11, 11, 12, 6, 7, 7, 9, 9, 10, 5, 7, 8, 8, 9, 9, 11, 11, 12, 6, 
};