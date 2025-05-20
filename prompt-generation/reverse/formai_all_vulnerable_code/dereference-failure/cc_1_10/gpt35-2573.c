//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define GEN_ERR -1
#define SUCCESS 0
#define KEY_LEN 16
#define IV_LEN 16

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        return GEN_ERR;

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return GEN_ERR;

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return GEN_ERR;
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return GEN_ERR;
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        return GEN_ERR;

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return GEN_ERR;

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        return GEN_ERR;
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        return GEN_ERR;
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char *argv[])
{
    // Generate a random key and initialization vector
    unsigned char key[KEY_LEN], iv[IV_LEN];
    RAND_bytes(key, KEY_LEN);
    RAND_bytes(iv, IV_LEN);

    // Define our message and allocate memory for ciphertext and decrypted_message
    char *message = "This is a secret message!";
    int message_len = strlen(message);
    unsigned char *ciphertext = calloc(message_len + EVP_MAX_BLOCK_LENGTH, sizeof(unsigned char));
    unsigned char *decrypted_message = calloc(message_len + EVP_MAX_BLOCK_LENGTH, sizeof(unsigned char));

    // Encrypt the message
    int ciphertext_len = encrypt((unsigned char *)message, message_len, key, iv, ciphertext);
    if(ciphertext_len < GEN_ERR) {
        printf("Encryption failed!\n");
        return GEN_ERR;
    }

    // Print the encrypted message
    printf("Encrypted message: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%x", ciphertext[i]);
    }

    // Decrypt the message
    int decrypted_message_len = decrypt(ciphertext, ciphertext_len, key, iv, decrypted_message);
    if(decrypted_message_len < GEN_ERR) {
        printf("Decryption failed!\n");
        return GEN_ERR;
    }

    // Print the decrypted message
    printf("\nDecrypted message: %s\n", decrypted_message);

    // Free memory
    free(ciphertext);
    free(decrypted_message);

    return SUCCESS;
}