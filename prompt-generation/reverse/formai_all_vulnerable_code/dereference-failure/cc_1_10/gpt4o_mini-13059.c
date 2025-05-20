//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function declarations
void encrypt_file(const char *input_file, const char *output_file, const char *key);
void decrypt_file(const char *input_file, const char *output_file, const char *key);
void xor_encrypt_decrypt(const char *input, char *output, const char *key, size_t length);
void print_usage(const char *program_name);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1]; // Encrypt or Decrypt
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key = argv[4];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    printf("Operation completed successfully.\n");
    return EXIT_SUCCESS;
}

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(output_file, "wb");
    if (!out) {
        fclose(in);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    size_t key_length = strlen(key);

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        char encrypted[BUFFER_SIZE];
        xor_encrypt_decrypt(buffer, encrypted, key, bytes_read);
        fwrite(encrypted, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt_file(const char *input_file, const char *output_file, const char *key) {
    // Decryption process is identical to encryption using XOR
    encrypt_file(input_file, output_file, key);
}

void xor_encrypt_decrypt(const char *input, char *output, const char *key, size_t length) {
    size_t key_length = strlen(key);
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", program_name);
    fprintf(stderr, "Example: %s encrypt myfile.txt encrypted.dat mysecretkey\n", program_name);
    fprintf(stderr, "         %s decrypt encrypted.dat decrypted.txt mysecretkey\n", program_name);
}