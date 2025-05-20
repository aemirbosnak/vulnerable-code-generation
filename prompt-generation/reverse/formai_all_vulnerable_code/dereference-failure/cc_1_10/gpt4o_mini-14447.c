//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a single character
char encrypt_char(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + key) % 26;
    } else if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + key) % 26;
    }
    return c;
}

// Function to encrypt a file
void encrypt_file(const char *input_filename, const char *output_filename, int key) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fclose(input_file);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(encrypt_char(c, key), output_file);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Encryption complete: %s -> %s\n", input_filename, output_filename);
}

// Function to decrypt a single character
char decrypt_char(char c, int key) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' - key + 26) % 26;
    } else if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' - key + 26) % 26;
    }
    return c;
}

// Function to decrypt a file
void decrypt_file(const char *input_filename, const char *output_filename, int key) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        fclose(input_file);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char c;
    while ((c = fgetc(input_file)) != EOF) {
        fputc(decrypt_char(c, key), output_file);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Decryption complete: %s -> %s\n", input_filename, output_filename);
}

// Main program function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    const char *input_filename = argv[2];
    const char *output_filename = argv[3];
    int key = atoi(argv[4]);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_filename, output_filename, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_filename, output_filename, key);
    } else {
        printf("Invalid mode. Choose either 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}