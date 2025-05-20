//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *filePath, const char *key) {
    FILE *file = fopen(filePath, "r+b");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    size_t keyLength = strlen(key);
    unsigned char buffer;
    size_t i = 0;

    while (fread(&buffer, sizeof(buffer), 1, file) == 1) {
        buffer ^= key[i % keyLength]; // XOR operation
        fseek(file, -1, SEEK_CUR);
        fwrite(&buffer, sizeof(buffer), 1, file);
        i++;
    }

    fclose(file);
    printf("File \"%s\" has been successfully encrypted/decrypted!\n", filePath);
}

void getUserInput(char *filePath, char *key) {
    printf("Enter the path of the file to encrypt/decrypt: ");
    fgets(filePath, 255, stdin);
    filePath[strcspn(filePath, "\n")] = 0; // Remove newline

    printf("Enter the encryption/decryption key: ");
    fgets(key, 255, stdin);
    key[strcspn(key, "\n")] = 0; // Remove newline
}

int main() {
    char filePath[256];
    char key[256];

    printf("Welcome to the File Encryptor Program!\n");
    printf("--------------------------------------------------\n");
    getUserInput(filePath, key);

    encryptDecryptFile(filePath, key);

    printf("--------------------------------------------------\n");
    printf("Thank you for using the File Encryptor! Bye!\n");

    return 0;
}