//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 42

// Encrypt a character
char encrypt(char c) {
    return c ^ KEY;
}

// Decrypt a character
char decrypt(char c) {
    return c ^ KEY;
}

// Encrypt a file
void encrypt_file(char *input_filename, char *output_filename) {
    // Open the input file
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read a character from the input file
    char c = fgetc(input_file);

    // While there are still characters to read
    while (c != EOF) {
        // Encrypt the character
        c = encrypt(c);

        // Write the encrypted character to the output file
        fputc(c, output_file);

        // Read the next character from the input file
        c = fgetc(input_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}

// Decrypt a file
void decrypt_file(char *input_filename, char *output_filename) {
    // Open the input file
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Read a character from the input file
    char c = fgetc(input_file);

    // While there are still characters to read
    while (c != EOF) {
        // Decrypt the character
        c = decrypt(c);

        // Write the decrypted character to the output file
        fputc(c, output_file);

        // Read the next character from the input file
        c = fgetc(input_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);
}

// Print usage information
void usage() {
    printf("Usage: file_encryptor [encrypt|decrypt] input_file output_file\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 4) {
        usage();
        exit(1);
    }

    // Check if the operation is encrypt or decrypt
    char *operation = argv[1];
    if (strcmp(operation, "encrypt") != 0 && strcmp(operation, "decrypt") != 0) {
        printf("Error: Invalid operation. Must be either 'encrypt' or 'decrypt'.\n");
        exit(1);
    }

    // Get the input and output file names
    char *input_filename = argv[2];
    char *output_filename = argv[3];

    // Encrypt or decrypt the file
    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_filename, output_filename);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_filename, output_filename);
    }

    return 0;
}