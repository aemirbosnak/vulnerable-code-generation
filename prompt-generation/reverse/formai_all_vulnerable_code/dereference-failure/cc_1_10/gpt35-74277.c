//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define CHUNK_SIZE 1024

void print_hex(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", buf[i]);
    }
}

void encrypt(const char *plaintext, const char *key, const unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: EVP_CIPHER_CTX_new() failed\n");
        exit(EXIT_FAILURE);
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, iv)) {
        fprintf(stderr, "Error: EVP_EncryptInit_ex() failed\n");
        exit(EXIT_FAILURE);
    }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char *)plaintext, strlen(plaintext))) {
        fprintf(stderr, "Error: EVP_EncryptUpdate() failed\n");
        exit(EXIT_FAILURE);
    }

    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Error: EVP_EncryptFinal_ex() failed\n");
        exit(EXIT_FAILURE);
    }

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    printf("Plaintext: %s\n", plaintext);
    printf("Key:       %s\n", key);
    printf("IV:        ");
    print_hex((unsigned char *)iv, EVP_CIPHER_iv_length(EVP_aes_256_cbc()));
    printf("\n");
    printf("Ciphertext (hex):  ");
    print_hex(ciphertext, ciphertext_len);
    printf("\n");
}

void decrypt(const unsigned char *ciphertext, const char *key, const unsigned char *iv, char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int plaintext_len;
    int len;
    int ciphertext_len;

    ciphertext_len = strlen(ciphertext);

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: EVP_CIPHER_CTX_new() failed\n");
        exit(EXIT_FAILURE);
    }

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, iv)) {
        fprintf(stderr, "Error: EVP_DecryptInit_ex() failed\n");
        exit(EXIT_FAILURE);
    }

    if (1 != EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &len, ciphertext, ciphertext_len)) {
        fprintf(stderr, "Error: EVP_DecryptUpdate() failed\n");
        exit(EXIT_FAILURE);
    }

    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext + len, &len)) {
        fprintf(stderr, "Error: EVP_DecryptFinal_ex() failed\n");
        exit(EXIT_FAILURE);
    }

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    plaintext[plaintext_len] = '\0';

    printf("Ciphertext (hex):  ");
    print_hex((unsigned char *)ciphertext, ciphertext_len);
    printf("\n");
    printf("Key:              %s\n", key);
    printf("IV:               ");
    print_hex((unsigned char *)iv, EVP_CIPHER_iv_length(EVP_aes_256_cbc()));
    printf("\n");
    printf("Plaintext:        %s\n", plaintext);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <key> <iv> <plaintext or ciphertext>\n", argv[0]);
        return 1;
    }

    const char *key = argv[1];
    const unsigned char *iv = (const unsigned char *)argv[2];
    const char *input = argv[3];

    if (strlen(input) >= CHUNK_SIZE) {
        fprintf(stderr, "Error: input is too large\n");
        return 1;
    }

    char *plaintext = malloc(CHUNK_SIZE);
    unsigned char *ciphertext = malloc(CHUNK_SIZE);

    if (!plaintext || !ciphertext) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        return 1;
    }

    if (isxdigit(*input)) {
        // input is ciphertext
        sscanf(input, "%2hhx", &ciphertext[0]);

        for (int i = 1; i < strlen(input) - 1; i += 2) {
            sscanf(&input[i], "%2hhx", &ciphertext[i / 2]);
        }

        decrypt(ciphertext, key, iv, plaintext);
    } else {
        // input is plaintext
        encrypt(input, key, iv, ciphertext);
    }

    free(plaintext);
    free(ciphertext);

    return 0;
}