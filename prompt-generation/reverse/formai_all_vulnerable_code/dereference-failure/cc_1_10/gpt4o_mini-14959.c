//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

// Function prototypes
void encrypt_decrypt(FILE *input_file, FILE *output_file, char key);
void print_usage();
void handle_file_error(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];
    char key = 'K';  // Simple key for XOR encryption

    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        handle_file_error(input_filename);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fclose(input_file);
        handle_file_error(output_filename);
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key);
        printf("File \"%s\" has been encrypted and saved as \"%s\".\n", input_filename, output_filename);
    } else if (strcmp(mode, "decrypt") == 0) {
        encrypt_decrypt(input_file, output_file, key);
        printf("File \"%s\" has been decrypted and saved as \"%s\".\n", input_filename, output_filename);
    } else {
        print_usage();
    }

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

void encrypt_decrypt(FILE *input_file, FILE *output_file, char key) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;  // XOR operation for encryption/decryption
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, output_file);
    }
}

void print_usage() {
    printf("Usage: file_encryptor <encrypt|decrypt> <input_file> <output_file>\n");
    printf("Example: file_encryptor encrypt myfile.txt myfile.enc\n");
    printf("         file_encryptor decrypt myfile.enc myfile.txt\n");
}

void handle_file_error(const char *filename) {
    perror(filename);
    exit(EXIT_FAILURE);
}