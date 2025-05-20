//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char data;
    int count;
} EncodedData;

void compress(unsigned char *input, unsigned int inputLength, unsigned char *output) {
    EncodedData *encodedData = malloc(inputLength * sizeof(EncodedData));
    int index = 0;
    int currentByte = input[0];
    int currentCount = 1;

    for (int i = 0; i < inputLength; i++) {
        if (i < inputLength - 1 && input[i] == input[i + 1]) {
            currentCount++;
        } else {
            encodedData[index].data = currentByte;
            encodedData[index].count = currentCount;
            index++;
            currentByte = input[i];
            currentCount = 1;
        }
    }

    // Write encoded data to output buffer
    int encodedLength = index + 1;
    for (int i = 0; i < encodedLength; i++) {
        output[i] = encodedData[i].data;
        if (i < encodedLength - 1) {
            output[i] |= encodedData[i].count << 5;
        }
    }

    free(encodedData);
}

void decompress(unsigned char *input, unsigned int inputLength, unsigned char *output) {
    int index = 0;
    for (int i = 0; i < inputLength; i += 2) {
        output[i / 2] = input[i];
        int count = input[i] >> 5;
        for (int j = 0; j < count; j++) {
            output[i / 2 + j + 1] = input[i + 1 + j];
        }
    }
}

int main() {
    unsigned char input[] = {0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03};
    unsigned char outputBuffer[sizeof(input)];
    unsigned char decompressedBuffer[sizeof(input)];

    compress(input, sizeof(input), outputBuffer);
    printf("Compressed data: ");
    for (int i = 0; i < sizeof(outputBuffer); i++) {
        printf("%02X ", outputBuffer[i]);
    }
    printf("\n");

    decompress(outputBuffer, sizeof(outputBuffer), decompressedBuffer);
    printf("Decompressed data: ");
    for (int i = 0; i < sizeof(decompressedBuffer); i++) {
        printf("%02X ", decompressedBuffer[i]);
    }
    printf("\n");

    return 0;
}