//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT_AMOUNT 3 // Amount to shift ASCII values for encryption

// Function prototypes
void encrypt_recursive(char *buffer, int index, int length, int shift);
void encrypt_file(const char *input_file, const char *output_file);

int main() {
    char input_file[256];
    char output_file[256];

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file);
    
    printf("Enter the name of the output encrypted file: ");
    scanf("%s", output_file);
    
    encrypt_file(input_file, output_file);
    
    printf("File encryption completed successfully!\n");
    return 0;
}

// Function that reads a file and encrypts its contents
void encrypt_file(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    // Move to the end of the file to determine the length
    fseek(input, 0, SEEK_END);
    long length = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Allocate memory for the file contents
    char *buffer = malloc(length + 1);
    if (!buffer) {
        perror("Could not allocate memory");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file
    fread(buffer, 1, length, input);
    buffer[length] = '\0'; // Null-terminate the string
    fclose(input);

    // Encrypt the buffer recursively
    encrypt_recursive(buffer, 0, length, SHIFT_AMOUNT);

    // Write the encrypted content to the output file
    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Could not open output file");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, 1, length, output);
    fclose(output);
    free(buffer);
}

// Recursive function to encrypt the content
void encrypt_recursive(char *buffer, int index, int length, int shift) {
    if (index >= length) {
        return; // Base case: reached the end of the buffer
    }
    
    // Encrypt the character by shifting its ASCII value
    buffer[index] += shift;

    // Recursive call for the next character
    encrypt_recursive(buffer, index + 1, length, shift);
}