//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the encryption/decryption
#define KEY 0x1234

// Function to encrypt a file
int encrypt_file(const char *input_filename, const char *output_filename) {
    // Open the input file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return -1;
    }

    // Read the input file in chunks
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Encrypt the chunk using XOR with the key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY;
        }

        // Write the encrypted chunk to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Function to decrypt a file
int decrypt_file(const char *input_filename, const char *output_filename) {
    // Open the input file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return -1;
    }

    // Read the input file in chunks
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Decrypt the chunk using XOR with the key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY;
        }

        // Write the decrypted chunk to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <encrypt|decrypt> <input_filename> <output_filename>\n", argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        return encrypt_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        return decrypt_file(argv[2], argv[3]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        return -1;
    }
}