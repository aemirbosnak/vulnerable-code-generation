//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "YOUR_SECRET_KEY"

// Function to encrypt a file
void encrypt_file(const char *input_file, const char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        exit(1);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for buffer\n");
        fclose(input);
        fclose(output);
        exit(1);
    }

    // Read the file contents into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, input);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error reading input file\n");
        fclose(input);
        fclose(output);
        free(buffer);
        exit(1);
    }

    // Encrypt the buffer using XOR encryption
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted buffer to the output file
    size_t bytes_written = fwrite(buffer, 1, file_size, output);
    if (bytes_written != file_size) {
        fprintf(stderr, "Error writing output file\n");
        fclose(input);
        fclose(output);
        free(buffer);
        exit(1);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Free the buffer
    free(buffer);

    printf("File encrypted successfully\n");
}

// Function to decrypt a file
void decrypt_file(const char *input_file, const char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        exit(1);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for buffer\n");
        fclose(input);
        fclose(output);
        exit(1);
    }

    // Read the file contents into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, input);
    if (bytes_read != file_size) {
        fprintf(stderr, "Error reading input file\n");
        fclose(input);
        fclose(output);
        free(buffer);
        exit(1);
    }

    // Decrypt the buffer using XOR encryption
    for (long i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted buffer to the output file
    size_t bytes_written = fwrite(buffer, 1, file_size, output);
    if (bytes_written != file_size) {
        fprintf(stderr, "Error writing output file\n");
        fclose(input);
        fclose(output);
        free(buffer);
        exit(1);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Free the buffer
    free(buffer);

    printf("File decrypted successfully\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <mode>\n", argv[0]);
        fprintf(stderr, "Mode: encrypt or decrypt\n");
        exit(1);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *mode = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        exit(1);
    }

    return 0;
}