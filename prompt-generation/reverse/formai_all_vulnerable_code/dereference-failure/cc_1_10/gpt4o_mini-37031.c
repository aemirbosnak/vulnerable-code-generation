//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SHIFT 3

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "Error: Unable to open file. \n");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Encryption Process
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, in_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = (buffer[i] + SHIFT) % 256;  // Simple Caesar Cipher
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, out_file);
    }

    fclose(in_file);
    fclose(out_file);
    printf("File encrypted: %s -> %s\n", input_file, output_file);
}

void decrypt_file(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");
    if (in_file == NULL || out_file == NULL) {
        fprintf(stderr, "Error: Unable to open file. \n");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Decryption Process
    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, in_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = (buffer[i] - SHIFT + 256) % 256; // Simple Caesar Cipher
        }
        fwrite(buffer, sizeof(unsigned char), bytes_read, out_file);
    }

    fclose(in_file);
    fclose(out_file);
    printf("File decrypted: %s -> %s\n", input_file, output_file);
}

void display_banner() {
    printf("============================================\n");
    printf("          Cyberpunk File Encryptor          \n");
    printf("         Your data, your control.          \n");
    printf("            V. 2.0 - Neon Dreams            \n");
    printf("============================================\n");
}

void show_usage() {
    fprintf(stderr, "Usage: ./cyber_encrypt [encrypt|decrypt] input_file output_file\n");
}

int main(int argc, char *argv[]) {
    display_banner();
    if (argc != 4) {
        show_usage();
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file);
    } else {
        fprintf(stderr, "Error: Unknown mode '%s'.\n", mode);
        show_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}