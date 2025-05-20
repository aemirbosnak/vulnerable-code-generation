//FormAI DATASET v1.0 Category: Image Steganography ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

int main(int argc, const char *argv[]) {
    char *filename = argv[1];
    char *message = argv[2];
    char *outFilename = argv[3];

    FILE *inFile = fopen(filename, "rb");
    FILE *outFile = fopen(outFilename, "wb");

    if (inFile == NULL) {
        printf("Error: Cannot open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    unsigned char *imageData = (unsigned char *) malloc(MAX_FILE_SIZE);
    int imageSize = fread(imageData, sizeof(unsigned char), MAX_FILE_SIZE, inFile);

    if (imageSize == 0) {
        printf("Error: File %s is empty.\n", filename);
        exit(EXIT_FAILURE);
    }

    int messageLength = strlen(message);
    if (messageLength > imageSize / 8) {
        printf("Error: Message is too large to fit inside the image %s.\n", filename);
        exit(EXIT_FAILURE);
    }

    unsigned char *outData = (unsigned char *) malloc(imageSize);

    int writtenBytes = 0;
    for (int i = 0; i < imageSize; i++) {
        if (writtenBytes < messageLength) {
            int bitIndex = i % 8;
            unsigned char bitToWrite = (message[writtenBytes] >> bitIndex) & 1;
            outData[i] = (imageData[i] & 0xFE) | bitToWrite;
            if (bitIndex == 7) {
                writtenBytes++;
            }
        } else {
            outData[i] = imageData[i];
        }
    }

    int outSize = fwrite(outData, sizeof(unsigned char), imageSize, outFile);

    if (outSize == 0) {
        printf("Error: Cannot write to file %s.\n", outFilename);
        exit(EXIT_FAILURE);
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}