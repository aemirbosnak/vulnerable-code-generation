//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the encryption key
char key[] = "MySecretKey";

// Function to encrypt a file using XOR encryption
void encrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    // Check if the files were opened successfully
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the file contents
    char *buffer = malloc(file_size);

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, input);

    // Encrypt the file contents using XOR encryption
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted file contents to the output file
    fwrite(buffer, file_size, 1, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file using XOR encryption
void decrypt_file(char *input_file, char *output_file) {
    // Open the input and output files
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    // Check if the files were opened successfully
    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the file contents
    char *buffer = malloc(file_size);

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, input);

    // Decrypt the file contents using XOR encryption
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    // Write the decrypted file contents to the output file
    fwrite(buffer, file_size, 1, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Encrypt or decrypt the file
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2], argv[3]);
    } else {
        printf("Invalid operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}