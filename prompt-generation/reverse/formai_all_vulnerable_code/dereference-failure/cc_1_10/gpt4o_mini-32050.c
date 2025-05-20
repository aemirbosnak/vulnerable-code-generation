//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <unistd.h>

#define AES_KEYLEN 256
#define AES_BLOCK_SIZE 16
#define BUF_SIZE 1024

typedef struct {
    unsigned char *plaintext;
    int plaintext_len;
    unsigned char *ciphertext;
    unsigned char *key;
    unsigned char *iv;
} CryptoArgs;

void *encrypt(void *args) {
    CryptoArgs *crypto_args = (CryptoArgs *)args;
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        perror("EVP_CIPHER_CTX_new");
        return NULL;
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, crypto_args->key, crypto_args->iv)) {
        perror("EVP_EncryptInit_ex");
        return NULL;
    }

    if (1 != EVP_EncryptUpdate(ctx, crypto_args->ciphertext, &len, crypto_args->plaintext, crypto_args->plaintext_len)) {
        perror("EVP_EncryptUpdate");
        return NULL;
    }
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, crypto_args->ciphertext + len, &len)) {
        perror("EVP_EncryptFinal_ex");
        return NULL;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    printf("Encryption complete.\n");
    return (void *)(intptr_t)ciphertext_len;
}

void *decrypt(void *args) {
    CryptoArgs *crypto_args = (CryptoArgs *)args;
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        perror("EVP_CIPHER_CTX_new");
        return NULL;
    }

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, crypto_args->key, crypto_args->iv)) {
        perror("EVP_DecryptInit_ex");
        return NULL;
    }

    if (1 != EVP_DecryptUpdate(ctx, crypto_args->plaintext, &len, crypto_args->ciphertext, crypto_args->plaintext_len)) {
        perror("EVP_DecryptUpdate");
        return NULL;
    }
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, crypto_args->plaintext + len, &len)) {
        perror("EVP_DecryptFinal_ex");
        return NULL;
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    printf("Decryption complete.\n");
    return (void *)(intptr_t)plaintext_len;
}

int main() {
    unsigned char key[AES_KEYLEN / 8];
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char *plaintext = (unsigned char *)"Hello, this is a test message!";
    unsigned char *ciphertext = (unsigned char *)malloc(BUF_SIZE);
    unsigned char *decryptedtext = (unsigned char *)malloc(BUF_SIZE);
    
    // Generate a random key and IV
    if (!RAND_bytes(key, sizeof(key))) {
        perror("RAND_bytes for key");
        return 1;
    }
    if (!RAND_bytes(iv, sizeof(iv))) {
        perror("RAND_bytes for IV");
        return 1;
    }

    CryptoArgs crypto_args;
    crypto_args.plaintext = plaintext;
    crypto_args.plaintext_len = strlen((char *)plaintext);
    crypto_args.ciphertext = ciphertext;
    crypto_args.key = key;
    crypto_args.iv = iv;

    pthread_t encrypt_thread, decrypt_thread;

    // Encrypting in a separate thread
    pthread_create(&encrypt_thread, NULL, encrypt, (void *)&crypto_args);
    void *ciphertext_len;
    pthread_join(encrypt_thread, &ciphertext_len);

    // Prepare for decryption
    crypto_args.plaintext = decryptedtext;
    crypto_args.plaintext_len = BUF_SIZE;

    // Decrypting in a separate thread
    pthread_create(&decrypt_thread, NULL, decrypt, (void *)&crypto_args);
    void *plaintext_len;
    pthread_join(decrypt_thread, &plaintext_len);

    printf("Ciphertext: ");
    for (int i = 0; i < (intptr_t)ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nDecrypted text: %s\n", decryptedtext);

    free(ciphertext);
    free(decryptedtext);
    return 0;
}