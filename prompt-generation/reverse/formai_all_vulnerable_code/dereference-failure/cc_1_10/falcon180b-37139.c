//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_LENGTH 32

typedef struct {
    char *data;
    size_t length;
} hash_t;

hash_t *hash_create(const char *data, size_t length) {
    hash_t *hash = malloc(sizeof(hash_t));
    if (hash == NULL) {
        return NULL;
    }
    hash->data = strndup(data, length);
    hash->length = length;
    return hash;
}

void hash_destroy(hash_t *hash) {
    free(hash->data);
    free(hash);
}

char *hash_compute(const hash_t *hash) {
    char *hash_value = malloc(HASH_LENGTH);
    if (hash_value == NULL) {
        return NULL;
    }
    memset(hash_value, 0, HASH_LENGTH);
    for (size_t i = 0; i < hash->length; i++) {
        hash_value[i % HASH_LENGTH] ^= hash->data[i];
    }
    return hash_value;
}

int main() {
    const char *data = "Hello, World!";
    size_t length = strlen(data);
    hash_t *hash = hash_create(data, length);
    if (hash == NULL) {
        printf("Error creating hash.\n");
        return 1;
    }
    char *hash_value = hash_compute(hash);
    if (hash_value == NULL) {
        printf("Error computing hash.\n");
        hash_destroy(hash);
        return 1;
    }
    printf("Hash value: %s\n", hash_value);
    free(hash_value);
    hash_destroy(hash);
    return 0;
}