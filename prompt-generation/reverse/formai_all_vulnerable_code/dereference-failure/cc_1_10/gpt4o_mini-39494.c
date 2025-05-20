//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // Simple XOR key
#define MAX_BUF 1024

void encrypt_decrypt(unsigned char *data, size_t data_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= KEY; // XOR encryption/decryption
    }
}

void usage(const char *progname) {
    printf("Usage: %s <encrypt|decrypt> <inputfile> <outputfile>\n", progname);
    exit(EXIT_FAILURE);
}

FILE *open_file(const char *filename, const char *mode) {
    FILE *file = fopen(filename, mode);
    if (!file) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    return file;
}

size_t read_file(FILE *file, unsigned char *buffer) {
    size_t bytes_read = fread(buffer, sizeof(unsigned char), MAX_BUF, file);
    if (ferror(file)) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }
    return bytes_read;
}

void write_file(FILE *file, const unsigned char *buffer, size_t bytes_to_write) {
    size_t bytes_written = fwrite(buffer, sizeof(unsigned char), bytes_to_write, file);
    if (bytes_written < bytes_to_write) {
        perror("Error writing file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }

    const char *operation = argv[1];
    const char *input_file_name = argv[2];
    const char *output_file_name = argv[3];

    unsigned char buffer[MAX_BUF];
    FILE *input_file = open_file(input_file_name, "rb");
    FILE *output_file = open_file(output_file_name, "wb");

    size_t bytes_read;

    if (strcmp(operation, "encrypt") == 0) {
        while ((bytes_read = read_file(input_file, buffer)) > 0) {
            encrypt_decrypt(buffer, bytes_read);
            write_file(output_file, buffer, bytes_read);
        }
        printf("File encrypted successfully.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        while ((bytes_read = read_file(input_file, buffer)) > 0) {
            encrypt_decrypt(buffer, bytes_read);
            write_file(output_file, buffer, bytes_read);
        }
        printf("File decrypted successfully.\n");
    } else {
        usage(argv[0]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}