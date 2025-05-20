//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

void print_usage(const char* program_name) {
    printf("Usage: %s <encrypt|decrypt> <key> <input_file> <output_file>\n", program_name);
}

void generate_key(const char* base_key, char* key) {
    size_t key_length = strlen(base_key);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = base_key[i % key_length];
    }
}

void encrypt_file(const char* input_file_path, const char* output_file_path, const char* key) {
    FILE* input_file = fopen(input_file_path, "rb");
    FILE* output_file = fopen(output_file_path, "wb");

    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files!\n");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t key_length = strlen(key);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length];
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(const char* input_file_path, const char* output_file_path, const char* key) {
    // Decryption is the same as encryption in XOR
    encrypt_file(input_file_path, output_file_path, key);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char* operation = argv[1];
    const char* base_key = argv[2];
    const char* input_file_path = argv[3];
    const char* output_file_path = argv[4];

    // Generate a key
    char key[KEY_SIZE];
    generate_key(base_key, key);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file_path, output_file_path, key);
        printf("File '%s' encrypted to '%s'.\n", input_file_path, output_file_path);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file_path, output_file_path, key);
        printf("File '%s' decrypted to '%s'.\n", input_file_path, output_file_path);
    } else {
        fprintf(stderr, "Invalid operation! Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}