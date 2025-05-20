//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define POLY 0x8408
#define INIT 0xFFFF

uint16_t calc_crc16(uint8_t *data, int len);
void print_checksum(uint8_t *data, int len);

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: %s <data>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int len = strlen(argv[1]);
    uint8_t *data;

    data = (uint8_t*) malloc(len);

    for(int i=0;i<len;i++) {
        data[i] = argv[1][i];
    }

    printf("Calculating checksum for \"%s\"\n", data);

    print_checksum(data, len);

    printf("Done\n");

    return EXIT_SUCCESS;
}

uint16_t calc_crc16(uint8_t *data, int len) {

    uint16_t crc = INIT;
    int i,j;

    for(i=0;i<len;i++) {
        crc ^= (uint16_t)data[i];

        for(j=0;j<8;j++) {
            if(crc & 0x0001) {
                crc >>= 1;
                crc ^= POLY;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

void print_checksum(uint8_t *data, int len) {

    uint16_t checksum = calc_crc16(data, len);

    printf("CRC16 Checksum: 0x%04x\n", checksum);
}