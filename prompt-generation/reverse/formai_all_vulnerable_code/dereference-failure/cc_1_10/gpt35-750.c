//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_OF_BITS 177         
#define NUM_OF_ELEMENTS 53      

typedef struct exQRData {       
    uint32_t version;
    uint32_t maskIndex;
    uint8_t data[NUM_OF_ELEMENTS][NUM_OF_ELEMENTS];
} exQRData;

void decodeQR(char* string, uint8_t* data) {
    /* QR decoding algorithm goes here */
    /* 
       ...
    */
    strncpy((char*)data, string, NUM_OF_ELEMENTS*NUM_OF_ELEMENTS);
}

int main(int argc, char* argv[]) {
    if (argc != 2 || strlen(argv[1]) != NUM_OF_BITS) {
        printf("Invalid input argument length!\n");
        return -1;
    }

    exQRData qrData;
    decodeQR(argv[1], (uint8_t*)qrData.data);

    /* Shape shifting starts here */
    srand(qrData.version);

    for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
        for (int j = 0; j < NUM_OF_ELEMENTS; j++) {
            int randomNum = rand() % 4;

            switch (randomNum) {
                case 0:
                    qrData.data[i][j] = qrData.data[i][j] ^ qrData.maskIndex;
                    break;
                case 1:
                    qrData.data[i][j] = qrData.data[j][i];
                    break;
                case 2:
                    qrData.data[i][j] = qrData.data[NUM_OF_ELEMENTS-1-i][NUM_OF_ELEMENTS-1-j];
                    break;
                case 3:
                    qrData.data[i][j] = qrData.data[NUM_OF_ELEMENTS-1-j][i];
                    break;
            }
        }
    }

    printf("Shape shifted QR code:\n");
    for (int i = 0; i < NUM_OF_ELEMENTS; i++) {
        for (int j = 0; j < NUM_OF_ELEMENTS; j++) {
            printf("%d ", qrData.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}