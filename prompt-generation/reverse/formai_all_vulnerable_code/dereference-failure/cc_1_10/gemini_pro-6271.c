//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input file
#define MAX_FILE_SIZE 1024

// Define the encryption key
#define ENCRYPTION_KEY 0x12345678

// Define the function to encrypt a file
void encrypt_file(char *input_file_name, char *output_file_name) {
    // Open the input file
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read the input file into a buffer
    unsigned char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file);
    if (bytes_read == 0) {
        perror("Error reading input file");
        exit(1);
    }

    // Encrypt the buffer
    for (size_t i = 0; i < bytes_read; i++) {
        buffer[i] ^= ENCRYPTION_KEY;
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, bytes_read, output_file);
    if (ferror(output_file)) {
        perror("Error writing output file");
        exit(1);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        exit(1);
    }

    // Encrypt the file
    encrypt_file(argv[1], argv[2]);

    // Return success
    return 0;
}