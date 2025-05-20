//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred\n");
    exit(1);
}

int main(void)
{
    printf("Enter the text to encrypt: ");
    char *text = NULL;
    size_t text_size;
    getline(&text, &text_size, stdin);

    // Initialize the library
    OpenSSL_add_all_algorithms();
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher;
    unsigned char *ciphertext;
    int ciphertext_len;

    cipher = EVP_get_cipherbyname("aes-256-cbc");
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx || !cipher)
    {
        handleErrors();
    }

    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";
    if (EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv) != 1)
    {
        handleErrors();
    }

    ciphertext = malloc(strlen(text) + EVP_CIPHER_block_size(cipher));
    if (!ciphertext)
    {
        handleErrors();
    }

    // Encrypt the data
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *)text, strlen(text)) != 1)
    {
        handleErrors();
    }

    int final_len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &final_len) != 1)
    {
        handleErrors();
    }
    ciphertext_len += final_len;

    EVP_CIPHER_CTX_free(ctx);
    printf("Encrypted text: ");
    for (int i = 0; i < ciphertext_len; i++)
    {
        printf("%02x", ciphertext[i]);
    }

    // Now decrypt the data
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
    {
        handleErrors();
    }

    if (EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv) != 1)
    {
        handleErrors();
    }

    unsigned char *plaintext = malloc(ciphertext_len + EVP_CIPHER_block_size(cipher));
    if (!plaintext)
    {
        handleErrors();
    }

    int decrypted_len;
    if (EVP_DecryptUpdate(ctx, plaintext, &decrypted_len, ciphertext, ciphertext_len) != 1)
    {
        handleErrors();
    }

    if (EVP_DecryptFinal_ex(ctx, plaintext + decrypted_len, &final_len) != 1)
    {
        handleErrors();
    }
    decrypted_len += final_len;

    EVP_CIPHER_CTX_free(ctx);

    printf("\nDecrypted text: ");
    printf("%s", plaintext);

    free(ciphertext);
    free(plaintext);

    return 0;
}