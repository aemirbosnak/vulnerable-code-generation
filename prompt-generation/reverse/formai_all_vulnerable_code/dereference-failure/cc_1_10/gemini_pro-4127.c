//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
int encrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return EXIT_FAILURE;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return EXIT_FAILURE;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file in chunks
    int chunk_size = 1024;
    char chunk[chunk_size];
    while(fread(chunk, chunk_size, 1, input) > 0) {
        // Encrypt the chunk
        for (int i = 0; i < chunk_size; i++) {
            chunk[i] ^= key[i % key_len];
        }

        // Write the encrypted chunk to the output file
        fwrite(chunk, chunk_size, 1, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return EXIT_FAILURE;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return EXIT_FAILURE;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file in chunks
    int chunk_size = 1024;
    char chunk[chunk_size];
    while(fread(chunk, chunk_size, 1, input) > 0) {
        // Decrypt the chunk
        for (int i = 0; i < chunk_size; i++) {
            chunk[i] ^= key[i % key_len];
        }

        // Write the decrypted chunk to the output file
        fwrite(chunk, chunk_size, 1, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <encrypt/decrypt> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];
    char *key = argv[4];

    if (strcmp(mode, "encrypt") == 0) {
        if (encrypt_file(input_file, output_file, key) != EXIT_SUCCESS) {
            fprintf(stderr, "Error encrypting file: %s\n", input_file);
            return EXIT_FAILURE;
        }
    } else if (strcmp(mode, "decrypt") == 0) {
        if (decrypt_file(input_file, output_file, key) != EXIT_SUCCESS) {
            fprintf(stderr, "Error decrypting file: %s\n", input_file);
            return EXIT_FAILURE;
        }
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}