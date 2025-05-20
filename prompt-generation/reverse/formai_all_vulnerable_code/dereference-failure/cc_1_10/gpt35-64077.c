//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256 

void encrypt(char *filename, char *keyfile, char *outputFilename) {
    FILE *file = fopen(filename, "rb");
    FILE *key = fopen(keyfile, "rb");
    FILE *output = fopen(outputFilename, "wb");

    char buffer[BUFFER_SIZE];
    char keyBuffer[BUFFER_SIZE];

    int bytesRead = 0;
    int keyBytesRead = 0;
    int keySize = 0;

    if (!file || !key || !output) {
        printf("Error opening files!\n");
        exit(1);
    }

    fseek(key, 0, SEEK_END);
    keySize = ftell(key);
    rewind(key);

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        keyBytesRead = fread(keyBuffer, 1, BUFFER_SIZE, key);

        for (int i = 0; i < bytesRead; i++) {
            buffer[i] ^= keyBuffer[i % keyBytesRead];
        }

        fwrite(buffer, 1, bytesRead, output);
    }

    fclose(file);
    fclose(key);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s input_file key_file output_file\n", argv[0]);
        exit(1);
    }

    char *inputFilename = argv[1];
    char *keyFilename = argv[2];
    char *outputFilename = argv[3];

    encrypt(inputFilename, keyFilename, outputFilename);

    return 0;
}