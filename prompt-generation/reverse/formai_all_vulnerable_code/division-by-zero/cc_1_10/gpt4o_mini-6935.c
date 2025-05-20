//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

// Function to encrypt the content using XOR cipher
void encryptDecrypt(FILE *inputFile, FILE *outputFile, char *key) {
    char buffer[BUFFER_SIZE];
    size_t keyLen = strlen(key);
    int i;

    while (fread(buffer, 1, BUFFER_SIZE, inputFile) > 0) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] ^= key[i % keyLen]; // Simple XOR encryption
        }
        fwrite(buffer, 1, BUFFER_SIZE, outputFile);
    }
}

// A whimsical function to display the welcome message
void welcomeMessage() {
    printf("Welcome to the Curious C File Encryptor!\n");
    printf("Unleash the magic of XOR encryption on your files.\n\n");
}

// A function to get user input for filename and key
void getUserInput(char *inputFilename, char *outputFilename, char *key) {
    printf("Please enter the input filename: ");
    fgets(inputFilename, MAX_FILENAME, stdin);
    inputFilename[strcspn(inputFilename, "\n")] = '\0'; // Remove newline

    printf("Please enter the output filename: ");
    fgets(outputFilename, MAX_FILENAME, stdin);
    outputFilename[strcspn(outputFilename, "\n")] = '\0'; // Remove newline

    printf("Please enter a simple key (no spaces): ");
    fgets(key, MAX_FILENAME, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove newline
}

int main() {
    char inputFilename[MAX_FILENAME];
    char outputFilename[MAX_FILENAME];
    char key[MAX_FILENAME];

    welcomeMessage();
    getUserInput(inputFilename, outputFilename, key);

    FILE *inputFile = fopen(inputFilename, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(outputFilename, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    encryptDecrypt(inputFile, outputFile, key);

    printf("\nEncryption complete! The file '%s' has been created.\n",
           outputFilename);

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}