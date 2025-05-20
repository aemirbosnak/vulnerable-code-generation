//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_LENGTH 16

void encrypt(char *buffer, const char *key) {
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = buffer[i] ^ key[i % KEY_LENGTH];
    }
}

void decrypt(char *buffer, const char *key) {
    // XOR is symmetric, so we can use the same function for decryption
    encrypt(buffer, key);
}

void process_file(const char *input_file, const char *output_file, const char *key, int mode) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        fprintf(stderr, "Error opening file(s).\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate for safety
        if (mode == 1) { // Encryption
            encrypt(buffer, key);
        } else { // Decryption
            decrypt(buffer, key);
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

void display_usage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file> <key>\n");
    printf("Key must be exactly %d characters long.\n", KEY_LENGTH);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage();
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char *key = argv[4];

    if (strlen(key) != KEY_LENGTH) {
        fprintf(stderr, "Error: Key must be exactly %d characters long.\n", KEY_LENGTH);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        process_file(input_file, output_file, key, 1);
        printf("File encrypted successfully: %s\n", output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        process_file(input_file, output_file, key, 0);
        printf("File decrypted successfully: %s\n", output_file);
    } else {
        display_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}