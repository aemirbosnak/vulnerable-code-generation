//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Key and IV
unsigned char key[] = "0123456789abcdef";
unsigned char iv[] = "abcdef0123456789";

// Encryption function
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char **ciphertext, int *ciphertext_len)
{
    EVP_CIPHER_CTX *ctx;
    int outlen;

    *ciphertext = malloc(plaintext_len + EVP_CIPHER_CTX_block_size(EVP_aes_128_cbc()));
    if (*ciphertext == NULL)
        return -1;

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL)
        return -1;

    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
        return -1;

    if (EVP_EncryptUpdate(ctx, *ciphertext, &outlen, plaintext, plaintext_len) != 1)
        return -1;

    if (EVP_EncryptFinal_ex(ctx, *ciphertext + outlen, &outlen) != 1)
        return -1;

    *ciphertext_len = outlen;

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

// Decryption function
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char **plaintext, int *plaintext_len)
{
    EVP_CIPHER_CTX *ctx;
    int outlen;

    *plaintext = malloc(ciphertext_len + EVP_CIPHER_CTX_block_size(EVP_aes_128_cbc()));
    if (*plaintext == NULL)
        return -1;

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL)
        return -1;

    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
        return -1;

    if (EVP_DecryptUpdate(ctx, *plaintext, &outlen, ciphertext, ciphertext_len) != 1)
        return -1;

    if (EVP_DecryptFinal_ex(ctx, *plaintext + outlen, &outlen) != 1)
        return -1;

    *plaintext_len = outlen;

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}

int main()
{
    unsigned char *plaintext = "Hello, world!";
    unsigned char *ciphertext;
    int plaintext_len = strlen(plaintext);
    int ciphertext_len;
    int ret;

    // Encryption
    ret = encrypt(plaintext, plaintext_len, &ciphertext, &ciphertext_len);
    if (ret != 0)
        return -1;

    // Decryption
    ret = decrypt(ciphertext, ciphertext_len, &plaintext, &plaintext_len);
    if (ret != 0)
        return -1;

    // Print result
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    free(ciphertext);
    free(plaintext);

    return 0;
}