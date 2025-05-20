//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a key
int encrypt_file(char *input_file_path, char *output_file_path, char *key) {
    // Open the input file
    FILE *input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return -1;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file in chunks
    int chunk_size = 1024;
    char *chunk = malloc(chunk_size);
    while (fread(chunk, 1, chunk_size, input_file) > 0) {
        // Encrypt the chunk
        for (int i = 0; i < chunk_size; i++) {
            chunk[i] ^= key[i % key_len];
        }

        // Write the encrypted chunk to the output file
        fwrite(chunk, 1, chunk_size, output_file);
    }

    // Close the input and output files
    free(chunk);
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Function to decrypt a file using a key
int decrypt_file(char *input_file_path, char *output_file_path, char *key) {
    // Open the input file
    FILE *input_file = fopen(input_file_path, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return -1;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file in chunks
    int chunk_size = 1024;
    char *chunk = malloc(chunk_size);
    while (fread(chunk, 1, chunk_size, input_file) > 0) {
        // Decrypt the chunk
        for (int i = 0; i < chunk_size; i++) {
            chunk[i] ^= key[i % key_len];
        }

        // Write the decrypted chunk to the output file
        fwrite(chunk, 1, chunk_size, output_file);
    }

    // Close the input and output files
    free(chunk);
    fclose(input_file);
    fclose(output_file);

    return 0;
}

int main(int argc, char **argv) {
    // Check if the user provided enough arguments
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_file_path> <output_file_path> <key> <encrypt/decrypt>\n", argv[0]);
        return -1;
    }

    // Get the input file path
    char *input_file_path = argv[1];

    // Get the output file path
    char *output_file_path = argv[2];

    // Get the key
    char *key = argv[3];

    // Get the mode (encrypt or decrypt)
    char *mode = argv[4];

    // Encrypt or decrypt the file
    int result;
    if (strcmp(mode, "encrypt") == 0) {
        result = encrypt_file(input_file_path, output_file_path, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        result = decrypt_file(input_file_path, output_file_path, key);
    } else {
        fprintf(stderr, "Invalid mode. Must be \"encrypt\" or \"decrypt\".\n");
        return -1;
    }

    // Check if the encryption/decryption was successful
    if (result != 0) {
        fprintf(stderr, "Error encrypting/decrypting file.\n");
        return -1;
    }

    return 0;
}