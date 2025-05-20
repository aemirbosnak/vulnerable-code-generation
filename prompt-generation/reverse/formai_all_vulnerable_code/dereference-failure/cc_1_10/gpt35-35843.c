//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024
#define SHA256_DIGEST_LENGTH 32

void handleErrors(void)
{
    printf("Error: %s\n", ERR_error_string(ERR_get_error(), NULL));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <plaintext>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *plaintext = argv[1];
    size_t plaintext_len = strlen(plaintext);

    unsigned char md[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();

    if (!mdctx) {
        handleErrors();
    }

    if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
        handleErrors();
    }

    if (1 != EVP_DigestUpdate(mdctx, (const void *)plaintext, plaintext_len)) {
        handleErrors();
    }

    if (1 != EVP_DigestFinal_ex(mdctx, md, NULL)) {
        handleErrors();
    }

    EVP_MD_CTX_free(mdctx);

    printf("Plaintext: %s\n", plaintext);
    printf("SHA256 hash: ");
    for (size_t i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}