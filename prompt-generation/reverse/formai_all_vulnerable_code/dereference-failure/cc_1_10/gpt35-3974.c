//FormAI DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_READ_BUFFER_LENGTH 1024

void encryptFile(const char* fileName, const char* key) {
    FILE* filePtr = fopen(fileName, "rb");
    if (filePtr == NULL) {
        printf("Failed to open file %s\n", fileName);
        return;
    }

    unsigned char readBuffer[MAX_READ_BUFFER_LENGTH];
    size_t bytesRead;
    size_t keyLength = strlen(key);
    size_t i = 0;

    FILE* encryptedFilePtr = fopen(strcat(fileName, ".encrypted"), "wb");
    if (encryptedFilePtr == NULL) {
        printf("Failed to create encrypted file\n");
        fclose(filePtr);
        return;
    }

    while ((bytesRead = fread(readBuffer, sizeof(unsigned char), MAX_READ_BUFFER_LENGTH, filePtr)) > 0) {
        for (i = 0; i < bytesRead; ++i) {
            readBuffer[i] ^= key[i % keyLength];
        }

        fwrite(readBuffer, sizeof(unsigned char), bytesRead, encryptedFilePtr);
    }

    fclose(filePtr);
    fclose(encryptedFilePtr);
    printf("File %s encrypted successfully with key %s\n", fileName, key);
}

void decryptFile(const char* fileName, const char* key) {
    FILE* filePtr = fopen(fileName, "rb");
    if (filePtr == NULL) {
        printf("Failed to open file %s\n", fileName);
        return;
    }

    unsigned char readBuffer[MAX_READ_BUFFER_LENGTH];
    size_t bytesRead;
    size_t keyLength = strlen(key);
    size_t i = 0;

    char decryptedFileName[MAX_FILE_NAME_LENGTH];
    strncpy(decryptedFileName, fileName, strlen(fileName) - strlen(".encrypted"));

    FILE* decryptedFilePtr = fopen(decryptedFileName, "wb");
    if (decryptedFilePtr == NULL) {
        printf("Failed to create decrypted file\n");
        fclose(filePtr);
        return;
    }

    while ((bytesRead = fread(readBuffer, sizeof(unsigned char), MAX_READ_BUFFER_LENGTH, filePtr)) > 0) {
        for (i = 0; i < bytesRead; ++i) {
            readBuffer[i] ^= key[i % keyLength];
        }

        fwrite(readBuffer, sizeof(unsigned char), bytesRead, decryptedFilePtr);
    }

    fclose(filePtr);
    fclose(decryptedFilePtr);
    printf("File %s decrypted successfully with key %s\n", fileName, key);
}

int main(int argc, char* argv[]) {
    int option = 0;
    char fileName[MAX_FILE_NAME_LENGTH];
    char key[MAX_FILE_NAME_LENGTH];

    if (argc < 2) {
        printf("Usage: %s <option> <file-name> <key>\n", argv[0]);
        printf("\nOptions:\n");
        printf("1. Encrypt file\n");
        printf("2. Decrypt file\n");
        return 0;
    }

    option = atoi(argv[1]);
    if (argc < 3) {
        printf("Please provide file name\n");
        return 0;
    }

    strncpy(fileName, argv[2], MAX_FILE_NAME_LENGTH);

    if (argc < 4) {
        printf("Please provide key\n");
        return 0;
    }

    strncpy(key, argv[3], MAX_FILE_NAME_LENGTH);

    switch (option) {
        case 1:
            encryptFile(fileName, key);
            break;
        case 2:
            decryptFile(fileName, key);
            break;
        default:
            printf("Invalid option %d\n", option);
    }

    return 0;
}