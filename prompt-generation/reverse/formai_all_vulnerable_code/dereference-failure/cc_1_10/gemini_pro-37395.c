//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// A simple encryption function
uint32_t encrypt(uint32_t x) {
    return (x << 13) | (x >> 19);
}

// A simple decryption function
uint32_t decrypt(uint32_t x) {
    return (x >> 13) | (x << 19);
}

// A function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file %s\n", input_file);
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file %s\n", output_file);
        exit(1);
    }

    // Read the input file in 4-byte chunks
    uint32_t buffer[4];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(uint32_t), 4, input)) > 0) {
        // Encrypt each 4-byte chunk
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = encrypt(buffer[i]);
        }

        // Write the encrypted chunk to the output file
        fwrite(buffer, sizeof(uint32_t), bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// A function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file %s\n", input_file);
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file %s\n", output_file);
        exit(1);
    }

    // Read the input file in 4-byte chunks
    uint32_t buffer[4];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(uint32_t), 4, input)) > 0) {
        // Decrypt each 4-byte chunk
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = decrypt(buffer[i]);
        }

        // Write the decrypted chunk to the output file
        fwrite(buffer, sizeof(uint32_t), bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <operation> <input_file> <output_file>\n", argv[0]);
        fprintf(stderr, "Operation can be either \"encrypt\" or \"decrypt\"\n");
        exit(1);
    }

    // Get the operation, input file, and output file
    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];

    // Perform the encryption/decryption
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        exit(1);
    }

    return 0;
}