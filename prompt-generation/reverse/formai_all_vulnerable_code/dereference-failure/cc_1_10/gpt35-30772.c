//FormAI DATASET v1.0 Category: modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFSIZE 1024

void handleErrors(void)
{
    printf("Error occurred!\n");
    abort();
}

int main(int argc, char *argv[])
{
    EVP_CIPHER_CTX *ctx;
    unsigned char key[32], iv[16], outbuf[BUFSIZE], inbuf[BUFSIZE];
    int key_length = 256, iv_length = 128;
    int outlen, inlen;
    int i;

    // Generate random key and iv
    memset(key, 0, 32);
    memset(iv, 0, 16);
    if (!RAND_bytes(key, key_length/8) || !RAND_bytes(iv, iv_length/8)) {
        handleErrors();
    }   

    // Initialize context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        handleErrors();
    }

    // Choose cipher and set key and iv
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        handleErrors();
    }

    // Read input file and encrypt blocks
    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");
    while ((inlen = fread(inbuf, 1, BUFSIZE, input))) {
        if (EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen) != 1) {
            handleErrors();
        }
        fwrite(outbuf, 1, outlen, output);
    }

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, outbuf, &outlen) != 1) {
        handleErrors();
    }
    fwrite(outbuf, 1, outlen, output);

    // Clean up
    fclose(input);
    fclose(output);
    EVP_CIPHER_CTX_free(ctx);

    printf("Encryption successful!\n");

    return 0;
}