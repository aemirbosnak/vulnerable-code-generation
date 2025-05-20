//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256 // AES key size in bits
#define AES_BLOCK_SIZE 16 // AES block size in bytes
#define IV_SIZE AES_BLOCK_SIZE // Initialization Vector size

// Function to handle errors
void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

// Function to encrypt plaintext using AES
void aes_encrypt(const uint8_t *key, const uint8_t *plaintext, uint8_t *ciphertext, const uint8_t *iv) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &encryptKey) < 0) {
        handleErrors();
    }

    // Perform AES encryption in CBC mode
    AES_cbc_encrypt(plaintext, ciphertext, AES_BLOCK_SIZE, &encryptKey, iv, AES_ENCRYPT);
}

// Function to decrypt ciphertext using AES
void aes_decrypt(const uint8_t *key, const uint8_t *ciphertext, uint8_t *plaintext, const uint8_t *iv) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &decryptKey) < 0) {
        handleErrors();
    }

    // Perform AES decryption in CBC mode
    AES_cbc_encrypt(ciphertext, plaintext, AES_BLOCK_SIZE, &decryptKey, iv, AES_DECRYPT);
}

// Function to generate a random AES key
void generate_random_key(uint8_t *key, int key_size) {
    if (!RAND_bytes(key, key_size)) {
        handleErrors();
    }
}

// Function to generate a random IV
void generate_random_iv(uint8_t *iv) {
    if (!RAND_bytes(iv, IV_SIZE)) {
        handleErrors();
    }
}

// Function to print bytes in hexadecimal format
void print_hex(const char *desc, const uint8_t *data, size_t len) {
    printf("%s: ", desc);
    for (size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    // Key and IV buffers
    uint8_t key[AES_KEY_SIZE / 8];
    uint8_t iv[IV_SIZE];

    // Generate random AES key and IV
    generate_random_key(key, sizeof(key));
    generate_random_iv(iv);

    // Example plaintext
    const char *plaintext_str = "This is a test message.";
    size_t plaintext_len = strlen(plaintext_str);
    size_t padded_length = ((plaintext_len / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE; // Padding length

    // Allocate buffers for plaintext, ciphertext, and decrypted text
    uint8_t *plaintext = (uint8_t *)malloc(padded_length);
    uint8_t *ciphertext = (uint8_t *)malloc(padded_length);
    uint8_t *decryptedtext = (uint8_t *)malloc(padded_length);

    // Padding plaintext - simple zero padding
    memcpy(plaintext, plaintext_str, plaintext_len);
    memset(plaintext + plaintext_len, 0, padded_length - plaintext_len); // Padding with zeros

    // Print original plaintext
    print_hex("Original Plaintext", plaintext, padded_length);

    // Encrypting the plaintext
    aes_encrypt(key, plaintext, ciphertext, iv);
    print_hex("Ciphertext", ciphertext, padded_length);

    // Decrypting the ciphertext
    aes_decrypt(key, ciphertext, decryptedtext, iv);
    print_hex("Decrypted Text", decryptedtext, padded_length);

    // Print Decrypted Text as string
    printf("Decrypted String: %s\n", decryptedtext);

    // Clean up
    free(plaintext);
    free(ciphertext);
    free(decryptedtext);

    return 0;
}