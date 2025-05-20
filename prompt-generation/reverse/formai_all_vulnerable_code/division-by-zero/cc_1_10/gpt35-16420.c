//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BUFFER_LENGTH 1024

void encryptFile(char *fileName, char *key);
void decryptFile(char *fileName, char *key);
void xorEncrypt(char *buffer, int length, char *key);
void errorMessage(char *message);

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    char key[MAX_BUFFER_LENGTH];

    printf("Enter the file name to encrypt: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    printf("Enter the key to use for encryption: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    encryptFile(fileName, key);
    printf("File %s has been encrypted with key %s\n", fileName, key);

    printf("Enter the file name to decrypt: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = 0;

    printf("Enter the key to use for decryption: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;

    decryptFile(fileName, key);
    printf("File %s has been decrypted with key %s\n", fileName, key);

    return 0;
}

void encryptFile(char *fileName, char *key) {
    FILE *fp;
    fp = fopen(fileName, "r+");
    if(fp == NULL) {
        errorMessage("ERROR: Unable to open file...\n");
    }

    char buffer[MAX_BUFFER_LENGTH];

    while(fgets(buffer, MAX_BUFFER_LENGTH, fp)) {
        xorEncrypt(buffer, strlen(buffer), key);
        fseek(fp, -strlen(buffer), SEEK_CUR);
        fprintf(fp, "%s", buffer);
    }

    fclose(fp);
}

void decryptFile(char *fileName, char *key) {
    FILE *fp;
    fp = fopen(fileName, "r+");
    if(fp == NULL) {
        errorMessage("ERROR: Unable to open file...\n");
    }

    char buffer[MAX_BUFFER_LENGTH];

    while(fgets(buffer, MAX_BUFFER_LENGTH, fp)) {
        xorEncrypt(buffer, strlen(buffer), key);
        fseek(fp, -strlen(buffer), SEEK_CUR);
        fprintf(fp, "%s", buffer);
    }

    fclose(fp);
}

void xorEncrypt(char *buffer, int length, char *key) {
    int keyLength = strlen(key);
    for(int i=0; i<length; i++) {
        buffer[i] ^= key[i%keyLength];
    }
}

void errorMessage(char *message) {
    fprintf(stderr, "%s", message);
    exit(1);
}