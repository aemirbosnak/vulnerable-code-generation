//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void encrypt_decrypt(FILE *input_file, FILE *output_file, char *key) {
    char buffer[BUFFER_SIZE];
    size_t key_len = strlen(key);
    size_t key_index = 0;
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[key_index];  // XOR operation
            key_index = (key_index + 1) % key_len;  // Loop over key
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

void usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", prog_name);
    printf("Example: %s encrypt example.txt encrypted.txt mysecretkey\n", prog_name);
    printf("Example: %s decrypt encrypted.txt decrypted.txt mysecretkey\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char *operation = argv[1];
    char *input_file_path = argv[2];
    char *output_file_path = argv[3];
    char *key = argv[4];

    FILE *input_file = fopen(input_file_path, "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(output_file_path, "wb");
    if (!output_file) {
        fclose(input_file);
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key);
        printf("File decrypted successfully.\n");
    } else {
        usage(argv[0]);
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}