//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 128 // AES key size in bits
#define AES_BLOCK_SIZE 16 // AES block size in bytes

static void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

// Function to encrypt plaintext
void encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &encryptKey) < 0)
        handleErrors();

    AES_encrypt(plaintext, ciphertext, &encryptKey);
}

// Function to decrypt ciphertext
void decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &decryptKey) < 0)
        handleErrors();

    AES_decrypt(ciphertext, plaintext, &decryptKey);
}

// Function to generate a random AES key
void generateKey(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8)) {
        handleErrors();
    }
}

// Function to print a byte array in hexadecimal form
void printHex(const unsigned char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

// Function to pad the plaintext for AES: PKCS#7 padding
void padPlaintext(unsigned char *input, unsigned char *output, int length) {
    int padding = AES_BLOCK_SIZE - (length % AES_BLOCK_SIZE);
    memcpy(output, input, length);
    memset(output + length, padding, padding);
}

// Function to unpad the plaintext
void unpadPlaintext(unsigned char *input, unsigned char *output, int *length) {
    int padding = input[*length - 1];
    memcpy(output, input, *length - padding);
    *length -= padding;
}

int main() {
    unsigned char key[AES_KEY_SIZE / 8]; // AES key
    unsigned char plaintext[AES_BLOCK_SIZE]; // Input plaintext
    unsigned char ciphertext[AES_BLOCK_SIZE]; // Encrypted output
    unsigned char decryptedtext[AES_BLOCK_SIZE]; // Decrypted output
    unsigned char paddedPlaintext[AES_BLOCK_SIZE]; // Padded plaintext

    // Generate a random AES Key
    generateKey(key);

    // Example plaintext input
    printf("Enter text to encrypt (max 16 chars): ");
    fgets((char *)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // Remove newline character

    // Pad the plaintext
    int plaintextLength = strlen((char *)plaintext);
    if (plaintextLength > AES_BLOCK_SIZE) {
        fprintf(stderr, "Plaintext exceeds the maximum block size of 16 bytes.\n");
        return EXIT_FAILURE;
    }
    padPlaintext(plaintext, paddedPlaintext, plaintextLength);

    // Encrypt the padded plaintext
    encrypt(paddedPlaintext, key, ciphertext);
    printf("Ciphertext in hex: ");
    printHex(ciphertext, AES_BLOCK_SIZE);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    int decryptedLength = AES_BLOCK_SIZE;
    unpadPlaintext(decryptedtext, paddedPlaintext, &decryptedLength);
    printf("Decrypted text: %.*s\n", decryptedLength, paddedPlaintext);

    return EXIT_SUCCESS;
}