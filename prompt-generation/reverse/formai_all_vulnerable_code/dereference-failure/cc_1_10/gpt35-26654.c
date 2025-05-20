//FormAI DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char buffer_in[BUFF_SIZE], buffer_out[BUFF_SIZE + EVP_MAX_BLOCK_LENGTH];
    int inlen, outlen, keylen, ivlen;

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    if (!input) {
        printf("Unable to open input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (!output) {
        printf("Unable to open output file: %s\n", argv[2]);
        fclose(input);
        return EXIT_FAILURE;
    }

    memset(buffer_in, 0, sizeof(buffer_in));
    memset(buffer_out, 0, sizeof(buffer_out));

    keylen = EVP_CIPHER_key_length(EVP_aes_256_cbc());
    ivlen = EVP_CIPHER_iv_length(EVP_aes_256_cbc());

    RAND_bytes(key, keylen);
    RAND_bytes(iv, ivlen);

    // Write the key and iv to the beginning of the output file
    fwrite(key, 1, keylen, output);
    fwrite(iv, 1, ivlen, output);

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    while ((inlen = fread(buffer_in, 1, sizeof(buffer_in), input)) > 0) {
        EVP_EncryptUpdate(ctx, buffer_out, &outlen, buffer_in, inlen);
        fwrite(buffer_out, 1, outlen, output);
    }

    EVP_EncryptFinal_ex(ctx, buffer_out, &outlen);
    fwrite(buffer_out, 1, outlen, output);

    EVP_CIPHER_CTX_free(ctx);

    fclose(input);
    fclose(output);

    printf("Encryption successful!\n");

    return 0;
}