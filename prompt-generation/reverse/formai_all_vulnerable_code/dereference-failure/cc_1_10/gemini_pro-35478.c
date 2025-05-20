//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

// Function to encrypt a file
int encrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return 1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file: %s\n", output_file);
        return 1;
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Read the file into a buffer
    char buffer[file_size];
    fread(buffer, 1, file_size, input);

    // Encrypt the buffer using the key
    int key_len = strlen(key);
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % key_len];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, file_size, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file, char *key) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return 1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file: %s\n", output_file);
        return 1;
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Read the file into a buffer
    char buffer[file_size];
    fread(buffer, 1, file_size, input);

    // Decrypt the buffer using the key
    int key_len = strlen(key);
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % key_len];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, file_size, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 5) {
        printf("Usage: %s <input_file> <output_file> <key> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    // Get the input and output file names
    char *input_file = argv[1];
    char *output_file = argv[2];

    // Get the key
    char *key = argv[3];

    // Get the operation (encrypt or decrypt)
    char *operation = argv[4];

    // Check the operation
    if (strcmp(operation, "encrypt") == 0) {
        // Encrypt the file
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        // Decrypt the file
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}