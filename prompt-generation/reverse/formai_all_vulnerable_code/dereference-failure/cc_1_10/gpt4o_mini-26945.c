//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    int len;
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    *ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    int len;
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    *plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if(!RAND_bytes(key, 32)) handleErrors(); // 256 bits key
    if(!RAND_bytes(iv, EVP_MAX_IV_LENGTH)) handleErrors(); // IV
}

int main() {
    unsigned char *key = malloc(32); // Key for AES-256
    unsigned char *iv = malloc(EVP_MAX_IV_LENGTH); // IV for AES
    generate_key_and_iv(key, iv);

    unsigned char *plaintext = (unsigned char *)"Hello, World! This is my encryption example. Let's see how it works!";
    unsigned char ciphertext[128];
    int ciphertext_len;

    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext is:\n");
    for(int i = 0; i < ciphertext_len; i++)
        printf("%02x ", ciphertext[i]);
    printf("\n");

    unsigned char decryptedtext[128];
    int decryptedtext_len;

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted text

    printf("Decrypted text is:\n%s\n", decryptedtext);

    free(key);
    free(iv);
    return 0;
}