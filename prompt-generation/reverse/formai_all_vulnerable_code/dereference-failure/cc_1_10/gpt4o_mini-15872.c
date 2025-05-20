//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt the data
void encrypt(const char *inputFile, const char *outputFile, int key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read the input file and encrypt its content
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // Simple XOR encryption
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("File encrypted successfully: %s\n", outputFile);
}

// Function to decrypt the data
void decrypt(const char *inputFile, const char *outputFile, int key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Read the input file and decrypt its content
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // Simple XOR decryption
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("File decrypted successfully: %s\n", outputFile);
}

// Function to get a simple integer key from the user
int getEncryptionKey() {
    int key;
    printf("Enter a numeric key for encryption (0 - 255): ");
    scanf("%d", &key);
    while (key < 0 || key > 255) {
        printf("Invalid key. Please enter a number between 0 and 255: ");
        scanf("%d", &key);
    }
    return key;
}

// Main function to control the program flow
int main() {
    int choice;
    char inputFile[256];
    char outputFile[256];
    int key;

    printf("=== File Encryptor ===\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");

    while (1) {
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input file name to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter output file name for encrypted data: ");
                scanf("%s", outputFile);
                key = getEncryptionKey();
                encrypt(inputFile, outputFile, key);
                break;

            case 2:
                printf("Enter input file name to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter output file name for decrypted data: ");
                scanf("%s", outputFile);
                key = getEncryptionKey();
                decrypt(inputFile, outputFile, key);
                break;

            case 3:
                printf("Exiting program.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please choose again!\n");
        }
    }

    return 0;
}