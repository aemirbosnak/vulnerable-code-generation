//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BLOCK_SIZE 16
#define KEY_LENGTH 32

void handleErrors(void)
{
    fprintf(stderr, "Error in cryptography operation\n");
    exit(1);
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char *argv[])
{
    unsigned char *key = (unsigned char *)"0123456789abcdef0123456789abcdef";
    unsigned char *iv = (unsigned char *)"0123456789abcdef";
    unsigned char *plaintext = (unsigned char *)"The quick brown fox jumps over the lazy dog";
    int plaintext_len = strlen((char *)plaintext);

    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(plaintext_len + BLOCK_SIZE);
    if(ciphertext == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the encrypted ciphertext
    printf("Ciphertext:\n");
    for(int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Allocate memory for the decrypted plaintext
    unsigned char *decrypted_plaintext = malloc(ciphertext_len);
    if(decrypted_plaintext == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    // Decrypt the ciphertext
    int decrypted_plaintext_len = decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: ");
    for(int i = 0; i < decrypted_plaintext_len; i++)
        printf("%c", decrypted_plaintext[i]);
    printf("\n");

    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}