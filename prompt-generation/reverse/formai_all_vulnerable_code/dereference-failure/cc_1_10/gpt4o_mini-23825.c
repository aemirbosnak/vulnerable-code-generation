//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 32   // Size of the encryption key

// Function to display the usage of the program
void display_usage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file> <key>\n");
    printf("Example: file_encryptor encrypt myfile.txt myfile.enc mysecretkey12345\n");
}

// Function to validate the length of the key
bool validate_key(const char *key) {
    if (strlen(key) != KEY_SIZE) {
        fprintf(stderr, "Error: Key must be exactly %d characters.\n", KEY_SIZE);
        return false;
    }
    return true;
}

// Function to encrypt or decrypt the contents of a file
void process_file(const char *input_file, const char *output_file, const char *key, bool encrypt) {
    FILE *f_input = fopen(input_file, "rb");
    FILE *f_output = fopen(output_file, "wb");

    if (!f_input || !f_output) {
        perror("File error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, f_input)) > 0) {
        for (size_t i = 0; i < bytesRead; ++i) {
            buffer[i] ^= key[i % KEY_SIZE]; // XOR operation for encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, f_output);
    }

    fclose(f_input);
    fclose(f_output);
    printf("%s operation completed successfully!\n", encrypt ? "Encryption" : "Decryption");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage();
        return EXIT_FAILURE;
    }

    bool encrypt = strcmp(argv[1], "encrypt") == 0;
    if (!encrypt && strcmp(argv[1], "decrypt") != 0) {
        fprintf(stderr, "Error: First argument must be 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key = argv[4];

    if (!validate_key(key)) {
        return EXIT_FAILURE;
    }

    process_file(input_file, output_file, key, encrypt);

    return EXIT_SUCCESS;
}