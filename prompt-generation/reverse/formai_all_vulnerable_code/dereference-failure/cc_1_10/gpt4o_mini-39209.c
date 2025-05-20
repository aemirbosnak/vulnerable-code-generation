//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt text using a simple Caesar cipher
void encrypt(const char* inputText, char* encryptedText, int shift) {
    for (int i = 0; inputText[i] != '\0'; i++) {
        char ch = inputText[i];

        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            encryptedText[i] = (ch - offset + shift) % 26 + offset;
        } else {
            encryptedText[i] = ch; // Non-alphabetical characters remain unchanged
        }
    }
}

// Function to decrypt text using a simple Caesar cipher
void decrypt(const char* encryptedText, char* decryptedText, int shift) {
    for (int i = 0; encryptedText[i] != '\0'; i++) {
        char ch = encryptedText[i];

        if (isalpha(ch)) {
            char offset = islower(ch) ? 'a' : 'A';
            decryptedText[i] = (ch - offset - shift + 26) % 26 + offset; // +26 to avoid negative values
        } else {
            decryptedText[i] = ch; // Non-alphabetical characters remain unchanged
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <shift> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* mode = argv[1];
    int shift = atoi(argv[2]);
    const char* filename = argv[3];

    // Read the content of the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *inputText = malloc(length + 1);
    if (!inputText) {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    fread(inputText, 1, length, file);
    inputText[length] = '\0'; // Null-terminate the string
    fclose(file);

    // Allocate memory for the output text
    char *outputText = malloc(length + 1);
    if (!outputText) {
        perror("Failed to allocate memory");
        free(inputText);
        return EXIT_FAILURE;
    }

    // Either encrypt or decrypt
    if (strcmp(mode, "encrypt") == 0) {
        encrypt(inputText, outputText, shift);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(inputText, outputText, shift);
    } else {
        fprintf(stderr, "Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        free(inputText);
        free(outputText);
        return EXIT_FAILURE;
    }

    // Write the output text to a file
    const char *outputFilename = strcmp(mode, "encrypt") == 0 ? "encrypted.txt" : "decrypted.txt";
    file = fopen(outputFilename, "w");
    if (!file) {
        perror("Failed to open output file");
        free(inputText);
        free(outputText);
        return EXIT_FAILURE;
    }

    fwrite(outputText, 1, strlen(outputText), file);
    fclose(file);

    printf("Operation successful! Output written to %s\n", outputFilename);

    // Clean up
    free(inputText);
    free(outputText);
    return EXIT_SUCCESS;
}