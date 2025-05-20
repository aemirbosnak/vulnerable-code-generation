//FormAI DATASET v1.0 Category: File Encyptor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void encryptFile(char *fileName, char *key);
void decryptFile(char *fileName, char *key);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [option] [file_name] [key]\n", argv[0]);
        printf("Option 1: Encrypt a file\nOption 2: Decrypt a file\n");
        return 1;
    }
    if (strcmp(argv[1], "1") == 0) {
        encryptFile(argv[2], argv[3]);
        printf("File %s encrypted successfully!\n", argv[2]);
    } else if (strcmp(argv[1], "2") == 0) {
        decryptFile(argv[2], argv[3]);
        printf("File %s decrypted successfully!\n", argv[2]);
    } else {
        printf("Invalid option %s\n", argv[1]);
        return 1;
    }
    return 0;
}

void encryptFile(char *fileName, char *key) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }
    char buffer[MAX_BUFFER_SIZE];
    char newFileName[MAX_BUFFER_SIZE];
    strcpy(newFileName, fileName);
    strcat(newFileName, ".enc");
    FILE *newFile = fopen(newFileName, "w");
    if (newFile == NULL) {
        printf("Error creating file %s\n", newFileName);
        return;
    }
    int keyLength = strlen(key);
    int i = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        int bufferLength = strlen(buffer);
        for (int j = 0; j < bufferLength; j++) {
            buffer[j] = buffer[j] + key[i] + j;
            i = (i + 1) % keyLength;
        }
        fputs(buffer, newFile);
    }
    fclose(file);
    fclose(newFile);
}

void decryptFile(char *fileName, char *key) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }
    char buffer[MAX_BUFFER_SIZE];
    char newFileName[MAX_BUFFER_SIZE];
    strcpy(newFileName, fileName);
    int len = strlen(newFileName);
    if (strcmp(newFileName + len - 4, ".enc") == 0) {
        newFileName[len - 4] = '\0';
    }
    FILE *newFile = fopen(newFileName, "w");
    if (newFile == NULL) {
        printf("Error creating file %s\n", newFileName);
        return;
    }
    int keyLength = strlen(key);
    int i = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        int bufferLength = strlen(buffer);
        for (int j = 0; j < bufferLength; j++) {
            buffer[j] = buffer[j] - key[i] - j;
            i = (i + 1) % keyLength;
        }
        fputs(buffer, newFile);
    }
    fclose(file);
    fclose(newFile);
}