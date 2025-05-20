//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void encrypt(const char *input_file, const char *output_file, char key);
void decrypt(const char *input_file, const char *output_file, char key);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    // Artistic prompt for the user
    printf("=========================================\n");
    printf("        C File Encryptor v1.0          \n");
    printf("=========================================\n");

    // Check for correct number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char operation = argv[1][0];
    char key = argv[4][0];

    if (operation == 'e') {
        // Call encrypt function
        encrypt(argv[2], argv[3], key);
    } 
    else if (operation == 'd') {
        // Call decrypt function
        decrypt(argv[2], argv[3], key);
    } 
    else {
        fprintf(stderr, "Invalid operation! Use 'e' for encrypt or 'd' for decrypt.\n");
        return 1;
    }

    // Indicate successful completion
    printf("Operation completed successfully!\n");
    return 0;
}

void encrypt(const char *input_file, const char *output_file, char key) {
    FILE *input = fopen(input_file, "rb");
    if (!input) handle_error("Failed to open input file for reading.");

    FILE *output = fopen(output_file, "wb");
    if (!output) handle_error("Failed to open output file for writing.");

    int ch;
    // Read each byte and XOR it with the key
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output);
    }

    // Close files after operation
    fclose(input);
    fclose(output);
    printf("File '%s' encrypted to '%s' using key '%c'.\n", input_file, output_file, key);
}

void decrypt(const char *input_file, const char *output_file, char key) {
    FILE *input = fopen(input_file, "rb");
    if (!input) handle_error("Failed to open input file for reading.");

    FILE *output = fopen(output_file, "wb");
    if (!output) handle_error("Failed to open output file for writing.");

    int ch;
    // Read each byte and XOR it with the key
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output);
    }

    // Close files after operation
    fclose(input);
    fclose(output);
    printf("File '%s' decrypted to '%s' using key '%c'.\n", input_file, output_file, key);
}

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}