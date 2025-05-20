//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

// Custom data structure to hold the encryption key and initialization vector (IV)
typedef struct {
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];
} CipherParams;

// Function to generate a random encryption key and IV
CipherParams generate_cipher_params() {
    CipherParams params;
    RAND_bytes(params.key, AES_BLOCK_SIZE);
    RAND_bytes(params.iv, AES_BLOCK_SIZE);
    return params;
}

// Function to encrypt a plaintext string using AES-256 in CBC mode
char *aes_cbc_encrypt(const char *plaintext, const CipherParams *params) {
    // Declare variables
    int len = strlen(plaintext);
    unsigned char *ciphertext = malloc(len + AES_BLOCK_SIZE);
    AES_KEY aes_key;

    // Set up the AES context
    AES_set_encrypt_key(params->key, 256, &aes_key);

    // Encrypt the plaintext in CBC mode
    AES_cbc_encrypt((const unsigned char *)plaintext, ciphertext, len, &aes_key, params->iv, AES_ENCRYPT);

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a ciphertext string using AES-256 in CBC mode
char *aes_cbc_decrypt(const char *ciphertext, const CipherParams *params) {
    // Declare variables
    int len = strlen(ciphertext);
    unsigned char *plaintext = malloc(len);
    AES_KEY aes_key;

    // Set up the AES context
    AES_set_decrypt_key(params->key, 256, &aes_key);

    // Decrypt the ciphertext in CBC mode
    AES_cbc_encrypt((const unsigned char *)ciphertext, plaintext, len, &aes_key, params->iv, AES_DECRYPT);

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Generate a random encryption key and IV
    CipherParams params = generate_cipher_params();

    // Get a plaintext string from the user
    printf("Enter the plaintext to encrypt: ");
    char plaintext[1024];
    fgets(plaintext, 1024, stdin);

    // Encrypt the plaintext
    char *ciphertext = aes_cbc_encrypt(plaintext, &params);

    // Decrypt the ciphertext
    char *decrypted_plaintext = aes_cbc_decrypt(ciphertext, &params);

    // Print the encrypted and decrypted strings
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}