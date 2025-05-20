//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a given key
void encrypt_file(const char* input_file, const char* output_file, const char* key) {
    // Open the input and output files
    FILE *in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error opening input file %s\n", input_file);
        return;
    }
    FILE *out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error opening output file %s\n", output_file);
        fclose(in_file);
        return;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file and encrypt it
    int c;
    int key_idx = 0;
    while ((c = fgetc(in_file)) != EOF) {
        // Encrypt the character using the key
        c ^= key[key_idx];

        // Increment the key index
        key_idx = (key_idx + 1) % key_len;

        // Write the encrypted character to the output file
        fputc(c, out_file);
    }

    // Close the input and output files
    fclose(in_file);
    fclose(out_file);
}

// Function to decrypt a file using a given key
void decrypt_file(const char* input_file, const char* output_file, const char* key) {
    // Open the input and output files
    FILE *in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error opening input file %s\n", input_file);
        return;
    }
    FILE *out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error opening output file %s\n", output_file);
        fclose(in_file);
        return;
    }

    // Get the length of the key
    int key_len = strlen(key);

    // Read the input file and decrypt it
    int c;
    int key_idx = 0;
    while ((c = fgetc(in_file)) != EOF) {
        // Decrypt the character using the key
        c ^= key[key_idx];

        // Increment the key index
        key_idx = (key_idx + 1) % key_len;

        // Write the decrypted character to the output file
        fputc(c, out_file);
    }

    // Close the input and output files
    fclose(in_file);
    fclose(out_file);
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 5) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file] [key]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the operation type
    char* operation = argv[1];

    // Get the input and output file names
    char* input_file = argv[2];
    char* output_file = argv[3];

    // Get the key
    char* key = argv[4];

    // Perform the encryption or decryption
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid operation: %s\n", operation);
        return EXIT_FAILURE;
    }

    // Exit successfully
    return EXIT_SUCCESS;
}