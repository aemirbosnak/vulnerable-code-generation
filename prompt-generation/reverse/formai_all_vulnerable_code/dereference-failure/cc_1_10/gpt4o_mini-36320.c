//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA  // Your cyber-enhanced encryption key
#define BUFFER_SIZE 4096  // For hyperspeed data transfer

// Function prototypes for adding flair
void encrypt_file(const char *input_file, const char *output_file);
void decrypt_file(const char *input_file, const char *output_file);
void show_help();

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        show_help();
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2], argv[3]);
        printf("Encryption complete. Your data is now secure in the neon haze.\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2], argv[3]);
        printf("Decryption complete. The shadows of your data are now revealed.\n");
    } else {
        show_help();
        return 1;
    }

    return 0;
}

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    
    if (!in) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    if (!out) {
        perror("Failed to open output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (size_t i = 0; i < bytes_read; ++i) {
            buffer[i] ^= KEY;  // The Cybernetic Encryption Protocol
        }
        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt_file(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    
    if (!in) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }
    if (!out) {
        perror("Failed to open output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Decrypting data similarly using the XOR operation
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (size_t i = 0; i < bytes_read; ++i) {
            buffer[i] ^= KEY;  // Unraveling the encrypted data
        }
        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void show_help() {
    printf("\n=== Cyberpunk File Encryptor ===\n");
    printf("A tool to protect your secrets in the world of neon.\n");
    printf("Commands:\n");
    printf("   encrypt <input_file> <output_file>  // Encrypt your data\n");
    printf("   decrypt <input_file> <output_file>  // Decrypt your data\n");
    printf("====================================\n");
}