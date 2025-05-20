//FormAI DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt data
void encryptData(char* data, int len) {
    for(int i = 0; i < len; i++) {
        data[i] = data[i] + 5;
    }
}

// Function to decrypt data
void decryptData(char* data, int len) {
    for(int i = 0; i < len; i++) {
        data[i] = data[i] - 5;
    }
}

// Structure to represent file
typedef struct {
    char* fileName;
    char* fileData;
    int fileSize;
} File;

// Function to create a new file
File* createFile(char* name) {
    File* newFile = (File*) malloc(sizeof(File));
    newFile->fileName = (char*) malloc(strlen(name) + 1);
    strcpy(newFile->fileName, name);
    newFile->fileData = NULL;
    newFile->fileSize = 0;
    return newFile;
}

// Function to read data from a file
char* readFileData(char* fileName, int* size) {
    FILE* fp = fopen(fileName, "rb");
    if(fp == NULL) {
        printf("Unable to open file: %s\n", fileName);
        return NULL;
    }
    fseek(fp, 0L, SEEK_END);
    *size = ftell(fp);
    char* data = (char*) malloc(*size);
    fseek(fp, 0L, SEEK_SET);
    fread(data, *size, 1, fp);
    fclose(fp);
    return data;
}

// Function to write data to a file
void writeToFile(char* fileName, char* data, int size) {
    FILE* fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("Unable to open file: %s\n", fileName);
        return;
    }
    fwrite(data, size, 1, fp);
    fclose(fp);
}

// Function to backup a file
void backupFile(char* fileName) {
    // Read the data from the file
    int size;
    char* data = readFileData(fileName, &size);
    if(data == NULL) {
        return;
    }

    // Encrypt the data
    encryptData(data, size);

    // Create a new file and write the encrypted data to it
    char* backupName = (char*) malloc(strlen(fileName) + 5);
    sprintf(backupName, "%s.bak", fileName);
    writeToFile(backupName, data, size);
    free(backupName);
    free(data);

    // Print a success message
    printf("File backed up: %s\n", fileName);
}

// Function to restore a file from backup
void restoreFile(char* fileName) {
    // Read the data from the backup file
    char* backupName = (char*) malloc(strlen(fileName) + 5);
    sprintf(backupName, "%s.bak", fileName);
    int size;
    char* data = readFileData(backupName, &size);
    if(data == NULL) {
        free(backupName);
        return;
    }

    // Decrypt the data
    decryptData(data, size);

    // Write the decrypted data to the original file
    writeToFile(fileName, data, size);
    free(backupName);
    free(data);

    // Print a success message
    printf("File restored: %s from backup\n", fileName);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return -1;
    }

    char* fileName = argv[1];
    File* file = createFile(fileName);

    backupFile(fileName);
    restoreFile(fileName);

    return 0;
}