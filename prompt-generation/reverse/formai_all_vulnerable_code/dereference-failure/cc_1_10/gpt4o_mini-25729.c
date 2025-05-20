//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // You can also use 128 or 192 bits
#define BLOCK_SIZE 16      // AES works with blocks of 16 bytes

void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

// Generate a random AES key
void generateRandomKey(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) {
        handleErrors();
    }
}

// Encrypt plaintext using AES encryption
void aesEncrypt(unsigned char *key, unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &enc_key) < 0) {
        handleErrors();
    }

    // Pad the plaintext to make it a multiple of BLOCK_SIZE
    int len = strlen((char *)plaintext);
    int padding = BLOCK_SIZE - (len % BLOCK_SIZE);
    unsigned char *padded_text = malloc(len + padding);
    if (padded_text == NULL) {
        handleErrors();
    }
    memcpy(padded_text, plaintext, len);
    memset(padded_text + len, padding, padding); // Adding the padding

    // Encrypt the padded text
    for (int i = 0; i < (len + padding) / BLOCK_SIZE; i++) {
        AES_encrypt(padded_text + (i * BLOCK_SIZE), ciphertext + (i * BLOCK_SIZE), &enc_key);
    }

    free(padded_text);
}

// Decrypt ciphertext using AES decryption
void aesDecrypt(unsigned char *key, unsigned char *ciphertext, unsigned char *decrypted) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &dec_key) < 0) {
        handleErrors();
    }

    int num_blocks = strlen((char *)ciphertext) / BLOCK_SIZE;
    for (int i = 0; i < num_blocks; i++) {
        AES_decrypt(ciphertext + (i * BLOCK_SIZE), decrypted + (i * BLOCK_SIZE), &dec_key);
    }

    // Remove padding
    int padding = decrypted[num_blocks * BLOCK_SIZE - 1];
    decrypted[(num_blocks * BLOCK_SIZE) - padding] = '\0'; // Null terminate
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];
    generateRandomKey(key);

    unsigned char plaintext[] = "Curiosity killed the cat, but satisfaction brought it back!";
    unsigned char ciphertext[sizeof(plaintext)];
    unsigned char decrypted[sizeof(plaintext)];

    printf("Original plaintext: %s\n", plaintext);

    aesEncrypt(key, plaintext, ciphertext);
    printf("Encrypted text: ");
    for (size_t i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    aesDecrypt(key, ciphertext, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}