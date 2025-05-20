//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16 // 128 bit key size
#define BLOCK_SIZE 16 // AES block size
#define MAX_MSG_SIZE 1024 // Maximum message size

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Generate a random key
    }
}

void xor_blocks(unsigned char *output, const unsigned char *input, const unsigned char *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i]; // Basic XOR operation
    }
}

void encrypt(const unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key) {
    // Simple encryption by XORing with the key (not secure, for demonstration purposes)
    xor_blocks(ciphertext, plaintext, key);
}

void decrypt(const unsigned char *ciphertext, unsigned char *plaintext, unsigned char *key) {
    // Decrypting by XORing back with the same key
    xor_blocks(plaintext, ciphertext, key);
}

void print_hex(const unsigned char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

void safe_input(char *input, size_t size) {
    if (fgets(input, size, stdin) == NULL) {
        perror("Input error");
        exit(EXIT_FAILURE);
    }
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') { 
        input[len - 1] = '\0'; // Remove the newline character
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    unsigned char key[KEY_SIZE];
    generate_key(key); // Generate a random 128-bit key

    printf("Secure Random Key Generated:\n");
    print_hex(key, KEY_SIZE);

    char input[MAX_MSG_SIZE];
    printf("Enter a message to encrypt (max %d characters): ", MAX_MSG_SIZE - 1);
    safe_input(input, MAX_MSG_SIZE);

    size_t input_length = strlen(input);
    
    // Pad input to a multiple of BLOCK_SIZE
    size_t padded_length = ((input_length / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    unsigned char *padded_input = (unsigned char *)calloc(padded_length, sizeof(unsigned char));
    memcpy(padded_input, input, input_length);
    
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char decryptedtext[BLOCK_SIZE];
    
    printf("Encrypting...\n");
    for (size_t i = 0; i < padded_length; i += BLOCK_SIZE) {
        encrypt(padded_input + i, ciphertext, key);
        printf("Ciphertext Block %zu: ", i / BLOCK_SIZE);
        print_hex(ciphertext, BLOCK_SIZE);
    }
    
    printf("\nDecrypting...\n");
    for (size_t i = 0; i < padded_length; i += BLOCK_SIZE) {
        decrypt(ciphertext, decryptedtext, key);
        printf("Decrypted Block %zu: ", i / BLOCK_SIZE);
        print_hex(decryptedtext, BLOCK_SIZE);
    }

    free(padded_input);
    return 0;
}