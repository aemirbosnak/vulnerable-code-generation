//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_FILENAME 256

void readHeader(unsigned char **input, unsigned int *width, unsigned int *height, unsigned int *channels) {
    unsigned int offset = 0;
    char header[4];
    memcpy(header, *input + offset, 3);
    header[3] = '\0';
    offset += 3;
    if (strcmp(header, "P6\n")) {
        printf("Wrong Header\n");
        return;
    }
    while(*(*input + offset) == '#') {
        while(*(*input + offset) != '\n') {
            offset ++;
        }
        offset ++;
    }
    sscanf((char *)*input + offset, "%d%d%d", width, height, channels);
    offset += (int)(log10(*width) + 1) + (int)(log10(*height) + 1) + (int)(log10(*channels) + 1) + 3;
    *input += offset;
}

void writeHeader(unsigned char **output, const unsigned int width, const unsigned int height, const unsigned int channels) {
    char header[50];
    sprintf(header, "P6\n%d %d\n%d\n", width, height, channels);
    unsigned int headerLen = strlen(header);
    memcpy(*output, header, headerLen);
    *output += headerLen;
}

unsigned int compress(unsigned char *input, unsigned char *output, const unsigned int width, const unsigned int height, const unsigned int channels) {
    unsigned int numPixels = width * height;
    unsigned char *currentPixel = input;
    unsigned int compressedSize = 0;
    for (unsigned int pixelIndex = 0; pixelIndex < numPixels; pixelIndex ++) {
        for (unsigned int channelIndex = 0; channelIndex < channels; channelIndex ++) {
            char binaryChar = 0;
            for (int i = 0; i < 8; i ++) {
                binaryChar |= (*currentPixel >> (8 - i - 1)) & 1<<i;
            }
            *output = binaryChar;
            output ++;
            compressedSize ++;
            currentPixel ++;
        }
    }
    return compressedSize;
}

void decompress(unsigned char *input, unsigned char *output, const unsigned int width, const unsigned int height, const unsigned int channels) {
    unsigned int numPixels = width * height;
    unsigned char *currentPixel = output;
    for (unsigned int pixelIndex = 0; pixelIndex < numPixels; pixelIndex ++) {
        for (unsigned int channelIndex = 0; channelIndex < channels; channelIndex ++) {
            char binaryChar = *input;
            for (int i = 0; i < 8; i ++) {
                *currentPixel |= (binaryChar >> (8 - i - 1)) & 1<<i;
            }
            input ++;
            currentPixel ++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage:\n%s <filename>\n", argv[0]);
        return -1;
    }
    char inputFilename[MAX_FILENAME];
    char outputFilename[MAX_FILENAME];
    sprintf(inputFilename, "%s", argv[1]);
    sprintf(outputFilename, "compressed_%s", argv[1]);
    FILE *inputFile = fopen(inputFilename, "rb");
    if (!inputFile) {
        printf("Failed to open input file: %s\n", inputFilename);
        return -1;
    }
    fseek(inputFile, 0, SEEK_END);
    unsigned int inputSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    unsigned char *input = malloc(inputSize);
    fread(input, sizeof(unsigned char), inputSize, inputFile);
    fclose(inputFile);
    unsigned int width = 0, height = 0, channels = 0;
    readHeader(&input, &width, &height, &channels);
    unsigned char *output = malloc(width * height * channels / 8);
    writeHeader(&output, width, height, channels);
    unsigned int compressedSize = compress(input, output, width, height, channels);
    FILE *outputFile = fopen(outputFilename, "wb");
    fwrite(output, sizeof(unsigned char), compressedSize, outputFile);
    fclose(outputFile);
    free(output);
    unsigned char *compressedData = malloc(compressedSize);
    FILE *compressedFile = fopen(outputFilename, "rb");
    fread(compressedData, sizeof(unsigned char), compressedSize, compressedFile);
    fclose(compressedFile);
    unsigned char *decompressedData = malloc(width * height * channels);
    decompress(compressedData, decompressedData, width, height, channels);
    char decompressedFilename[MAX_FILENAME];
    sprintf(decompressedFilename, "decompressed_%s", argv[1]);
    FILE *decompressedFile = fopen(decompressedFilename, "wb");
    fwrite(decompressedData, sizeof(unsigned char), width * height * channels, decompressedFile);
    fclose(decompressedFile);
    free(input);
    free(compressedData);
    free(decompressedData);
    return 0;
}