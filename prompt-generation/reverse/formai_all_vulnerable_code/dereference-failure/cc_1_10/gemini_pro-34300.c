//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: safe
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
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Get the file size
    fseek(input, 0L, SEEK_END);
    long int file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to hold the file contents
    char *buffer = (char *)malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, input);

    // Encrypt the buffer using the XOR encryption algorithm
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the encrypted buffer to the output file
    fwrite(buffer, 1, file_size, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Function to decrypt a file
int decrypt_file(char *input_file, char *output_file) {
    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return -1;
    }

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        return -1;
    }

    // Get the file size
    fseek(input, 0L, SEEK_END);
    long int file_size = ftell(input);
    rewind(input);

    // Allocate a buffer to hold the file contents
    char *buffer = (char *)malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        return -1;
    }

    // Read the file contents into the buffer
    fread(buffer, 1, file_size, input);

    // Decrypt the buffer using the XOR encryption algorithm
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= KEY[i % strlen(KEY)];
    }

    // Write the decrypted buffer to the output file
    fwrite(buffer, 1, file_size, output);

    // Free the buffer
    free(buffer);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <encrypt|decrypt> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the input file name
    char *input_file = argv[1];

    // Get the output file name
    char *output_file = argv[2];

    // Get the operation type (encrypt or decrypt)
    char *operation = argv[3];

    // Get the password
    char *password = argv[4];

    // Check if the password is correct
    if (strcmp(password, KEY) != 0) {
        printf("Incorrect password\n");
        return EXIT_FAILURE;
    }

    // Check if the operation is valid
    if (strcmp(operation, "encrypt") == 0) {
        // Encrypt the file
        if (encrypt_file(input_file, output_file) != 0) {
            return EXIT_FAILURE;
        }
    } else if (strcmp(operation, "decrypt") == 0) {
        // Decrypt the file
        if (decrypt_file(input_file, output_file) != 0) {
            return EXIT_FAILURE;
        }
    } else {
        printf("Invalid operation\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}