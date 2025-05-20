//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void encryptFile(char *fileName, char *key);
void decryptFile(char *fileName, char *key);

int main() {
    char fileName[MAX_FILENAME_LENGTH];
    char key[MAX_BUFFER_SIZE];
    char option;

    printf("Enter file name: ");
    fgets(fileName, MAX_FILENAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    printf("Do you want to encrypt (E) or decrypt (D) the file '%s'? ", fileName);
    scanf("%c", &option);

    printf("Enter encryption / decryption key: ");
    getchar(); // to clear the newline character
    fgets(key, MAX_BUFFER_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    switch (option) {
        case 'E':
            encryptFile(fileName, key);
            break;
        case 'D':
            decryptFile(fileName, key);
            break;
        default:
            printf("Invalid option. Program terminated.\n");
            exit(1);
    }

    return 0;
}

void encryptFile(char *fileName, char *key) {
    FILE *inputFile, *outputFile;
    char buffer[MAX_BUFFER_SIZE];
    int keyLength = strlen(key);
    int keyIndex = 0;

    inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Cannot open file '%s' for reading.\n", fileName);
        exit(1);
    }

    char outputFileName[MAX_FILENAME_LENGTH];
    snprintf(outputFileName, MAX_FILENAME_LENGTH, "%s.enc", fileName);

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Cannot open file '%s' for writing.\n", outputFileName);
        exit(1);
    }

    while (1) {
        size_t bytesRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, inputFile);
        if (bytesRead == 0) {
            break;
        }

        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ key[keyIndex++ % keyLength];
        }

        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File '%s' encrypted successfully.\n", fileName);
}

void decryptFile(char *fileName, char *key) {
    FILE *inputFile, *outputFile;
    char buffer[MAX_BUFFER_SIZE];
    int keyLength = strlen(key);
    int keyIndex = 0;

    inputFile = fopen(fileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Cannot open file '%s' for reading.\n", fileName);
        exit(1);
    }

    char outputFileName[MAX_FILENAME_LENGTH];
    snprintf(outputFileName, MAX_FILENAME_LENGTH, "%s.dec", fileName);

    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Cannot open file '%s' for writing.\n", outputFileName);
        exit(1);
    }

    while (1) {
        size_t bytesRead = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, inputFile);
        if (bytesRead == 0) {
            break;
        }

        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] = buffer[i] ^ key[keyIndex++ % keyLength];
        }

        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File '%s' decrypted successfully.\n", fileName);
}