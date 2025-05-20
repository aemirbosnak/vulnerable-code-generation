//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "my_secret_key"

// Function to encrypt a file
int encrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return -1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        return -1;
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the encrypted data
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for buffer\n");
        fclose(input);
        fclose(output);
        return -1;
    }

    // Read the input file into the buffer
    fread(buffer, 1, file_size, input);
    fclose(input);

    // Encrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted data to the output file
    fwrite(buffer, 1, file_size, output);
    fclose(output);

    // Free the buffer
    free(buffer);

    return 0;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return -1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        return -1;
    }

    // Get the file size
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    // Create a buffer to hold the decrypted data
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for buffer\n");
        fclose(input);
        fclose(output);
        return -1;
    }

    // Read the input file into the buffer
    fread(buffer, 1, file_size, input);
    fclose(input);

    // Decrypt the buffer
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted data to the output file
    fwrite(buffer, 1, file_size, output);
    fclose(output);

    // Free the buffer
    free(buffer);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <encrypt/decrypt>\n", argv[0]);
        return -1;
    }

    // Get the input file name
    char *input_file = argv[1];

    // Get the output file name
    char *output_file = argv[2];

    // Get the action (encrypt/decrypt)
    char *action = argv[3];

    // Check if the action is valid
    if (strcmp(action, "encrypt") != 0 && strcmp(action, "decrypt") != 0) {
        fprintf(stderr, "Invalid action: %s\n", action);
        return -1;
    }

    // Perform the encryption or decryption
    int result;
    if (strcmp(action, "encrypt") == 0) {
        result = encrypt_file(input_file, output_file);
    } else {
        result = decrypt_file(input_file, output_file);
    }

    // Check if the operation was successful
    if (result != 0) {
        fprintf(stderr, "Error performing %s operation\n", action);
        return -1;
    }

    // Print a success message
    printf("%s operation completed successfully\n", action);

    return 0;
}