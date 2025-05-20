//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt or decrypt a file using XOR operation
void xor_encrypt_decrypt(FILE *input, FILE *output, char key) {
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output); // Apply XOR operation with the key
    }
}

// Function to display usage instructions
void display_usage(const char *program_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", program_name);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage(argv[0]);
        return 1; // Exit with error
    }

    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char key = argv[4][0]; // Use the first character as the key

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        xor_encrypt_decrypt(input, output, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        xor_encrypt_decrypt(input, output, key);
        printf("File decrypted successfully.\n");
    } else {
        display_usage(argv[0]);
    }

    fclose(input);
    fclose(output);
    return 0; // Exit successfully
}