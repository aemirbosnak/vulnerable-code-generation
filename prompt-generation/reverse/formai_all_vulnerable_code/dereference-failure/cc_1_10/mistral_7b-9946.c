//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define PLAINTEXT_SIZE 16
#define KEY_SIZE 16
#define IV_SIZE 16

int main() {
    char plaintext[PLAINTEXT_SIZE] = "This is a secret message!";
    char key[KEY_SIZE];
    char iv[IV_SIZE];
    char ciphertext[PLAINTEXT_SIZE];

    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; ++i)
        printf("%02x", key[i]);
    printf("\n");
    printf("IV: ");
    for (int i = 0; i < IV_SIZE; ++i)
        printf("%02x", iv[i]);
    printf("\n");

    EVP_CIPHER_CTX *ctx;
    int len;

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv);

    len = strlen(plaintext);
    int padding = AES_BLOCK_SIZE - len % AES_BLOCK_SIZE;
    plaintext[len++] = padding;
    plaintext[len] = '\0';

    int encrypted_len = 0;
    EVP_EncryptUpdate(ctx, ciphertext, &encrypted_len, plaintext, len);

    len = strlen(plaintext) + padding;
    memset(plaintext + len, 0, AES_BLOCK_SIZE - len);

    EVP_EncryptFinal_ex(ctx, ciphertext + encrypted_len, &len);

    encrypted_len += len;

    printf("Ciphertext: ");
    for (int i = 0; i < encrypted_len; ++i)
        printf("%02x", ciphertext[i]);
    printf("\n");

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}