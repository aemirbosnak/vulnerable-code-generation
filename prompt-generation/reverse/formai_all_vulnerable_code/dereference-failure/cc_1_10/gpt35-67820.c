//FormAI DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

void print_hex(char *label, uint8_t *data, size_t len) {
    printf("%s: ", label);
    for (size_t i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {

    // Check for correct number of command-line arguments
    if (argc != 4) {
        printf("Usage: %s <key> <iv> <plaintext>\n", argv[0]);
        return 1;
    }

    // Parse command-line arguments
    char *key_hex = argv[1];
    char *iv_hex = argv[2];
    char *plaintext = argv[3];

    // Convert key and IV from hex string to byte array
    uint8_t key[AES_BLOCK_SIZE];
    uint8_t iv[AES_BLOCK_SIZE];
    size_t hex_len = strlen(key_hex);
    for (size_t i = 0; i < hex_len / 2; i++) {
        sscanf(key_hex + 2*i, "%2hhx", &key[i]);
    }
    hex_len = strlen(iv_hex);
    for (size_t i = 0; i < hex_len / 2; i++) {
        sscanf(iv_hex + 2*i, "%2hhx", &iv[i]);
    }

    // Pad plaintext if necessary
    size_t pt_len = strlen(plaintext);
    int num_blocks = (pt_len + BLOCK_SIZE - 1) / BLOCK_SIZE;
    size_t padded_len = num_blocks * BLOCK_SIZE;
    uint8_t *padded_pt = malloc(padded_len);
    memcpy(padded_pt, plaintext, pt_len);
    for (size_t i = pt_len; i < padded_len; i++) {
        padded_pt[i] = padded_len - pt_len;
    }

    // Allocate cipher buffer
    uint8_t *cipher = malloc(padded_len);

    // Initialize AES context in CBC mode
    AES_KEY key_schedule;
    AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &key_schedule);

    // Perform encryption block-by-block
    uint8_t *prev_cipher_block = iv;
    for (int i = 0; i < num_blocks; i++) {
        uint8_t *pt_block = padded_pt + (i * BLOCK_SIZE);
        uint8_t cipher_block[BLOCK_SIZE];
        for (size_t j = 0; j < BLOCK_SIZE; j++) {
            cipher_block[j] = pt_block[j] ^ prev_cipher_block[j];
        }
        AES_encrypt(cipher_block, cipher_block, &key_schedule);
        memcpy(cipher + (i * BLOCK_SIZE), cipher_block, BLOCK_SIZE);
        prev_cipher_block = cipher_block;
    }

    // Print outputs
    print_hex("Key", key, AES_BLOCK_SIZE);
    print_hex("IV", iv, AES_BLOCK_SIZE);
    print_hex("Plaintext", padded_pt, padded_len);
    print_hex("Cipher", cipher, padded_len);

    // Free memory
    free(padded_pt);
    free(cipher);

    return 0;
}