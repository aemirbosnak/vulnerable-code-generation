//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// Function prototypes
void encrypt_file(const char *input_file, const char *output_file, char key);
void decrypt_file(const char *input_file, const char *output_file, char key);
void handle_file_error(const char *filename);
void process_file(const char *input_file, const char *output_file, char key, int is_encrypt);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    char key = argv[4][0]; // Taking first char as key

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid operation! Use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    printf("Operation completed successfully.\n");
    return 0;
}

void encrypt_file(const char *input_file, const char *output_file, char key) {
    process_file(input_file, output_file, key, 1);
}

void decrypt_file(const char *input_file, const char *output_file, char key) {
    process_file(input_file, output_file, key, 0);
}

void process_file(const char *input_file, const char *output_file, char key, int is_encrypt) {
    FILE *in = fopen(input_file, "rb");
    if (in == NULL) {
        handle_file_error(input_file);
        return;
    }

    FILE *out = fopen(output_file, "wb");
    if (out == NULL) {
        fclose(in);
        handle_file_error(output_file);
        return;
    }

    int bytes_read;
    unsigned char buffer[MAX_BUFFER];

    while ((bytes_read = fread(buffer, sizeof(unsigned char), MAX_BUFFER, in)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key; // Simple XOR cipher
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void handle_file_error(const char *filename) {
    perror(filename);
    exit(EXIT_FAILURE);
}