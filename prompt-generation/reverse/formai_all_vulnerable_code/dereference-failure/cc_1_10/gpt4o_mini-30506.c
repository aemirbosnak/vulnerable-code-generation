//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KEY_LENGTH 16
#define BUFFER_SIZE 1024

// Function prototypes
void generate_random_key(char *key, size_t length);
void encrypt_decrypt_file(const char *input_file, const char *output_file, const char *key);
void xor_encrypt_decrypt(char *data, size_t length, const char *key, size_t key_length);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *key = argv[3];

    if (strlen(key) != KEY_LENGTH) {
        fprintf(stderr, "Error: Key must be exactly %d characters long.\n", KEY_LENGTH);
        return EXIT_FAILURE;
    }

    encrypt_decrypt_file(input_file, output_file, key);

    printf("File '%s' has been processed and saved to '%s'.\n", input_file, output_file);
    return EXIT_SUCCESS;
}

void encrypt_decrypt_file(const char *input_file, const char *output_file, const char *key) {
    int input_fd = open(input_file, O_RDONLY);
    if (input_fd == -1) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (output_fd == -1) {
        perror("Could not open output file");
        close(input_fd);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(input_fd, buffer, sizeof(buffer))) > 0) {
        xor_encrypt_decrypt(buffer, bytes_read, key, KEY_LENGTH);
        write(output_fd, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading from input file");
    }

    close(input_fd);
    close(output_fd);
}

void xor_encrypt_decrypt(char *data, size_t length, const char *key, size_t key_length) {
    for (size_t i = 0; i < length; i++) {
        data[i] ^= key[i % key_length];
    }
}

// Utility function to generate a random key (to be used if desired)
void generate_random_key(char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        key[i] = rand() % 256; // Generates a random byte
    }
}