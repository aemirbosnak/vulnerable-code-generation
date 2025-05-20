//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "your_encryption_key"

// Function to encrypt a file
void encrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, input);

    // Encrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, file_size, 1, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file
void decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    int file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }

    // Read the file contents into the buffer
    fread(buffer, file_size, 1, input);

    // Decrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, file_size, 1, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Main function
int main() {
    // Get the input and output file names from the user
    char input_file[100];
    char output_file[100];
    printf("Enter the input file name: ");
    scanf("%s", input_file);
    printf("Enter the output file name: ");
    scanf("%s", output_file);

    // Encrypt the file
    encrypt_file(input_file, output_file);

    // Decrypt the file
    decrypt_file(output_file, "decrypted.txt");

    return 0;
}