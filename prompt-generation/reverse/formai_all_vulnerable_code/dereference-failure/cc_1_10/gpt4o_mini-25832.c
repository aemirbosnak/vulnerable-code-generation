//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_BLOCK_SIZE 16

void handleErrors() {
    fprintf(stderr, "An error occurred while encrypting/decrypting.\n");
    exit(1);
}

// Function to print the bytes in hexadecimal format
void printHex(const unsigned char *buffer, size_t length) {
    for(size_t i = 0; i < length; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

// Function to encrypt plaintext using AES
void encryptAES(const unsigned char *key, const unsigned char *plaintext, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    if(AES_set_encrypt_key(key, 128, &encryptKey) < 0) {
        handleErrors();
    }

    // Pad plaintext to block size
    int plaintext_len = strlen((char *)plaintext);
    int padding_len = AES_BLOCK_SIZE - (plaintext_len % AES_BLOCK_SIZE);
    unsigned char padded_plaintext[AES_BLOCK_SIZE * ((plaintext_len + padding_len) / AES_BLOCK_SIZE)];
    memcpy(padded_plaintext, plaintext, plaintext_len);
    memset(padded_plaintext + plaintext_len, padding_len, padding_len); // Padding

    // Encrypt
    AES_ecb_encrypt(padded_plaintext, ciphertext, &encryptKey, AES_ENCRYPT);
}

// Function to decrypt the ciphertext using AES
void decryptAES(const unsigned char *key, const unsigned char *ciphertext, unsigned char *plaintext) {
    AES_KEY decryptKey;
    if(AES_set_decrypt_key(key, 128, &decryptKey) < 0) {
        handleErrors();
    }

    AES_ecb_encrypt(ciphertext, plaintext, &decryptKey, AES_DECRYPT);
    
    // Remove padding
    int padding_len = plaintext[AES_BLOCK_SIZE - 1];
    plaintext[AES_BLOCK_SIZE - padding_len] = '\0'; // Null-terminate after removing padding
}

int main() {
    const unsigned char key[16] = "0123456789abcdef"; // 128 bit key
    const unsigned char *plaintext = (unsigned char *)"Hello, World!";
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE + 1];

    printf("Original Plaintext: %s\n", plaintext);
    
    // Encrypt the plaintext
    encryptAES(key, plaintext, ciphertext);
    
    printf("Ciphertext (hex): ");
    printHex(ciphertext, AES_BLOCK_SIZE);
    
    // Decrypt the ciphertext
    decryptAES(key, ciphertext, decryptedtext);
    
    printf("Decrypted Plaintext: %s\n", decryptedtext);
    
    return 0;
}