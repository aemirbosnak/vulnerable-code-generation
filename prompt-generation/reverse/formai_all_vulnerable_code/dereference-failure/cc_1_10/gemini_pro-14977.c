//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

// Encrypt a file using the XOR cipher
void encrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the length of the key
    int key_length = strlen(KEY);

    // Read the input file and encrypt it
    int c;
    int key_index = 0;
    while ((c = fgetc(input)) != EOF) {
        // XOR the character with the key
        c ^= KEY[key_index];

        // Increment the key index
        key_index = (key_index + 1) % key_length;

        // Write the encrypted character to the output file
        fputc(c, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Decrypt a file using the XOR cipher
void decrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the length of the key
    int key_length = strlen(KEY);

    // Read the input file and decrypt it
    int c;
    int key_index = 0;
    while ((c = fgetc(input)) != EOF) {
        // XOR the character with the key
        c ^= KEY[key_index];

        // Increment the key index
        key_index = (key_index + 1) % key_length;

        // Write the decrypted character to the output file
        fputc(c, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <encrypt/decrypt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the input file name, output file name, and operation type
    char *input_file = argv[1];
    char *output_file = argv[2];
    char *operation = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid operation: %s\n", operation);
        exit(EXIT_FAILURE);
    }

    // Success
    return EXIT_SUCCESS;
}