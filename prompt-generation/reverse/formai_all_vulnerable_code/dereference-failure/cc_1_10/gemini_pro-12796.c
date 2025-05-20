//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define ENCRYPT_KEY "This is a 16-byte key"
#define ENCRYPT_IV "This is a 16-byte IV"

void encrypt(const unsigned char *plaintext, int plaintext_len,
             unsigned char *ciphertext, unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx;
    int ciphertext_len, len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
    {
        fprintf(stderr, "EVP_CIPHER_CTX_new error\n");
        exit(1);
    }

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL,
                                ENCRYPT_KEY, ENCRYPT_IV))
    {
        fprintf(stderr, "EVP_EncryptInit_ex error\n");
        exit(1);
    }

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len,
                              plaintext, plaintext_len))
    {
        fprintf(stderr, "EVP_EncryptUpdate error\n");
        exit(1);
    }

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &len))
    {
        fprintf(stderr, "EVP_EncryptFinal_ex error\n");
        exit(1);
    }

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    memcpy(iv, ciphertext, EVP_CIPHER_iv_length(EVP_aes_128_cbc()));
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len,
             unsigned char *plaintext, const unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx;
    int plaintext_len, len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
    {
        fprintf(stderr, "EVP_CIPHER_CTX_new error\n");
        exit(1);
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL,
                                ENCRYPT_KEY, iv))
    {
        fprintf(stderr, "EVP_DecryptInit_ex error\n");
        exit(1);
    }

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &plaintext_len,
                              ciphertext, ciphertext_len))
    {
        fprintf(stderr, "EVP_DecryptUpdate error\n");
        exit(1);
    }

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &len))
    {
        fprintf(stderr, "EVP_DecryptFinal_ex error\n");
        exit(1);
    }

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char **argv)
{
    unsigned char plaintext[] = "Hello, World!";
    unsigned char ciphertext[256];
    unsigned char iv[EVP_CIPHER_iv_length(EVP_aes_128_cbc())];
    unsigned char decryptedtext[256];

    encrypt(plaintext, strlen((char *)plaintext), ciphertext, iv);

    memcpy(decryptedtext, ciphertext + EVP_CIPHER_iv_length(EVP_aes_128_cbc()),
           strlen((char *)plaintext));
    decryptedtext[strlen((char *)plaintext)] = '\0';

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decryptedtext: %s\n", decryptedtext);

    return 0;
}