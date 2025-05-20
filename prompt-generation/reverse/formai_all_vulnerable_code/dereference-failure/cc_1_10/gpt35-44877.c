//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 50
#define MAX_BUFFER_SIZE 1024

void enryptFile(FILE *file, char *key) {
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes;

    FILE *encryptedFile = fopen("encryptedFile", "wb");

    if (encryptedFile == NULL) {
        printf("Error: Could not create encrypted file\n");
        return;
    }

    while ((bytes = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file)) != 0) {
        for (int i = 0; i < bytes; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, sizeof(char), bytes, encryptedFile);
    }

    fclose(file);
    fclose(encryptedFile);

    printf("File encrypted successfully\n");
}

void decryptFile(FILE *file, char *key) {
    unsigned char buffer[MAX_BUFFER_SIZE];
    size_t bytes;

    FILE *decryptedFile = fopen("decryptedFile", "wb");

    if (decryptedFile == NULL) {
        printf("Error: Could not create decrypted file\n");
        return;
    }

    while ((bytes = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, file)) != 0) {
        for (int i = 0; i < bytes; i++) {
            buffer[i] ^= key[i % strlen(key)];
        }
        fwrite(buffer, sizeof(char), bytes, decryptedFile);
    }

    fclose(file);
    fclose(decryptedFile);

    printf("File decrypted successfully\n");
}

int main() {
    char fileName[MAX_FILE_NAME_SIZE];
    char key[MAX_FILE_NAME_SIZE];

    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", fileName);
        return 1;
    }

    printf("Enter a key to encrypt/decrypt the file: ");
    scanf("%s", key);

    printf("Encrypting file...\n");
    enryptFile(file, key);

    printf("Decrypting file...\n");
    file = fopen("encryptedFile", "rb");

    if (file == NULL) {
        printf("Error: Could not open encrypted file\n");
        return 1;
    }

    decryptFile(file, key);

    return 0;
}