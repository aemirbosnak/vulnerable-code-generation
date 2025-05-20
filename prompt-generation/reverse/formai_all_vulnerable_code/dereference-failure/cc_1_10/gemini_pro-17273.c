//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int numBytes = 0;
    fread(&numBytes, sizeof(int), 1, inputFile);

    char *inputBuffer = malloc(numBytes);
    if (inputBuffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    fread(inputBuffer, sizeof(char), numBytes, inputFile);

    int outputSize = numBytes * 8 + 1;
    char *outputBuffer = malloc(outputSize);
    if (outputBuffer == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    int outputIndex = 0;
    for (int i = 0; i < numBytes; i++) {
        char byte = inputBuffer[i];
        for (int j = 7; j >= 0; j--) {
            outputBuffer[outputIndex++] = (byte & (1 << j)) ? '1' : '0';
        }
    }

    outputBuffer[outputIndex] = '\0';

    fwrite(outputBuffer, sizeof(char), outputIndex, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    free(inputBuffer);
    free(outputBuffer);

    return EXIT_SUCCESS;
}