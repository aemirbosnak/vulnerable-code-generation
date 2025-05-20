//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void encryptDecrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    int keyLength = strlen(key);
    char buffer[MAX_BUFFER];
    int i = 0;
    int c;

    while ((c = fgetc(inputFile)) != EOF) {
        buffer[i++] = c ^ key[i % keyLength]; // XOR encryption/decryption
        if (i == MAX_BUFFER) {
            fwrite(buffer, sizeof(char), i, outputFile);
            i = 0; // Reset buffer index
        }
    }
    if (i > 0) {
        fwrite(buffer, sizeof(char), i, outputFile); // Write remaining bytes
    }
}

void encryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    encryptDecrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    encryptFile(inputFileName, outputFileName, key); // Encryption and decryption are the same with XOR
}

int main() {
    char choice;
    char inputFileName[256], outputFileName[256], key[256];

    printf("File Encryptor/Decryptor\n");
    printf("=========================\n");
    
    printf("Enter the file name to encrypt/decrypt: ");
    scanf("%255s", inputFileName);
    
    printf("Enter the output file name: ");
    scanf("%255s", outputFileName);
    
    printf("Enter the key (password): ");
    scanf("%255s", key);

    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1/2): ");
    while ((choice = getchar()) != '\n' && choice != EOF); // Clear input buffer
    choice = getchar();

    switch (choice) {
        case '1':
            encryptFile(inputFileName, outputFileName, key);
            printf("File encrypted successfully!\n");
            break;
        case '2':
            decryptFile(inputFileName, outputFileName, key);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid choice! Please select 1 or 2.\n");
    }

    return 0;
}