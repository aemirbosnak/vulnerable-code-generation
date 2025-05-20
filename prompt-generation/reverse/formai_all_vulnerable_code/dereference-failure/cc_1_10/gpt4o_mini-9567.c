//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define BUFFER_SIZE 1024
#define KEY 123  // Simple XOR key for encryption; can be changed.

// Function prototypes
void encrypt_file(const char *filename);
void decrypt_file(const char *filename);
void process_file(const char *filename, int is_encrypting);
void handle_error(const char *message);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encrypt' or 'decrypt'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void encrypt_file(const char *filename) {
    printf("Encrypting file: %s\n", filename);
    process_file(filename, 1);
}

void decrypt_file(const char *filename) {
    printf("Decrypting file: %s\n", filename);
    process_file(filename, 0);
}

void process_file(const char *filename, int is_encrypting) {
    FILE *input_file = fopen(filename, "rb");
    if (!input_file) {
        handle_error("Unable to open input file for reading.");
    }

    char output_filename[MAX_FILENAME_LENGTH];
    snprintf(output_filename, sizeof(output_filename), "%s.%s", filename, 
             is_encrypting ? "enc" : "dec");
    
    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        fclose(input_file);
        handle_error("Unable to open output file for writing.");
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= KEY;  // Simple XOR encryption/decryption.
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    printf("File processed successfully: %s -> %s\n", filename, output_filename);

    fclose(input_file);
    fclose(output_file);
}

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}