//FormAI DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_KEY_LEN 32

void encryptFile(char *fileName, char *key);
void decryptFile(char *fileName, char *key);

int main() {
    char fileName[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];
    int choice;
    
    printf("Enter the name of the file to be encrypted/decrypted: ");
    scanf("%s", fileName);
    
    printf("Enter the encryption/decryption key (must be %d characters long): ", MAX_KEY_LEN - 1);
    scanf("%s", key);
    
    printf("\n\nChoose an option:\n1. Encrypt this file\n2. Decrypt this file\n\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            encryptFile(fileName, key);
            printf("Encryption Successful!");
            break;
        case 2:
            decryptFile(fileName, key);
            printf("Decryption Successful!");
            break;
        default:
            printf("Invalid Choice!");
    }
    
    return 0;
}

void encryptFile(char *fileName, char *key) {
    FILE *fp;
    fp = fopen(fileName, "rb+");
    
    if(fp == NULL) {
        printf("Error: File cannot be opened!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    char *buffer = calloc(fileSize, sizeof(char));
    
    if(buffer == NULL) {
        printf("Error: Memory cannot be allocated!\n");
        exit(1);
    }
    
    fseek(fp, 0, SEEK_SET);
    fread(buffer, sizeof(char), fileSize, fp);
    
    int key_length = strlen(key);
    int i, j;
    
    for(i = 0, j = 0; i < fileSize; i++, j++) {
        if(j == key_length) {
            j = 0;
        }
        
        buffer[i] = buffer[i] ^ key[j];
    }
    
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer, sizeof(char), fileSize, fp);
    fclose(fp);
    free(buffer);
}

void decryptFile(char *fileName, char *key) {
    encryptFile(fileName, key);
}