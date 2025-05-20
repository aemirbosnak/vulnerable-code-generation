//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BITS_PER_BYTE 8
#define MAX_FILENAME_LENGTH 100

void printHeader() {
    printf("*******************************************\n");
    printf("* C Digital Watermarking Example Program  *\n");
    printf("*******************************************\n\n");
}

void printUsage() {
    printf("Usage: ./watermark <input_file> <watermark> <output_file>\n");
}

int main(int argc, char** argv) {
    printHeader();

    // Check for correct usage
    if (argc != 4) {
        printUsage();
        return -1;
    }

    // Get input file name
    char* inputFileName = argv[1];
    printf("Input File: %s\n", inputFileName);

    // Get watermark string
    char* watermark = argv[2];
    printf("Watermark: %s\n", watermark);

    // Get output file name
    char* outputFileName = argv[3];
    printf("Output File: %s\n\n", outputFileName);

    // Open input file
    FILE* inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open file %s\n", inputFileName);
        return -1;
    }

    // Get size of input file
    fseek(inputFile, 0, SEEK_END);
    long inputFileLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    printf("Input File Size: %ld bytes\n", inputFileLength);

    // Calculate size of watermark in bits
    int watermarkLength = strlen(watermark);
    int watermarkBitLength = watermarkLength * BITS_PER_BYTE;
    printf("Watermark Size: %d bits\n", watermarkBitLength);

    // Calculate new file size with watermark
    long outputFileLength = inputFileLength + watermarkBitLength;
    printf("Output File Size: %ld bytes\n", outputFileLength);

    // Allocate memory for input file buffer
    char* inputFileBuffer = (char*)malloc(inputFileLength);
    fread(inputFileBuffer, 1, inputFileLength, inputFile);

    // Allocate memory for output file buffer
    char* outputFileBuffer = (char*)malloc(outputFileLength);
    memset(outputFileBuffer, 0, outputFileLength);

    // Copy input file contents to output file buffer
    memcpy(outputFileBuffer, inputFileBuffer, inputFileLength);

    // Insert watermark into output file buffer
    for (int i = 0; i < watermarkLength; i++) {
        unsigned char watermarkChar = (unsigned char)watermark[i];

        for (int j = 0; j < BITS_PER_BYTE; j++) {
            int watermarkBit = (watermarkChar >> j) & 1;
            int watermarkBitIndex = (i * BITS_PER_BYTE) + j;
            int watermarkByteIndex = watermarkBitIndex / BITS_PER_BYTE;
            int watermarkByteBitIndex = watermarkBitIndex % BITS_PER_BYTE;

            char* watermarkByte = &outputFileBuffer[inputFileLength + watermarkByteIndex];
            *watermarkByte = (*watermarkByte & ~(1 << watermarkByteBitIndex)) | (watermarkBit << watermarkByteBitIndex);
        }
    }

    // Open output file
    FILE* outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not create file %s\n", outputFileName);
        return -1;
    }

    // Write output file buffer to output file
    fwrite(outputFileBuffer, 1, outputFileLength, outputFile);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    // Free memory
    free(inputFileBuffer);
    free(outputFileBuffer);

    printf("\nWatermarking complete! Output file created: %s\n", outputFileName);

    return 0;
}