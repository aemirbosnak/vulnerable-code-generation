//FormAI DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 128

// Encrypts input data with a given key
unsigned char* encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, int key_len, int* ciphertext_len)
{
    unsigned char* iv = (unsigned char*) malloc(BLOCK_SIZE/8);

    if (RAND_bytes(iv, BLOCK_SIZE/8) <= 0) {
        return NULL;
    }

    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, key_len, &aes_key) < 0) {
        return NULL;
    }

    int cipher_len = (plaintext_len/BLOCK_SIZE + 1) * BLOCK_SIZE;
    unsigned char* ciphertext = (unsigned char*) malloc(cipher_len);

    *ciphertext_len = 0;
    int bytes_processed = 0;

    while (bytes_processed < plaintext_len) {
        unsigned char* block = plaintext + bytes_processed;

        AES_cbc_encrypt(block, ciphertext + bytes_processed, BLOCK_SIZE, &aes_key, iv, AES_ENCRYPT);

        bytes_processed += BLOCK_SIZE;
    }

    *ciphertext_len = bytes_processed;

    free(iv);

    return ciphertext;
}

// Decrypts input ciphertext with a given key
unsigned char* decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, int key_len, int* plaintext_len)
{
    unsigned char* iv = (unsigned char*) malloc(BLOCK_SIZE/8);

    if (RAND_bytes(iv, BLOCK_SIZE/8) <= 0) {
        return NULL;
    }

    AES_KEY aes_key;
    if (AES_set_decrypt_key(key, key_len, &aes_key) < 0) {
        return NULL;
    }

    int plain_len = (ciphertext_len/BLOCK_SIZE + 1) * BLOCK_SIZE;
    unsigned char* plaintext = (unsigned char*) malloc(plain_len);

    *plaintext_len = 0;
    int bytes_processed = 0;

    while (bytes_processed < ciphertext_len) {
        unsigned char* block = ciphertext + bytes_processed;

        AES_cbc_encrypt(block, plaintext + bytes_processed, BLOCK_SIZE, &aes_key, iv, AES_DECRYPT);

        bytes_processed += BLOCK_SIZE;
    }

    *plaintext_len = bytes_processed;

    free(iv);

    return plaintext;
}

int main()
{
    unsigned char key[KEY_SIZE/8];
    unsigned char plaintext[] = "Interoperability is cool!";
    unsigned char* ciphertext = NULL;
    unsigned char* decrypted_text = NULL;
    int ciphertext_len = 0;
    int decrypted_len = 0;

    if (RAND_bytes(key, KEY_SIZE/8) <= 0) {
        printf("Failed to generate a key");
        return -1;
    }

    ciphertext = encrypt(plaintext, strlen((char*) plaintext), key, KEY_SIZE, &ciphertext_len);

    if (!ciphertext) {
        printf("Failed to encrypt the plaintext");
        return -1;
    }

    decrypted_text = decrypt(ciphertext, ciphertext_len, key, KEY_SIZE, &decrypted_len);

    if (!decrypted_text) {
        printf("Failed to decrypt the ciphertext");
        return -1;
    }

    if (strcmp((char*) plaintext, (char*) decrypted_text) == 0) {
        printf("Encryption and decryption was successful!\n");
    } else {
        printf("Encryption and decryption failed!\n");
    }

    free(ciphertext);
    free(decrypted_text);

    return 0;
}