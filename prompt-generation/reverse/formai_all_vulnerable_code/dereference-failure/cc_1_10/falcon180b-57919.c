//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 64

typedef struct {
    unsigned char data[HASH_SIZE];
    int len;
} hash_t;

void hash_init(hash_t *hash) {
    memset(hash->data, 0, HASH_SIZE);
    hash->len = 0;
}

void hash_update(hash_t *hash, const char *data, int len) {
    hash_t temp_hash;
    int i;

    if (hash->len + len >= HASH_SIZE) {
        memcpy(temp_hash.data, hash->data, HASH_SIZE);
        memcpy(temp_hash.data + HASH_SIZE - hash->len, data, HASH_SIZE - hash->len);
        for (i = 0; i < len - (HASH_SIZE - hash->len); i++) {
            temp_hash.data[HASH_SIZE - hash->len + i] ^= data[i];
        }
        memcpy(hash->data, temp_hash.data, HASH_SIZE);
        hash->len = 0;
    } else {
        memcpy(hash->data + hash->len, data, len);
        hash->len += len;
    }
}

void hash_final(hash_t *hash, char *digest) {
    int i;
    unsigned char padding[HASH_SIZE];
    unsigned char pad_len;

    if (hash->len >= HASH_SIZE - 8) {
        memcpy(padding, hash->data, HASH_SIZE - 8);
        memset(padding + HASH_SIZE - 8, 0x80, 8);
        memcpy(padding + HASH_SIZE - 8, &hash->len, 8);
        hash_update(hash, padding, HASH_SIZE);
    } else {
        memset(padding, 0x80, HASH_SIZE - 1 - hash->len);
        memcpy(padding + HASH_SIZE - 8, &hash->len, 8);
        hash_update(hash, padding, HASH_SIZE);
    }

    memcpy(digest, hash->data, HASH_SIZE);
}

int main() {
    char *message = "The quick brown fox jumps over the lazy dog. ";
    hash_t hash;
    char digest[HASH_SIZE * 2 + 1];

    hash_init(&hash);
    hash_update(&hash, message, strlen(message));
    hash_final(&hash, digest);

    printf("Message: %s\n", message);
    printf("Digest: ");
    for (int i = 0; i < HASH_SIZE * 2; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}