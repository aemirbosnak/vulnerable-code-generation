//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(const char *input, const char *output, int shift) {
    FILE *inFile = fopen(input, "r");
    FILE *outFile = fopen(output, "w");
    if (inFile == NULL || outFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        }
        fputc(ch, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

// Function to decrypt the text using Caesar Cipher
void decrypt(const char *input, const char *output, int shift) {
    FILE *inFile = fopen(input, "r");
    FILE *outFile = fopen(output, "w");
    if (inFile == NULL || outFile == NULL) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift + 26 - 'A') % 26 + 'A'; // Adding 26 to avoid negatives
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift + 26 - 'a') % 26 + 'a'; // Adding 26 to avoid negatives
        }
        fputc(ch, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

// Function to display usage information
void displayUsage() {
    printf("Usage: cipher <encrypt/decrypt> <input_file> <output_file> <shift>\n");
    printf("Example: cipher encrypt input.txt output.txt 3\n");
    printf("Example: cipher decrypt output.txt decrypted.txt 3\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *inputFile = argv[2];
    char *outputFile = argv[3];
    int shift = atoi(argv[4]);

    // Handle different modes
    if (strcmp(mode, "encrypt") == 0) {
        encrypt(inputFile, outputFile, shift);
        printf("File encrypted successfully.\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(inputFile, outputFile, shift);
        printf("File decrypted successfully.\n");
    } else {
        displayUsage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}