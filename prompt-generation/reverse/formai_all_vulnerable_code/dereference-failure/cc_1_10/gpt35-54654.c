//FormAI DATASET v1.0 Category: modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 256 // AES-256
#define BLOCK_SIZE 16 // AES operates on 16-byte blocks

void print_hex(const unsigned char *string) {
    for (int i = 0; i < strlen((const char *)string); i++) {
        printf("%02x ", string[i]);
    }
    printf("\n");
}

int main() {
    // Input plaintext
    unsigned char plaintext[] = "Hello, world! This is a secret message.";
    printf("Plaintext: \"%s\"\n", plaintext);
    printf("Plaintext (hex): ");
    print_hex(plaintext);

    // Generate AES key
    unsigned char key[KEY_SIZE / 8];
    if (!RAND_bytes(key, sizeof(key))) {
        perror("Error generating AES key");
        return EXIT_FAILURE;
    }
    printf("AES key (hex): ");
    print_hex(key);

    // Encrypt
    unsigned char iv[BLOCK_SIZE]; // Initialization vector (IV) for CBC mode
    if (!RAND_bytes(iv, sizeof(iv))) {
        perror("Error generating IV");
        return EXIT_FAILURE;
    }
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, KEY_SIZE, &aes_key) != 0) {
        perror("Error setting AES encryption key");
        return EXIT_FAILURE;
    }
    unsigned char ciphertext[sizeof(plaintext)];
    AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &aes_key, iv, AES_ENCRYPT);
    printf("Ciphertext (hex): ");
    print_hex(ciphertext);

    // Decrypt
    unsigned char decrypted[sizeof(plaintext)];
    AES_set_decrypt_key(key, KEY_SIZE, &aes_key);
    AES_cbc_encrypt(ciphertext, decrypted, sizeof(ciphertext), &aes_key, iv, AES_DECRYPT);
    printf("Decrypted: \"%s\"\n", decrypted);

    return EXIT_SUCCESS;
}