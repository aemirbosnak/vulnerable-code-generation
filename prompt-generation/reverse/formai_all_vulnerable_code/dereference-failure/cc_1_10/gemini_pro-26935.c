//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    EVP_MD_CTX *ctx = EVP_MD_CTX_create();
    if (ctx == NULL) {
        perror("EVP_MD_CTX_create");
        return EXIT_FAILURE;
    }

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), NULL) != 1) {
        perror("EVP_DigestInit_ex");
        return EXIT_FAILURE;
    }

    unsigned char buf[BUFSIZE];
    size_t n;
    while ((n = fread(buf, 1, BUFSIZE, fp)) > 0) {
        if (EVP_DigestUpdate(ctx, buf, n) != 1) {
            perror("EVP_DigestUpdate");
            return EXIT_FAILURE;
        }
    }

    if (ferror(fp)) {
        perror("fread");
        return EXIT_FAILURE;
    }

    fclose(fp);

    unsigned char md[EVP_MAX_MD_SIZE];
    unsigned int mdlen;
    if (EVP_DigestFinal_ex(ctx, md, &mdlen) != 1) {
        perror("EVP_DigestFinal_ex");
        return EXIT_FAILURE;
    }

    EVP_MD_CTX_destroy(ctx);

    for (size_t i = 0; i < mdlen; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}