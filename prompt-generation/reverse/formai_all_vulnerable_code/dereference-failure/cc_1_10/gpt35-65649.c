//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* input_file = argv[1];
    const char* output_file = argv[2];
    const char* key = argv[3];

    FILE* file_in = fopen(input_file, "rb");
    if (file_in == NULL) {
        printf("Could not open input file: %s\n", input_file);
        return EXIT_FAILURE;
    }

    FILE* file_out = fopen(output_file, "wb");
    if (file_out == NULL) {
        printf("Could not open output file: %s\n", output_file);
        fclose(file_in);
        return EXIT_FAILURE;
    }

    const EVP_CIPHER* cipher = EVP_aes_256_cbc();
    unsigned char iv[EVP_MAX_IV_LENGTH];
    memset(iv, 0, EVP_MAX_IV_LENGTH);

    unsigned char key_data[MAX_BUFFER_SIZE];
    memset(key_data, 0, MAX_BUFFER_SIZE);
    strncpy(key_data, key, strlen(key));

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx, cipher, NULL, key_data, iv);

    unsigned char in_buffer[MAX_BUFFER_SIZE];
    unsigned char out_buffer[MAX_BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH];
    int in_len = 0;
    int out_len = 0;
    int total_len = 0;

    while ((in_len = fread(in_buffer, 1, MAX_BUFFER_SIZE, file_in)) > 0) {
        if (EVP_EncryptUpdate(ctx, out_buffer, &out_len, in_buffer, in_len) != 1) {
            printf("Encryption failed\n");
            fclose(file_in);
            fclose(file_out);
            EVP_CIPHER_CTX_free(ctx);
            return EXIT_FAILURE;
        }
        fwrite(out_buffer, 1, out_len, file_out);
        total_len += out_len;
    }

    if (EVP_EncryptFinal_ex(ctx, out_buffer, &out_len) != 1) {
        printf("Encryption failed\n");
        fclose(file_in);
        fclose(file_out);
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }
    fwrite(out_buffer, 1, out_len, file_out);
    total_len += out_len;

    fclose(file_in);
    fclose(file_out);
    EVP_CIPHER_CTX_free(ctx);

    printf("Encryption successful. Total bytes written: %d\n", total_len);

    return EXIT_SUCCESS;
}