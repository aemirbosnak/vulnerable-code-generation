//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: paranoid
// Paranoid File Encyptor 2.0
// Written by a Conspiracy Theorist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Encryption/Decryption Parameters
#define AES_KEY_LEN 32
#define AES_BLOCK_LEN 16
#define ENCRYPT_MODE AES_ENCRYPT
#define DECRYPT_MODE AES_DECRYPT

// Helper Functions
int check_args(int argc, char *argv[]);
void print_usage(char *prog_name);
void print_error(char *msg);
void print_success(char *msg);
void wipe_buffer(void *buffer, size_t size);
void xor_buffers(void *dest, void *src1, void *src2, size_t size);

// Encryption/Decryption Functions
int encrypt_file(char *input_file, char *output_file, unsigned char *aes_key);
int decrypt_file(char *input_file, char *output_file, unsigned char *aes_key);

// Main Function
int main(int argc, char *argv[]) {
    // Check Input Arguments
    if (check_args(argc, argv) != 0) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Generate a Random AES Key (32 bytes)
    unsigned char aes_key[AES_KEY_LEN];
    if (RAND_bytes(aes_key, AES_KEY_LEN) != 1) {
        print_error("Error generating AES key.");
        return EXIT_FAILURE;
    }

    // Encrypt or Decrypt File
    if (strcmp(argv[1], "encrypt") == 0) {
        if (encrypt_file(argv[2], argv[3], aes_key) != 0) {
            return EXIT_FAILURE;
        }
        print_success("File encrypted successfully.");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        if (decrypt_file(argv[2], argv[3], aes_key) != 0) {
            return EXIT_FAILURE;
        }
        print_success("File decrypted successfully.");
    } else {
        print_error("Invalid operation.");
        return EXIT_FAILURE;
    }

    // Wipe the AES Key from Memory (Paranoia)
    wipe_buffer(aes_key, AES_KEY_LEN);

    return EXIT_SUCCESS;
}

// Input Argument Checking
int check_args(int argc, char *argv[]) {
    if (argc != 4) {
        return -1;
    }
    if (strcmp(argv[1], "encrypt") != 0 && strcmp(argv[1], "decrypt") != 0) {
        return -1;
    }
    return 0;
}

// Usage Message
void print_usage(char *prog_name) {
    printf("Usage: %s [operation] [input_file] [output_file]\n", prog_name);
    printf("Operations:\n");
    printf("  encrypt: Encrypt input_file to output_file\n");
    printf("  decrypt: Decrypt input_file to output_file\n");
}

// Error Printing
void print_error(char *msg) {
    printf("Error: %s\n", msg);
}

// Success Message
void print_success(char *msg) {
    printf("Success: %s\n", msg);
}

// Buffer Wiping
void wipe_buffer(void *buffer, size_t size) {
    memset(buffer, 0, size);
}

// XORing Buffers
void xor_buffers(void *dest, void *src1, void *src2, size_t size) {
    unsigned char *d = (unsigned char *) dest;
    unsigned char *s1 = (unsigned char *) src1;
    unsigned char *s2 = (unsigned char *) src2;
    for (size_t i = 0; i < size; i++) {
        d[i] = s1[i] ^ s2[i];
    }
}

// File Encryption
int encrypt_file(char *input_file, char *output_file, unsigned char *aes_key) {
    // Open Input and Output Files
    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");
    if (input_fp == NULL || output_fp == NULL) {
        print_error("Error opening files.");
        return -1;
    }

    // Create Encryption Context
    AES_KEY aes_key_ctx;
    if (AES_set_encrypt_key(aes_key, AES_KEY_LEN * 8, &aes_key_ctx) != 0) {
        print_error("Error setting AES encryption key.");
        return -1;
    }

    // Read Input File and Encrypt
    size_t read_size;
    unsigned char input_buffer[AES_BLOCK_LEN];
    unsigned char output_buffer[AES_BLOCK_LEN];
    while ((read_size = fread(input_buffer, 1, AES_BLOCK_LEN, input_fp)) > 0) {
        // Pad Block
        if (read_size < AES_BLOCK_LEN) {
            memset(input_buffer + read_size, 0, AES_BLOCK_LEN - read_size);
        }
        // Encrypt Block
        AES_ecb_encrypt(input_buffer, output_buffer, &aes_key_ctx, ENCRYPT_MODE);
        // Write Encrypted Block
        fwrite(output_buffer, 1, AES_BLOCK_LEN, output_fp);
    }

    // Close Files
    fclose(input_fp);
    fclose(output_fp);

    // Wipe Buffers (Paranoia)
    wipe_buffer(input_buffer, AES_BLOCK_LEN);
    wipe_buffer(output_buffer, AES_BLOCK_LEN);

    return 0;
}

// File Decryption
int decrypt_file(char *input_file, char *output_file, unsigned char *aes_key) {
    // Open Input and Output Files
    FILE *input_fp = fopen(input_file, "rb");
    FILE *output_fp = fopen(output_file, "wb");
    if (input_fp == NULL || output_fp == NULL) {
        print_error("Error opening files.");
        return -1;
    }

    // Create Decryption Context
    AES_KEY aes_key_ctx;
    if (AES_set_decrypt_key(aes_key, AES_KEY_LEN * 8, &aes_key_ctx) != 0) {
        print_error("Error setting AES decryption key.");
        return -1;
    }

    // Read Input File and Decrypt
    size_t read_size;
    unsigned char input_buffer[AES_BLOCK_LEN];
    unsigned char output_buffer[AES_BLOCK_LEN];
    while ((read_size = fread(input_buffer, 1, AES_BLOCK_LEN, input_fp)) > 0) {
        // Decrypt Block
        AES_ecb_encrypt(input_buffer, output_buffer, &aes_key_ctx, DECRYPT_MODE);
        // Remove Padding
        if (read_size < AES_BLOCK_LEN) {
            for (int i = read_size; i < AES_BLOCK_LEN; i++) {
                if (output_buffer[i] != 0) {
                    print_error("Invalid padding detected.");
                    return -1;
                }
            }
            read_size -= output_buffer[read_size - 1];
        }
        // Write Decrypted Block
        fwrite(output_buffer, 1, read_size, output_fp);
    }

    // Close Files
    fclose(input_fp);
    fclose(output_fp);

    // Wipe Buffers (Paranoia)
    wipe_buffer(input_buffer, AES_BLOCK_LEN);
    wipe_buffer(output_buffer, AES_BLOCK_LEN);

    return 0;
}