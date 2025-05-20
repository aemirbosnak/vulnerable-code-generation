//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

#define SHA256_DIGEST_LENGTH 32

typedef struct HashContext {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA_CTX sha256_ctx;
} HashContext;

void initHash(HashContext *context) {
    SHA256_Init(&(context->sha256_ctx));
}

void updateHash(HashContext *context, const void *data, size_t len) {
    SHA256_Update(&(context->sha256_ctx), data, len);
}

void finalHash(HashContext *context, unsigned char output[SHA256_DIGEST_LENGTH]) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_Final(hash, &(context->sha256_ctx));
    memcpy(output, hash, SHA256_DIGEST_LENGTH);
    SHA256_Init(&(context->sha256_ctx));
}

void hashString(const char *input, unsigned char output[SHA256_DIGEST_LENGTH]) {
    HashContext context;
    initHash(&context);
    updateHash(&context, input, strlen(input));
    finalHash(&context, output);
}

int main() {
    unsigned char input[10] = "Hello, World!";
    unsigned char output[SHA256_DIGEST_LENGTH];

    printf("Input: ");
    for (int i = 0; i < 10; i++)
        printf("%c", input[i]);
    printf("\n");

    hashString((const char *)input, output);

    printf("Hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", output[i]);
    printf("\n");

    return 0;
}