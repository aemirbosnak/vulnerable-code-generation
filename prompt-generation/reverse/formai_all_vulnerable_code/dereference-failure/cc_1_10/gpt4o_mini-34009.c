//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024  // Define buffer size for file operations
#define SHIFT 3          // Define shift value for Caesar cipher

// Function prototypes
void encryptFile(const char *inputFileName, const char *outputFileName);
void decryptFile(const char *inputFileName, const char *outputFileName);
char shiftCharacter(char ch, int shift);

// Main function
int main() {
    char inputFileName[256];
    char outputFileName[256];
    
    // Themed introduction
    printf("Welcome to the Serene File Encryptor!\n");
    printf("This program will help you protect your text files with simple encryption.\n");

    // Input for the file to encrypt
    printf("Please enter the name of the file to encrypt: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove newline

    printf("Please enter the name for the encrypted output file: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove newline
    
    // Encrypt the file
    encryptFile(inputFileName, outputFileName);
    
    // Prepare to decrypt
    printf("Now, let us decrypt the file.\n");
    printf("Please enter the name of the file to decrypt: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove newline

    printf("Please enter the name for the decrypted output file: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove newline
    
    // Decrypt the file
    decryptFile(inputFileName, outputFileName);
    
    printf("Thank you for using the Serene File Encryptor! Have a peaceful day!\n");
    return 0;
}

// Function to encrypt a file
void encryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = shiftCharacter(buffer[i], SHIFT);
        }
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File '%s' has been successfully encrypted to '%s'.\n", inputFileName, outputFileName);
}

// Function to decrypt a file
void decryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = shiftCharacter(buffer[i], -SHIFT);
        }
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File '%s' has been successfully decrypted to '%s'.\n", inputFileName, outputFileName);
}

// Function to shift character by a given shift value
char shiftCharacter(char ch, int shift) {
    if (ch >= 'a' && ch <= 'z') {
        return (ch - 'a' + shift + 26) % 26 + 'a'; // Shift for lowercase
    }
    if (ch >= 'A' && ch <= 'Z') {
        return (ch - 'A' + shift + 26) % 26 + 'A'; // Shift for uppercase
    }
    return ch; // Non-alphabetic characters remain unchanged
}