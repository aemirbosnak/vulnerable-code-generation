//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256
#define AES_BLOCK_SIZE 16
#define SALT_LENGTH 16
#define MAX_INPUT_LENGTH 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_salt(unsigned char *salt, int length) {
    if (!RAND_bytes(salt, length)) {
        fprintf(stderr, "Error generating random salt\n");
        exit(EXIT_FAILURE);
    }
}

void encrypt(const unsigned char *plainText, const unsigned char *key, unsigned char *cipherText) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    int len;
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
        handleErrors();

    unsigned char iv[AES_BLOCK_SIZE];
    generate_salt(iv, AES_BLOCK_SIZE); // Generate IV for CBC mode
    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)) 
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, cipherText, &len, plainText, strlen((char *)plainText))) 
        handleErrors();
    
    int cipherTextLen = len;

    if (1 != EVP_EncryptFinal_ex(ctx, cipherText + len, &len)) 
        handleErrors();
    cipherTextLen += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *cipherText, int cipherTextLen, const unsigned char *key, unsigned char *plainText) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    unsigned char iv[AES_BLOCK_SIZE];
    generate_salt(iv, AES_BLOCK_SIZE); // Generate IV for CBC mode
    int len;

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) 
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plainText, &len, cipherText, cipherTextLen)) 
        handleErrors();
    
    int plainTextLen = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plainText + len, &len)) 
        handleErrors();
    plainTextLen += len;

    EVP_CIPHER_CTX_free(ctx);
    plainText[plainTextLen] = '\0'; // Null terminate the decrypted string
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char salt[SALT_LENGTH];
    unsigned char cipherText[MAX_INPUT_LENGTH + AES_BLOCK_SIZE];
    unsigned char plainText[MAX_INPUT_LENGTH];

    printf("Enter encryption key (32 bytes): ");
    scanf("%32s", key);

    generate_salt(salt, SALT_LENGTH); // Just an example, not used directly in encryption

    printf("Enter plain text to encrypt: ");
    char input[MAX_INPUT_LENGTH];
    scanf(" %[^\n]%*c", input); // Read input with spaces

    encrypt((unsigned char *)input, key, cipherText);

    printf("Encrypted text: ");
    for (int i = 0; i < strlen((char *)input); ++i) {
        printf("%02x", cipherText[i]);
    }
    printf("\n");

    decrypt(cipherText, strlen((char *)input), key, plainText);
    printf("Decrypted text: %s\n", plainText);

    return 0;
}