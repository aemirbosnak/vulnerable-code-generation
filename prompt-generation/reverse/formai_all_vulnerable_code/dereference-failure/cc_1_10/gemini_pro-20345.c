//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define ENCRYPTION_KEY 0x12345678

// Function to encrypt a file
void encrypt_file(const char *input_file, const char *output_file) {
    // Open the input file for reading
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file for writing
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file in chunks of 1024 bytes
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, input)) > 0) {
        // Encrypt the buffer using the encryption key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= ENCRYPTION_KEY;
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(const char *input_file, const char *output_file) {
    // Open the input file for reading
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file for writing
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file in chunks of 1024 bytes
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, 1024, input)) > 0) {
        // Decrypt the buffer using the encryption key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= ENCRYPTION_KEY;
        }

        // Write the decrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    // Encrypt the input file
    encrypt_file(argv[1], argv[2]);

    // Decrypt the output file
    decrypt_file(argv[2], "decrypted.txt");

    return 0;
}