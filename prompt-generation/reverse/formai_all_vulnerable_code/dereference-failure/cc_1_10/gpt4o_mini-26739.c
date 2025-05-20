//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define KEY_SIZE 16

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void encrypt_decrypt(char *input, char *output, char *key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE];
    }
}

void file_exists(const char *filename) {
    if (access(filename, F_OK) != 0) {
        fprintf(stderr, "The file '%s' does not exist.\n", filename);
        exit(EXIT_FAILURE);
    }
}

void encrypt_file(const char *input_filename, const char *output_filename, const char *key) {
    int input_fd = open(input_filename, O_RDONLY);
    if (input_fd < 0) handle_error("Failed to open input file");

    int output_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) handle_error("Failed to open output file");

    char buffer[BUFFER_SIZE];
    char encrypted_buffer[BUFFER_SIZE];

    ssize_t bytes_read;
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        encrypt_decrypt(buffer, encrypted_buffer, key);
        write(output_fd, encrypted_buffer, bytes_read);
    }

    if (bytes_read < 0) handle_error("Failed to read from input file");

    close(input_fd);
    close(output_fd);
}

void decrypt_file(const char *input_filename, const char *output_filename, const char *key) {
    int input_fd = open(input_filename, O_RDONLY);
    if (input_fd < 0) handle_error("Failed to open input file");

    int output_fd = open(output_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd < 0) handle_error("Failed to open output file");

    char buffer[BUFFER_SIZE];
    char decrypted_buffer[BUFFER_SIZE];

    ssize_t bytes_read;
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        encrypt_decrypt(buffer, decrypted_buffer, key);
        write(output_fd, decrypted_buffer, bytes_read);
    }

    if (bytes_read < 0) handle_error("Failed to read from input file");

    close(input_fd);
    close(output_fd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *operation = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];
    const char *key = argv[4];

    if (strlen(key) != KEY_SIZE) {
        fprintf(stderr, "Key must be exactly %d characters long.\n", KEY_SIZE);
        exit(EXIT_FAILURE);
    }

    file_exists(input_file);

    if (strcmp(operation, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
        printf("File '%s' encrypted to '%s'.\n", input_file, output_file);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
        printf("File '%s' decrypted to '%s'.\n", input_file, output_file);
    } else {
        fprintf(stderr, "Invalid operation: '%s'. Use 'encrypt' or 'decrypt'.\n", operation);
        exit(EXIT_FAILURE);
    }

    return 0;
}