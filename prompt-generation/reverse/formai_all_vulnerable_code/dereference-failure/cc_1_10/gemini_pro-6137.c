//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 0x12345678

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        return;
    }

    // Read the input file in 1-byte blocks
    unsigned char block[1];
    while (fread(block, 1, 1, input) == 1) {
        // Encrypt the block using XOR with the key
        block[0] ^= KEY;

        // Write the encrypted block to the output file
        fwrite(block, 1, 1, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        return;
    }

    // Read the input file in 1-byte blocks
    unsigned char block[1];
    while (fread(block, 1, 1, input) == 1) {
        // Decrypt the block using XOR with the key
        block[0] ^= KEY;

        // Write the decrypted block to the output file
        fwrite(block, 1, 1, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified the input and output files
    if (argc != 4) {
        fprintf(stderr, "Usage: %s encrypt/decrypt input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the mode (encrypt/decrypt)
    char *mode = argv[1];

    // Get the input and output file names
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return EXIT_FAILURE;
    }

    // Return success
    return EXIT_SUCCESS;
}