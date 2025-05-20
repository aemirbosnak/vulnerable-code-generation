//FormAI DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 100000

int getBit(unsigned char byte, int position) {
    return (byte >> position) & 1;
}

void setBit(unsigned char *byte, int position, int bit) {
    *byte ^= (-bit ^ *byte) & (1 << position);
}

void encode(unsigned char* data, unsigned char* image, int dataLen, int imageLen) {
    unsigned char bit;
    int dataIdx = 0;

    for (int i = 0; i < imageLen; i += 3) {
        if (dataIdx < dataLen) {
            for (int j = 7; j >= 0; j--) {
                if (dataIdx < dataLen) {
                    bit = getBit(data[dataIdx], j);
                } else {
                    bit = 0;
                }

                setBit(&image[i], j, bit);

                dataIdx++;
            }
        } else {
            break;
        }
    }
}

void decode(unsigned char* image, int imageLen) {
    unsigned char byte = 0;
    int byteIdx = 0;

    for (int i = 0; i < imageLen; i += 3) {
        if (byteIdx < MAX_FILE_SIZE) {
            for (int j = 7; j >= 0; j--) {
                if (getBit(image[i], j)) {
                    setBit(&byte, (7 - byteIdx % 8), 1);
                } else {
                    setBit(&byte, (7 - byteIdx % 8), 0);
                }

                byteIdx++;

                if (byteIdx % 8 == 0) {
                    printf("%c", byte);
                    byte = 0;
                }
            }
        } else {
            break;
        }
    }
}

int main() {
    FILE * dataFile, * imageFile;
    unsigned char data[MAX_FILE_SIZE], image[MAX_FILE_SIZE];

    dataFile = fopen("data.txt", "rb");
    imageFile = fopen("image.bmp", "rb+");

    if (dataFile == NULL || imageFile == NULL) {
        printf("Error opening file");
        exit(1);
    }

    fseek(dataFile, 0, SEEK_END);
    int dataLen = ftell(dataFile);
    rewind(dataFile);

    fread(data, 1, dataLen, dataFile);
    fread(image, 1, MAX_FILE_SIZE, imageFile);

    encode(data, image, dataLen, MAX_FILE_SIZE);

    fseek(imageFile, 0, SEEK_SET);
    fwrite(image, 1, MAX_FILE_SIZE, imageFile);

    rewind(imageFile);
    fread(image, 1, MAX_FILE_SIZE, imageFile);

    printf("Decoded data:\n");
    decode(image, MAX_FILE_SIZE);

    fclose(dataFile);
    fclose(imageFile);

    return 0;
}