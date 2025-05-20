//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt(char* message, int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        message[i] = toupper(message[i]) ^ KEY[i % strlen(KEY)];
    }
}

void decrypt(char* message, int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        message[i] = toupper(message[i]) ^ KEY[i % strlen(KEY)];
    }
}

int main(int argc, char* argv[]) {
    FILE* inputFile;
    char* inputBuffer;
    int inputSize;
    char* outputBuffer;
    int outputSize;

    if (argc!= 3) {
        printf("Usage: %s [encrypt/decrypt] [input_file]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        inputFile = fopen(argv[2], "rb");
        if (inputFile == NULL) {
            printf("Error: Could not open input file.\n");
            exit(1);
        }

        fseek(inputFile, 0, SEEK_END);
        inputSize = ftell(inputFile);
        rewind(inputFile);

        inputBuffer = malloc(inputSize + 1);
        fread(inputBuffer, inputSize, 1, inputFile);
        fclose(inputFile);

        encrypt(inputBuffer, inputSize);

        outputBuffer = malloc(inputSize + 1);
        memcpy(outputBuffer, inputBuffer, inputSize);
        outputBuffer[inputSize] = '\0';

        outputSize = strlen(outputBuffer);

        printf("Encrypted message:\n%s\n", outputBuffer);
        printf("Encrypted message size: %d bytes\n", outputSize);

        free(inputBuffer);
        free(outputBuffer);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        inputFile = fopen(argv[2], "rb");
        if (inputFile == NULL) {
            printf("Error: Could not open input file.\n");
            exit(1);
        }

        fseek(inputFile, 0, SEEK_END);
        inputSize = ftell(inputFile);
        rewind(inputFile);

        inputBuffer = malloc(inputSize + 1);
        fread(inputBuffer, inputSize, 1, inputFile);
        fclose(inputFile);

        decrypt(inputBuffer, inputSize);

        outputBuffer = malloc(inputSize + 1);
        memcpy(outputBuffer, inputBuffer, inputSize);
        outputBuffer[inputSize] = '\0';

        outputSize = strlen(outputBuffer);

        printf("Decrypted message:\n%s\n", outputBuffer);
        printf("Decrypted message size: %d bytes\n", outputSize);

        free(inputBuffer);
        free(outputBuffer);
    } else {
        printf("Invalid operation.\n");
        exit(1);
    }

    return 0;
}