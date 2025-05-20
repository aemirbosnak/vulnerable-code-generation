//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

// Function prototypes
void encrypt(const char *input, char *output, int key);
void decrypt(const char *input, char *output, int key);
void printUsage(const char *programName);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    char *inputText = argv[1];
    char *outputText = argv[2];
    int key = atoi(argv[3]);

    // Allocate memory for encrypted/decrypted text
    char *processedText = (char *)malloc(MAX_TEXT_LENGTH);
    if (processedText == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Encrypt the input text
    encrypt(inputText, processedText, key);
    printf("Encrypted text: %s\n", processedText);

    // Decrypt the text back to verify
    char *decryptedText = (char *)malloc(MAX_TEXT_LENGTH);
    if (decryptedText == NULL) {
        perror("Failed to allocate memory for decrypted text");
        free(processedText);
        return EXIT_FAILURE;
    }

    decrypt(processedText, decryptedText, key);
    printf("Decrypted text: %s\n", decryptedText);

    // Free allocated memory
    free(processedText);
    free(decryptedText);
    
    return EXIT_SUCCESS;
}

void encrypt(const char *input, char *output, int key) {
    int i = 0;
    while (input[i] != '\0' && i < MAX_TEXT_LENGTH) {
        // Encrypt using modular arithmetic
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base + key) % 26 + base;
        } else {
            output[i] = input[i];  // Non-alphabet characters remain unchanged
        }
        i++;
    }
    output[i] = '\0'; // Null-terminate the output string
}

void decrypt(const char *input, char *output, int key) {
    int i = 0;
    while (input[i] != '\0' && i < MAX_TEXT_LENGTH) {
        // Decrypt using modular arithmetic
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base - key + 26) % 26 + base; // Use +26 to avoid negative
        } else {
            output[i] = input[i];  // Non-alphabet characters remain unchanged
        }
        i++;
    }
    output[i] = '\0'; // Null-terminate the output string
}

void printUsage(const char *programName) {
    printf("Usage: %s <input_text> <output_text> <key>\n", programName);
    printf("Example: %s \"Hello World!\" encrypted.txt 3\n", programName);
}