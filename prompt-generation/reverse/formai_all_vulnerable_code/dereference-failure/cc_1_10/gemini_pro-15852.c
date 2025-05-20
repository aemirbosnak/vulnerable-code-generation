//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 16 // in bytes
#define KEY_SIZE 32 // in bytes
#define IV_SIZE 16 // in bytes

// Generate a random IV
void generate_iv(unsigned char *iv)
{
    if (RAND_bytes(iv, IV_SIZE) != 1) {
        perror("RAND_bytes");
        exit(EXIT_FAILURE);
    }
}

// Encrypt the data using AES-256-CBC
void aes_encrypt(unsigned char *plaintext, size_t plaintext_len,
                  unsigned char *key, unsigned char *iv,
                  unsigned char *ciphertext)
{
    AES_KEY aes_key;

    // Set the key
    if (AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key) != 0) {
        perror("AES_set_encrypt_key");
        exit(EXIT_FAILURE);
    }

    // Encrypt the data
    size_t processed = 0;
    while (processed < plaintext_len) {
        AES_cbc_encrypt(plaintext + processed, ciphertext + processed,
                        plaintext_len - processed, &aes_key, iv, AES_ENCRYPT);
        processed += CHUNK_SIZE;
    }
}

// Decrypt the data using AES-256-CBC
void aes_decrypt(unsigned char *ciphertext, size_t ciphertext_len,
                  unsigned char *key, unsigned char *iv,
                  unsigned char *plaintext)
{
    AES_KEY aes_key;

    // Set the key
    if (AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key) != 0) {
        perror("AES_set_decrypt_key");
        exit(EXIT_FAILURE);
    }

    // Decrypt the data
    size_t processed = 0;
    while (processed < ciphertext_len) {
        AES_cbc_encrypt(ciphertext + processed, plaintext + processed,
                        ciphertext_len - processed, &aes_key, iv, AES_DECRYPT);
        processed += CHUNK_SIZE;
    }
}

int main(void)
{
    // Initialize OpenSSL
    if (!EVP_add_cipher(EVP_aes_256_cbc())) {
        perror("EVP_add_cipher");
        exit(EXIT_FAILURE);
    }

    // Generate a random key
    unsigned char key[KEY_SIZE];
    if (RAND_bytes(key, KEY_SIZE) != 1) {
        perror("RAND_bytes");
        exit(EXIT_FAILURE);
    }

    // Generate a random IV
    unsigned char iv[IV_SIZE];
    generate_iv(iv);

    // Plaintext to be encrypted
    char plaintext[] = "This is a secret message.";

    // Encrypted ciphertext
    unsigned char ciphertext[sizeof(plaintext) + CHUNK_SIZE];

    // Encrypt the plaintext
    aes_encrypt((unsigned char *)plaintext, strlen(plaintext), key, iv, ciphertext);

    // Decrypted plaintext
    unsigned char decrypted_plaintext[sizeof(plaintext)];

    // Decrypt the ciphertext
    aes_decrypt(ciphertext, strlen((char *)ciphertext), key, iv, decrypted_plaintext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Clean up
    EVP_cleanup();

    return 0;
}