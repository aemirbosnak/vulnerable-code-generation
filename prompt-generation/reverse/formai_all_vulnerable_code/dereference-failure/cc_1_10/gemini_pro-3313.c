//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define ENCRYPTION_KEY "MySecretEncryptionKey"

// Function to encrypt a file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char buffer[1024];
    char encrypted_buffer[1024];

    // Read the input file in chunks of 1024 bytes
    while (fgets(buffer, 1024, input_file) != NULL) {
        // Encrypt the buffer
        int buffer_length = strlen(buffer);
        for (int i = 0; i < buffer_length; i++) {
            encrypted_buffer[i] = buffer[i] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
        }

        // Write the encrypted buffer to the output file
        fwrite(encrypted_buffer, 1, buffer_length, output_file);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char buffer[1024];
    char decrypted_buffer[1024];

    // Read the input file in chunks of 1024 bytes
    while (fgets(buffer, 1024, input_file) != NULL) {
        // Decrypt the buffer
        int buffer_length = strlen(buffer);
        for (int i = 0; i < buffer_length; i++) {
            decrypted_buffer[i] = buffer[i] ^ ENCRYPTION_KEY[i % strlen(ENCRYPTION_KEY)];
        }

        // Write the decrypted buffer to the output file
        fwrite(decrypted_buffer, 1, buffer_length, output_file);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Get the input and output file names from the command line arguments
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    char *input_file_name = argv[1];
    char *output_file_name = argv[2];
    char *operation = argv[3];

    // Open the input and output files
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        return 1;
    }

    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_file_name);
        return 1;
    }

    // Perform the encryption or decryption operation
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}