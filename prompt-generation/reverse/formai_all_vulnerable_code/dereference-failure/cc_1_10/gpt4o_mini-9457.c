//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 128 // AES key size 
#define AES_BLOCK_SIZE 16 // AES block size in bytes

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(EXIT_FAILURE);
}

void generate_random_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8)) {
        handleErrors();
    }
}

void aes_encrypt(unsigned char *key, unsigned char *input, unsigned char *output) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &encryptKey) < 0) {
        handleErrors();
    }
    AES_encrypt(input, output, &encryptKey);
}

void aes_decrypt(unsigned char *key, unsigned char *input, unsigned char *output) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &decryptKey) < 0) {
        handleErrors();
    }
    AES_decrypt(input, output, &decryptKey);
}

void print_hex(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}

void encrypt_file(const char *file_path, unsigned char *key) {
    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char encrypted[AES_BLOCK_SIZE];
    
    FILE *input_file = fopen(file_path, "rb");
    if (!input_file) {
        handleErrors();
    }
    
    FILE *output_file = fopen("encrypted.bin", "wb");
    if (!output_file) {
        fclose(input_file);
        handleErrors();
    }

    while (fread(buffer, 1, AES_BLOCK_SIZE, input_file) > 0) {
        aes_encrypt(key, buffer, encrypted);
        fwrite(encrypted, 1, AES_BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(const char *file_path, unsigned char *key) {
    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char decrypted[AES_BLOCK_SIZE];
    
    FILE *input_file = fopen(file_path, "rb");
    if (!input_file) {
        handleErrors();
    }

    FILE *output_file = fopen("decrypted.txt", "wb");
    if (!output_file) {
        fclose(input_file);
        handleErrors();
    }

    while (fread(buffer, 1, AES_BLOCK_SIZE, input_file) > 0) {
        aes_decrypt(key, buffer, decrypted);
        fwrite(decrypted, 1, AES_BLOCK_SIZE, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    unsigned char key[AES_KEY_SIZE / 8];
    generate_random_key(key);

    printf("Generated AES Key: ");
    print_hex(key, sizeof(key));

    // File encryption
    const char *input_file_path = "input.txt"; // Change this to your input file
    encrypt_file(input_file_path, key);
    printf("File encrypted and saved as encrypted.bin\n");

    // File decryption
    decrypt_file("encrypted.bin", key);
    printf("File decrypted and saved as decrypted.txt\n");

    return 0;
}