//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY "mysecretkey"
#define ENCRYPTION_BLOCK_SIZE 16

// XOR encryption/decryption function
void xor_encrypt_decrypt(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len) {
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

// Pad data to the nearest multiple of the encryption block size
unsigned char *pad_data(unsigned char *data, size_t data_len, size_t block_size) {
    size_t padded_len = data_len + block_size - (data_len % block_size);
    unsigned char *padded_data = malloc(padded_len);
    memcpy(padded_data, data, data_len);
    for (size_t i = data_len; i < padded_len; i++) {
        padded_data[i] = 0; // Pad with null bytes
    }
    return padded_data;
}

// Remove padding from data
unsigned char *unpad_data(unsigned char *data, size_t data_len, size_t block_size) {
    size_t unpadded_len = data_len - (data_len % block_size);
    unsigned char *unpadded_data = malloc(unpadded_len);
    memcpy(unpadded_data, data, unpadded_len);
    return unpadded_data;
}

// Encrypt data using XOR encryption
unsigned char *encrypt(unsigned char *data, size_t data_len) {
    unsigned char *key = (unsigned char *)ENCRYPTION_KEY;
    size_t key_len = strlen(ENCRYPTION_KEY);
    unsigned char *padded_data = pad_data(data, data_len, ENCRYPTION_BLOCK_SIZE);
    xor_encrypt_decrypt(padded_data, data_len + ENCRYPTION_BLOCK_SIZE - (data_len % ENCRYPTION_BLOCK_SIZE), key, key_len);
    return padded_data;
}

// Decrypt data using XOR encryption
unsigned char *decrypt(unsigned char *data, size_t data_len) {
    unsigned char *key = (unsigned char *)ENCRYPTION_KEY;
    size_t key_len = strlen(ENCRYPTION_KEY);
    xor_encrypt_decrypt(data, data_len, key, key_len);
    return unpad_data(data, data_len, ENCRYPTION_BLOCK_SIZE);
}

int main() {
    char plaintext[] = "This is a secret message.";
    size_t plaintext_len = strlen(plaintext);

    // Encrypt the plaintext
    unsigned char *ciphertext = encrypt((unsigned char *)plaintext, plaintext_len);
    size_t ciphertext_len = plaintext_len + ENCRYPTION_BLOCK_SIZE - (plaintext_len % ENCRYPTION_BLOCK_SIZE);

    // Decrypt the ciphertext
    unsigned char *decryptedtext = decrypt(ciphertext, ciphertext_len);
    size_t decryptedtext_len = ciphertext_len - ENCRYPTION_BLOCK_SIZE;

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}