//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 4096

void encrypt_file(const char* input_file, const char* output_file, const char* key, const char* iv) {
    FILE* input_fp = fopen(input_file, "rb");
    FILE* output_fp = fopen(output_file, "wb");

    if (input_fp == NULL || output_fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Error creating cipher context\n");
        exit(1);
    }

    int key_len = strlen(key);
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, iv)!= 1) {
        printf("Error initializing encryption\n");
        exit(1);
    }

    unsigned char in_buffer[BUFFER_SIZE], out_buffer[BUFFER_SIZE + EVP_MAX_IV_LENGTH];
    int out_len, total_read = 0;

    while ((out_len = fread(in_buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        if (EVP_EncryptUpdate(ctx, out_buffer, &out_len, in_buffer, out_len)!= 1) {
            printf("Error encrypting data\n");
            exit(1);
        }

        if (fwrite(out_buffer, 1, out_len, output_fp)!= out_len) {
            printf("Error writing output file\n");
            exit(1);
        }

        total_read += out_len;
    }

    if (EVP_EncryptFinal_ex(ctx, out_buffer, &out_len)!= 1) {
        printf("Error finalizing encryption\n");
        exit(1);
    }

    if (fwrite(out_buffer, 1, out_len, output_fp)!= out_len) {
        printf("Error writing output file\n");
        exit(1);
    }

    fclose(input_fp);
    fclose(output_fp);
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    const char* input_file = "input.txt";
    const char* output_file = "output.enc";
    const char* key = "mysecretkey123";
    const char* iv = "0123456789abcdef";

    encrypt_file(input_file, output_file, key, iv);

    printf("Encryption complete!\n");

    return 0;
}