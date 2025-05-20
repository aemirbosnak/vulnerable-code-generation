//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len;
    char *input;
    size_t input_len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input = argv[1];
    input_len = strlen(input);

    md = EVP_get_digestbyname("sha256");
    if (md == NULL) {
        fprintf(stderr, "EVP_get_digestbyname() failed\n");
        return EXIT_FAILURE;
    }

    mdctx = EVP_MD_CTX_create();
    if (mdctx == NULL) {
        fprintf(stderr, "EVP_MD_CTX_create() failed\n");
        return EXIT_FAILURE;
    }

    if (EVP_DigestInit_ex(mdctx, md, NULL) != 1) {
        fprintf(stderr, "EVP_DigestInit_ex() failed\n");
        return EXIT_FAILURE;
    }

    if (EVP_DigestUpdate(mdctx, input, input_len) != 1) {
        fprintf(stderr, "EVP_DigestUpdate() failed\n");
        return EXIT_FAILURE;
    }

    if (EVP_DigestFinal_ex(mdctx, digest, &digest_len) != 1) {
        fprintf(stderr, "EVP_DigestFinal_ex() failed\n");
        return EXIT_FAILURE;
    }

    EVP_MD_CTX_destroy(mdctx);

    printf("Digest: ");
    for (int i = 0; i < digest_len; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}