//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    char *data;
    int len;
} string_t;

string_t *string_create(const char *data, int len) {
    string_t *s = malloc(sizeof(string_t));
    s->data = malloc(len + 1);
    s->len = len;
    memcpy(s->data, data, len);
    s->data[len] = '\0';
    return s;
}

void string_destroy(string_t *s) {
    free(s->data);
    free(s);
}

void hash_data(SHA256_CTX *ctx, const void *data, size_t len) {
    SHA256_Update(ctx, data, len);
}

void hash_string(SHA256_CTX *ctx, const string_t *s) {
    hash_data(ctx, s->data, s->len);
}

int main() {
    string_t *data1 = string_create("Hello, world!", 13);
    string_t *data2 = string_create("This is a secret message.", 27);

    SHA256_CTX ctx;
    SHA256_Init(&ctx);

    hash_string(&ctx, data1);
    hash_string(&ctx, data2);

    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_Final(digest, &ctx);

    printf("SHA256 hash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    string_destroy(data1);
    string_destroy(data2);

    return 0;
}