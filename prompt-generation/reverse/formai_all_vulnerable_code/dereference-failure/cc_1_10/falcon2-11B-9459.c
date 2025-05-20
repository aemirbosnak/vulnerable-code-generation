//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

void encrypt(const unsigned char *input, int inputLen, unsigned char *output, int *outputLen) {
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *iv = (unsigned char *)"0123456789abcdef";
    unsigned char *ciphertext = (unsigned char *)malloc(inputLen + 16);
    int ciphertextLen = 0;

    EVP_CIPHER_CTX *ctx;
    int rc;

    if ((rc = EVP_EncryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key, iv))!= 1) {
        fprintf(stderr, "EVP_EncryptInit_ex failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    if ((rc = EVP_EncryptUpdate(ctx, ciphertext, &ciphertextLen, input, inputLen))!= 1) {
        fprintf(stderr, "EVP_EncryptUpdate failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    if ((rc = EVP_EncryptFinal_ex(ctx, ciphertext + ciphertextLen, &ciphertextLen))!= 1) {
        fprintf(stderr, "EVP_EncryptFinal_ex failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    free(key);
    free(iv);
    *outputLen = ciphertextLen + 16;
    output = ciphertext;
}

void decrypt(const unsigned char *ciphertext, int ciphertextLen, unsigned char *output, int *outputLen) {
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *iv = (unsigned char *)"0123456789abcdef";
    unsigned char *plaintext = (unsigned char *)malloc(ciphertextLen - 16);
    int plaintextLen = 0;

    EVP_CIPHER_CTX *ctx;
    int rc;

    if ((rc = EVP_DecryptInit_ex(&ctx, EVP_aes_256_cbc(), NULL, key, iv))!= 1) {
        fprintf(stderr, "EVP_DecryptInit_ex failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    if ((rc = EVP_DecryptUpdate(ctx, plaintext, &plaintextLen, ciphertext, ciphertextLen - 16))!= 1) {
        fprintf(stderr, "EVP_DecryptUpdate failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    if ((rc = EVP_DecryptFinal_ex(ctx, plaintext + plaintextLen, &plaintextLen))!= 1) {
        fprintf(stderr, "EVP_DecryptFinal_ex failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        exit(1);
    }

    free(key);
    free(iv);
    *outputLen = plaintextLen;
    output = plaintext;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [input] [output]\n", argv[0]);
        exit(1);
    }

    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(argv[2], "wb");
    unsigned char input[256];
    int inputLen = 0;

    fread(input, 1, 256, in);
    inputLen = fread(input, 1, 256, in);

    unsigned char output[inputLen];
    int outputLen;

    encrypt(input, inputLen, output, &outputLen);
    fwrite(output, 1, outputLen, out);

    decrypt(output, outputLen, input, &inputLen);
    fwrite(input, 1, inputLen, out);

    return 0;
}