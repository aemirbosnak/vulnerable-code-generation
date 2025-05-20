//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32

typedef struct {
    unsigned char hash[HASH_SIZE];
    int len;
} hash_t;

hash_t *hash_init() {
    hash_t *hash = (hash_t *)malloc(sizeof(hash_t));
    memset(hash->hash, 0, HASH_SIZE);
    hash->len = 0;
    return hash;
}

void hash_update(hash_t *hash, const unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        hash->hash[hash->len % HASH_SIZE] ^= data[i];
        hash->len++;
    }
}

void hash_final(hash_t *hash, unsigned char *digest) {
    for (int i = 0; i < HASH_SIZE; i++) {
        digest[i] = hash->hash[i];
    }
}

int main() {
    srand(time(NULL));
    hash_t *hash = hash_init();
    const unsigned char *message = "This is a test message.";
    int message_len = strlen((char *)message);

    hash_update(hash, (unsigned char *)message, message_len);
    unsigned char digest[HASH_SIZE];
    hash_final(hash, digest);

    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02X", digest[i]);
    }
    printf("\n");

    free(hash);
    return 0;
}