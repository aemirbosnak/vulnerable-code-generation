//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// The key to encrypt and decrypt the file
#define KEY 17

// Function to encrypt a file
void encrypt_file(FILE *input, FILE *output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ KEY, output);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input, FILE *output) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ KEY, output);
    }
}

// Function to get the file size
int get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <encrypt|decrypt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input and output files
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // Get the file size
    int file_size = get_file_size(input);

    // Encrypt or decrypt the file
    if (strcmp(argv[3], "encrypt") == 0) {
        encrypt_file(input, output);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decrypt_file(input, output);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}