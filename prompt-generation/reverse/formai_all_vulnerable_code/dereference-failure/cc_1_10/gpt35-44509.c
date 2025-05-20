//FormAI DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEYSIZE 32
#define IVSIZE 12

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_chacha20_poly1305(), NULL, key, iv)) {
        return -1;
    }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        return -1;
    }
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        return -1;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    if (1 != EVP_DecryptInit_ex(ctx, EVP_chacha20_poly1305(), NULL, key, iv)) {
        return -1;
    }

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        return -1;
    }
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        return -1;
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char *argv[]) {
    unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char) * KEYSIZE);
    unsigned char *iv = (unsigned char *) malloc(sizeof(unsigned char) * IVSIZE);
    unsigned char *plaintext = (unsigned char *)"Hello, World!";
    unsigned char ciphertext[256], decryptedtext[256];
    int decryptedtext_len, ciphertext_len;

    if (RAND_bytes(key, KEYSIZE) != 1) {
        printf("Error generating key\n");
        return -1;
    }

    if (RAND_bytes(iv, IVSIZE) != 1) {
        printf("Error generating iv\n");
        return -1;
    }

    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    printf("Original plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nDecrypted text: %s\n", decryptedtext);

    return 0;
}