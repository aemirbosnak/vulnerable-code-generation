//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32

typedef struct {
    unsigned char hash[HASH_SIZE];
    int size;
} hash_t;

hash_t *hash_init() {
    hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
    if (hash == NULL) {
        printf("Error: Could not allocate memory for hash\n");
        exit(1);
    }
    memset(hash->hash, 0, HASH_SIZE);
    hash->size = 0;
    return hash;
}

void hash_update(hash_t *hash, const unsigned char *data, int size) {
    if (hash->size + size > HASH_SIZE) {
        printf("Error: Hash buffer overflow\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        hash->hash[hash->size + i] = data[i];
    }
    hash->size += size;
}

void hash_final(hash_t *hash, unsigned char *digest) {
    int padding = HASH_SIZE - hash->size % HASH_SIZE;
    hash_update(hash, (unsigned char *)"\200", padding);
    for (int i = 0; i < HASH_SIZE; i++) {
        sprintf(&digest[i*2], "%02x", hash->hash[i]);
    }
}

void hash_destroy(hash_t *hash) {
    free(hash);
}

int main() {
    hash_t *hash = hash_init();
    hash_update(hash, (unsigned char *)"Hello, world!", 13);
    unsigned char digest[HASH_SIZE*2+1] = {0};
    hash_final(hash, digest);
    printf("Hash: %s\n", digest);
    hash_destroy(hash);
    return 0;
}