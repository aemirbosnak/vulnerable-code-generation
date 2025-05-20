//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to encrypt plaintext using AES-256-CBC
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;

    // Create and initialise the context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating context\n");
        return -1;
    }

    // Initialise the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        printf("Error initialising encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Encrypt the plaintext
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) {
        printf("Error encrypting plaintext\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Finalise the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        printf("Error finalising encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return len;
}

// Function to decrypt ciphertext using AES-256-CBC
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;

    // Create and initialise the context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating context\n");
        return -1;
    }

    // Initialise the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        printf("Error initialising decryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Decrypt the ciphertext
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) {
        printf("Error decrypting ciphertext\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Finalise the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) {
        printf("Error finalising decryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return len;
}

// Function to generate a random key and initialisation vector
void generate_key_and_iv(unsigned char *key, unsigned char *iv)
{
    // Generate a random key
    RAND_bytes(key, EVP_CIPHER_key_length(EVP_aes_256_cbc()));

    // Generate a random initialisation vector
    RAND_bytes(iv, EVP_CIPHER_iv_length(EVP_aes_256_cbc()));
}

// Function to print a hex string
void print_hex(unsigned char *str, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%02x", str[i]);
    }
    printf("\n");
}

int main()
{
    // Plaintext to be encrypted
    unsigned char plaintext[] = "I love you more than words can say.";
    int plaintext_len = strlen(plaintext);

    // Key and initialisation vector
    unsigned char key[EVP_CIPHER_key_length(EVP_aes_256_cbc())];
    unsigned char iv[EVP_CIPHER_iv_length(EVP_aes_256_cbc())];

    // Generate a random key and initialisation vector
    generate_key_and_iv(key, iv);

    // Encrypt the plaintext
    unsigned char ciphertext[plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc())];
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: ");
    print_hex(ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    unsigned char decryptedtext[ciphertext_len];
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}