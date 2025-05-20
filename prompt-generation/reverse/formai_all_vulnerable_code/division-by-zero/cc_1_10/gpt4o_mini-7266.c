//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256

// Function to encrypt or decrypt data
void xor_encrypt_decrypt(FILE *inputFile, FILE *outputFile, const char *key) {
    char buffer;
    size_t keyLength = strlen(key);
    size_t i = 0;

    // Process each byte of the input file
    while ((buffer = fgetc(inputFile)) != EOF) {
        // XOR the byte with the corresponding key character
        buffer ^= key[i % keyLength];
        fputc(buffer, outputFile);
        i++;
    }
}

// Function to get key input from the user
void get_key(char *key) {
    printf("Enter the encryption key (max %d characters): ", MAX_KEY_LENGTH - 1);
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove the newline character
}

// Function to encrypt a file
void encrypt_file(const char *inputFileName, const char *outputFileName, const char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file for encryption");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file for encryption");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    xor_encrypt_decrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("File '%s' encrypted successfully to '%s'.\n", inputFileName, outputFileName);
}

// Function to decrypt a file
void decrypt_file(const char *inputFileName, const char *outputFileName, const char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file for decryption");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file for decryption");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    xor_encrypt_decrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("File '%s' decrypted successfully to '%s'.\n", inputFileName, outputFileName);
}

// Function to display menu options
void display_menu() {
    printf("\nSimple File Encryptor/Decryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFileName[256];
    char outputFileName[256];
    char key[MAX_KEY_LENGTH];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the input file name to encrypt: ");
                fgets(inputFileName, sizeof(inputFileName), stdin);
                inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove newline

                printf("Enter the output file name for encryption: ");
                fgets(outputFileName, sizeof(outputFileName), stdin);
                outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove newline

                get_key(key);
                encrypt_file(inputFileName, outputFileName, key);
                break;

            case 2:
                printf("Enter the input file name to decrypt: ");
                fgets(inputFileName, sizeof(inputFileName), stdin);
                inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove newline

                printf("Enter the output file name for decryption: ");
                fgets(outputFileName, sizeof(outputFileName), stdin);
                outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove newline

                get_key(key);
                decrypt_file(inputFileName, outputFileName, key);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}