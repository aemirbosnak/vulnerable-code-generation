//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void encrypt_file(const char *input_file, const char *output_file, int key_length) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");
    if (!input_fp ||!output_fp) {
        fprintf(stderr, "Error opening file\n");
        return;
    }
    EVP_CIPHER_CTX *ctx;
    unsigned char *key = (unsigned char *)malloc(key_length);
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (!key ||!fread(key, key_length, 1, input_fp) ||!fread(iv, EVP_MAX_IV_LENGTH, 1, input_fp)) {
        fprintf(stderr, "Error reading file\n");
        return;
    }
    if (EVP_EncryptInit(&ctx, EVP_aes_256_cbc(), key, iv)!= 1) {
        fprintf(stderr, "Error initializing cipher\n");
        return;
    }
    char buffer[1024];
    while (fread(buffer, 1, 1024, input_fp) > 0) {
        unsigned char *encrypted_buffer = (unsigned char *)malloc(strlen(buffer) + 1);
        if (!encrypted_buffer) {
            fprintf(stderr, "Out of memory\n");
            return;
        }
        memset(encrypted_buffer, 0, strlen(buffer) + 1);
        if (EVP_EncryptUpdate(&ctx, encrypted_buffer, &encrypted_buffer[strlen(buffer)], buffer, strlen(buffer)) == -1) {
            fprintf(stderr, "Error encrypting data\n");
            return;
        }
        if (fwrite(encrypted_buffer, 1, strlen(encrypted_buffer), output_fp)!= strlen(encrypted_buffer)) {
            fprintf(stderr, "Error writing output\n");
            return;
        }
        free(encrypted_buffer);
    }
    if (fwrite(buffer, 1, strlen(buffer), output_fp)!= strlen(buffer)) {
        fprintf(stderr, "Error writing output\n");
        return;
    }
    if (EVP_EncryptFinal(&ctx, buffer, NULL) == -1) {
        fprintf(stderr, "Error finalizing cipher\n");
        return;
    }
    if (fwrite(buffer, 1, strlen(buffer), output_fp)!= strlen(buffer)) {
        fprintf(stderr, "Error writing output\n");
        return;
    }
    fclose(input_fp);
    fclose(output_fp);
    EVP_CIPHER_CTX_cleanup(&ctx);
    free(key);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s input_file output_file key_length\n", argv[0]);
        return 1;
    }
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int key_length = atoi(argv[3]);
    encrypt_file(input_file, output_file, key_length);
    return 0;
}