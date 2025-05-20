//FormAI DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_KEY_LENGTH 50

void encryptFile(char* fileName, char* key) {
    // Open file
    FILE* filePtr = fopen(fileName, "rb");
    if (!filePtr) {
        printf("Could not open file %s\n", fileName);
        return;
    }

    // Determine file size
    fseek(filePtr, 0, SEEK_END);
    int fileSize = ftell(filePtr);
    fseek(filePtr, 0, SEEK_SET);

    // Allocate memory for file content
    char* fileContent = (char*) malloc(fileSize * sizeof(char));
    if (!fileContent) {
        printf("Could not allocate memory for file content\n");
        return;
    }

    // Read file content
    fread(fileContent, fileSize, sizeof(char), filePtr);

    // Encrypt file
    int keyLength = strlen(key);
    for (int i = 0; i < fileSize; i++) {
        fileContent[i] ^= key[i % keyLength];
    }

    // Write encrypted content back to file
    fclose(filePtr);
    filePtr = fopen(fileName, "wb");
    if (!filePtr) {
        printf("Could not open file %s\n", fileName);
        return;
    }
    fwrite(fileContent, fileSize, sizeof(char), filePtr);

    // Cleanup
    free(fileContent);
    fclose(filePtr);

    printf("File %s encrypted successfully.\n", fileName);
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH], key[MAX_KEY_LENGTH];

    // Get file name from user
    printf("Enter name of file to encrypt: ");
    scanf("%s", fileName);

    // Get encryption key from user
    printf("Enter encryption key (max 50 characters): ");
    scanf("%s", key);

    encryptFile(fileName, key);

    return 0;
}