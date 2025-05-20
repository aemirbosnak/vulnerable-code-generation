//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_SIZE 256
#define AES_BLOCK_SIZE 16
#define BUFFER_SIZE 1024

void handleErrors() {
    fprintf(stderr, "An error occurred while processing.\n");
    exit(EXIT_FAILURE);
}

void generate_key(unsigned char* key) {
    if (!RAND_bytes(key, AES_KEY_SIZE / 8)) {
        handleErrors();
    }
}

void encrypt(unsigned char* plaintext, unsigned char* ciphertext, unsigned char* key) {
    AES_KEY encrypt_key;
    if (AES_set_encrypt_key(key, AES_KEY_SIZE, &encrypt_key) < 0) {
        handleErrors();
    }
    
    // Add padding to plaintext
    int len = strlen((char*)plaintext);
    int padded_len = ((len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char* padded_plaintext = (unsigned char*)malloc(padded_len);
    memcpy(padded_plaintext, plaintext, len);
    memset(padded_plaintext + len, 0, padded_len - len);

    for (int i = 0; i < padded_len / AES_BLOCK_SIZE; i++) {
        AES_encrypt(padded_plaintext + (i * AES_BLOCK_SIZE), ciphertext + (i * AES_BLOCK_SIZE), &encrypt_key);
    }
    
    free(padded_plaintext);
}

void decrypt(unsigned char* ciphertext, unsigned char* decryptedtext, unsigned char* key) {
    AES_KEY decrypt_key;
    if (AES_set_decrypt_key(key, AES_KEY_SIZE, &decrypt_key) < 0) {
        handleErrors();
    }

    int num_blocks = BUFFER_SIZE / AES_BLOCK_SIZE;
    
    for(int i = 0; i < num_blocks; i++) {
        AES_decrypt(ciphertext + (i * AES_BLOCK_SIZE), decryptedtext + (i * AES_BLOCK_SIZE), &decrypt_key);
    }
    
    decryptedtext[BUFFER_SIZE] = '\0'; // Null-terminate the decrypted string
}

int main() {
    unsigned char key[AES_KEY_SIZE / 8]; // AES-256 key size
    unsigned char input[BUFFER_SIZE];
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];

    printf("Welcome to the encryption program!\n");
    printf("We are grateful for your interest in secure communications.\n");

    generate_key(key);
    printf("A new encryption key has been generated, thank you!\n");

    printf("Please enter the message you want to encrypt: ");
    fgets((char*)input, BUFFER_SIZE, stdin);
    input[strcspn((char*)input, "\n")] = 0; // Remove trailing newline

    encrypt(input, ciphertext, key);
    printf("Your message has been encrypted successfully.\n");

    decrypt(ciphertext, decryptedtext, key);
    printf("And now, we shall decrypt your message:\n");
    printf("Decrypted Message: %s\n", decryptedtext);

    printf("Thank you for using our program. Stay secure!\n");
    return 0;
}