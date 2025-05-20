//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "your_encryption_key"

// Function to encrypt a file
int encrypt_file(char *filename) {
    // Open the input file
    FILE *input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", filename);
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen("encrypted.txt", "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: encrypted.txt\n");
        return -1;
    }

    // Read the input file in chunks
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Encrypt the buffer
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Function to decrypt a file
int decrypt_file(char *filename) {
    // Open the input file
    FILE *input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", filename);
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen("decrypted.txt", "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output file: decrypted.txt\n");
        return -1;
    }

    // Read the input file in chunks
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        // Decrypt the buffer
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY[i % strlen(KEY)];
        }

        // Write the decrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(int argc, char *argv[]) {
    // Check if the user specified a filename
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Get the filename from the command line
    char *filename = argv[1];

    // Encrypt the file
    if (encrypt_file(filename) != 0) {
        fprintf(stderr, "Error encrypting file: %s\n", filename);
        return -1;
    }

    // Decrypt the file
    if (decrypt_file("encrypted.txt") != 0) {
        fprintf(stderr, "Error decrypting file: encrypted.txt\n");
        return -1;
    }

    return 0;
}