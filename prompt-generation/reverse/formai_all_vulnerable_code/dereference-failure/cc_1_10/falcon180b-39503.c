//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 256

typedef struct {
    char *data;
    int length;
} HashData;

void hash_init(HashData *hash) {
    hash->data = NULL;
    hash->length = 0;
}

void hash_update(HashData *hash, char *data, int length) {
    hash->data = realloc(hash->data, hash->length + length);
    memcpy(hash->data + hash->length, data, length);
    hash->length += length;
}

void hash_final(HashData *hash, char *digest) {
    char *result = malloc(HASH_SIZE);
    int i, j;

    for (i = 0; i < hash->length; i += HASH_SIZE) {
        memcpy(result, hash->data + i, HASH_SIZE);
        for (j = 0; j < HASH_SIZE; j++) {
            result[j] = result[j] ^ ((j + 1) % HASH_SIZE);
        }
        memcpy(hash->data + i, result, HASH_SIZE);
    }

    hash->data = NULL;
    for (i = 0; i < HASH_SIZE; i++) {
        sprintf(digest + 2 * i, "%02x", (unsigned char)result[i]);
    }
    free(result);
}

int main() {
    HashData hash;
    char digest[2 * HASH_SIZE + 1];

    hash_init(&hash);
    hash_update(&hash, "This is a test message", 18);
    hash_final(&hash, digest);

    printf("Hash: %s\n", digest);

    return 0;
}