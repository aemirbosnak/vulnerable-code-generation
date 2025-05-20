//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key.
#define KEY 7

// Function to encrypt a character.
char encrypt(char ch) {
    return ch + KEY;
}

// Function to decrypt a character.
char decrypt(char ch) {
    return ch - KEY;
}

// Function to encrypt a file.
void encryptFile(char *fileName) {
    // Open the file in read mode.
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening the input file.");
        return;
    }

    // Open the encrypted file in write mode.
    FILE *outputFile = fopen("encrypted.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening the output file.");
        return;
    }

    // Read a character from the input file.
    char ch = fgetc(inputFile);

    // Continue reading until the end of the file is reached.
    while (ch != EOF) {
        // Encrypt the character.
        ch = encrypt(ch);

        // Write the encrypted character to the output file.
        fputc(ch, outputFile);

        // Read the next character from the input file.
        ch = fgetc(inputFile);
    }

    // Close the input and output files.
    fclose(inputFile);
    fclose(outputFile);
}

// Function to decrypt a file.
void decryptFile(char *fileName) {
    // Open the encrypted file in read mode.
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening the input file.");
        return;
    }

    // Open the decrypted file in write mode.
    FILE *outputFile = fopen("decrypted.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening the output file.");
        return;
    }

    // Read a character from the encrypted file.
    char ch = fgetc(inputFile);

    // Continue reading until the end of the file is reached.
    while (ch != EOF) {
        // Decrypt the character.
        ch = decrypt(ch);

        // Write the decrypted character to the output file.
        fputc(ch, outputFile);

        // Read the next character from the encrypted file.
        ch = fgetc(inputFile);
    }

    // Close the input and output files.
    fclose(inputFile);
    fclose(outputFile);
}

// Main function.
int main(int argc, char **argv) {
    // Check if the user specified the file name to be encrypted/decrypted.
    if (argc != 2) {
        printf("Usage: %s <file name>\n", argv[0]);
        return 1;
    }

    // Check if the user wants to encrypt or decrypt the file.
    printf("Do you want to encrypt or decrypt the file? (e/d)\n");
    char option = getchar();

    // Encrypt the file.
    if (option == 'e') {
        encryptFile(argv[1]);
    }
    // Decrypt the file.
    else if (option == 'd') {
        decryptFile(argv[1]);
    }
    // Invalid option.
    else {
        printf("Invalid option. Please enter 'e' to encrypt or 'd' to decrypt.\n");
        return 1;
    }

    return 0;
}