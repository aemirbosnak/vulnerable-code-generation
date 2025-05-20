//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Define constants
#define AES_BLOCK_SIZE 16
#define BYTE_TO_HEX_SIZE 2
#define MAX_LINE_LENGTH 1024

// Define functions
int compare_bytes(const void *a, const void *b, size_t len) {
    const unsigned char *aa = (const unsigned char *)a;
    const unsigned char *bb = (const unsigned char *)b;

    for (size_t i = 0; i < len; i++) {
        if (aa[i]!= bb[i])
            return 1;
    }

    return 0;
}

char* encrypt_aes(const char* input, char* output) {
    unsigned char* iv = (unsigned char*)malloc(AES_BLOCK_SIZE);
    unsigned char* key = (unsigned char*)malloc(AES_BLOCK_SIZE);
    unsigned char* data = (unsigned char*)malloc(AES_BLOCK_SIZE);

    memset(iv, 0, AES_BLOCK_SIZE);
    memset(key, 0, AES_BLOCK_SIZE);
    memset(data, 0, AES_BLOCK_SIZE);

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER_CTX_init(&ctx);

    int len = strlen(input);
    int j = 0;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (i % BYTE_TO_HEX_SIZE == 0) {
            if (k == 1) {
                EVP_EncryptInit(&ctx, EVP_aes_256_cbc(), key, iv);
                k = 0;
            } else {
                EVP_EncryptInit(&ctx, EVP_aes_256_cbc(), key, iv);
                k = 1;
            }
        }

        if (i % BYTE_TO_HEX_SIZE == 0 && j % BYTE_TO_HEX_SIZE == 0) {
            EVP_EncryptUpdate(&ctx, data, &data[AES_BLOCK_SIZE], &input[i], BYTE_TO_HEX_SIZE);
            j++;
        }

        data[j] = input[i];
        j++;
    }

    EVP_EncryptFinal(&ctx, data, &data[AES_BLOCK_SIZE]);

    char* hex_data = (char*)malloc(strlen(input) * BYTE_TO_HEX_SIZE * 2 + 1);
    sprintf(hex_data, "%s", data);

    free(iv);
    free(key);
    free(data);

    return hex_data;
}

char* decrypt_aes(const char* input, char* output) {
    unsigned char* iv = (unsigned char*)malloc(AES_BLOCK_SIZE);
    unsigned char* key = (unsigned char*)malloc(AES_BLOCK_SIZE);
    unsigned char* data = (unsigned char*)malloc(AES_BLOCK_SIZE);

    memset(iv, 0, AES_BLOCK_SIZE);
    memset(key, 0, AES_BLOCK_SIZE);
    memset(data, 0, AES_BLOCK_SIZE);

    EVP_CIPHER_CTX* ctx;
    EVP_CIPHER_CTX_init(&ctx);

    int len = strlen(input);
    int j = 0;
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (i % BYTE_TO_HEX_SIZE == 0) {
            if (k == 1) {
                EVP_DecryptInit(&ctx, EVP_aes_256_cbc(), key, iv);
                k = 0;
            } else {
                EVP_DecryptInit(&ctx, EVP_aes_256_cbc(), key, iv);
                k = 1;
            }
        }

        if (i % BYTE_TO_HEX_SIZE == 0 && j % BYTE_TO_HEX_SIZE == 0) {
            EVP_DecryptUpdate(&ctx, data, &data[AES_BLOCK_SIZE], &input[i], BYTE_TO_HEX_SIZE);
            j++;
        }

        data[j] = (unsigned char)strtol(input + i, NULL, 16);
        j++;
    }

    EVP_DecryptFinal(&ctx, data, &data[AES_BLOCK_SIZE]);

    char* hex_data = (char*)malloc(strlen(input) * BYTE_TO_HEX_SIZE * 2 + 1);
    sprintf(hex_data, "%s", data);

    free(iv);
    free(key);
    free(data);

    return hex_data;
}

int main() {
    printf("Enter a string to encrypt: ");
    char* input = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(input, MAX_LINE_LENGTH, stdin);

    printf("Enter a string to decrypt: ");
    char* decrypted_input = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(decrypted_input, MAX_LINE_LENGTH, stdin);

    char* encrypted_output = encrypt_aes(input, NULL);
    char* decrypted_output = decrypt_aes(encrypted_output, NULL);

    if (strcmp(input, decrypted_output) == 0)
        printf("Input and output match.\n");
    else
        printf("Input and output do not match.\n");

    free(input);
    free(decrypted_input);
    free(encrypted_output);
    free(decrypted_output);

    return 0;
}