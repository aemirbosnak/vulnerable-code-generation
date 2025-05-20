//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);
}

int main(void)
{
    // Initialize input buffer
    const unsigned char *input_data = (const unsigned char *)"Hello, world!";

    // Initialize key and IV
    const unsigned char *key = (const unsigned char *)"1234567890123456";
    const unsigned char *iv = (const unsigned char *)"0123456789012345";

    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Allocate memory for ciphertext buffer
    unsigned char *ciphertext = malloc(strlen(input_data) + EVP_MAX_BLOCK_LENGTH);

    // Initialize encryption context
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize encryption operation with AES-256-CBC
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    // Encrypt data
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, input_data, strlen(input_data))) handleErrors();
    ciphertext_len = len;

    // Finalize encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Print out the ciphertext
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++)
    {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);

    return 0;
}