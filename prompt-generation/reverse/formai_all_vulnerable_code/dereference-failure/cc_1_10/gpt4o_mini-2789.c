//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(char *input, char *output, char *key) {
    int keyLength = strlen(key);
    int i = 0, j = 0;
    char ch;

    FILE *inputFile = fopen(input, "rb");
    FILE *outputFile = fopen(output, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key[j], outputFile);
        j = (j + 1) % keyLength;
    }

    fclose(inputFile);
    fclose(outputFile);
}

void showUsage(char *programName) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        showUsage(argv[0]);
        return EXIT_FAILURE;
    }
    
    char *action = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    char *key = argv[4];

    if (strcmp(action, "encrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File encrypted successfully: %s -> %s\n", inputFile, outputFile);
    } else if (strcmp(action, "decrypt") == 0) {
        encryptDecrypt(inputFile, outputFile, key);
        printf("File decrypted successfully: %s -> %s\n", inputFile, outputFile);
    } else {
        showUsage(argv[0]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}