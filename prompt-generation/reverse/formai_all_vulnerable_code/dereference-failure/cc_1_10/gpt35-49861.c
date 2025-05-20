//FormAI DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 32
#define MAX_BUFF_LENGTH 1024

int main(int argc, char *argv[]) {
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char buffer[MAX_BUFF_LENGTH];
    FILE *input, *output;
    int i, keyLen, len, readLen;

    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }

    // Copy input arguments to local variables
    strncpy(inputFilename, argv[1], MAX_FILENAME_LENGTH - 1);
    strncpy(outputFilename, argv[2], MAX_FILENAME_LENGTH - 1);
    strncpy(key, argv[3], MAX_KEY_LENGTH - 1);
    keyLen = strlen(key);

    // Open input and output files
    input = fopen(inputFilename, "rb");
    if (input == NULL) {
        printf("Error: could not open input file %s\n", inputFilename);
        return 1;
    }
    output = fopen(outputFilename, "wb");
    if (output == NULL) {
        printf("Error: could not open output file %s\n", outputFilename);
        fclose(input);
        return 1;
    }

    // Read and encrypt input file in chunks
    while ((readLen = fread(buffer, 1, MAX_BUFF_LENGTH, input)) > 0) {
        len = readLen;
        for (i = 0; i < len; i++) {
            buffer[i] = buffer[i] ^ key[i % keyLen];
        }
        fwrite(buffer, 1, len, output);
    }

    // Close input and output files
    fclose(input);
    fclose(output);

    printf("File encryption completed.\n");
    return 0;
}