//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a key
int encrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Get the length of the key
    int key_length = strlen(key);

    // Read the input file byte by byte
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        // Encrypt the buffer using the key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length];
        }

        // Write the encrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to decrypt a file using a key
int decrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file in read mode
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file in write mode
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Get the length of the key
    int key_length = strlen(key);

    // Read the input file byte by byte
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        // Decrypt the buffer using the key
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length];
        }

        // Write the decrypted buffer to the output file
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Check the operation
    if (strcmp(argv[1], "encrypt") == 0) {
        // Encrypt the file
        encrypt_file(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        // Decrypt the file
        decrypt_file(argv[2], argv[3], argv[4]);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return 0;
}