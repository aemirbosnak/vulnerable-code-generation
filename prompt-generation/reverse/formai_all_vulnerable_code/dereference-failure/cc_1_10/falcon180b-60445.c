//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define BLOCK_SIZE 64

typedef struct {
    unsigned char hash[HASH_SIZE];
    int hashSize;
} Hash;

Hash *hashCreate() {
    Hash *hash = (Hash *)malloc(sizeof(Hash));
    hash->hashSize = 0;
    return hash;
}

void hashUpdate(Hash *hash, const unsigned char *data, int dataSize) {
    SHA256_CTX *ctx = (SHA256_CTX *)hash->hash;

    if (hash->hashSize + dataSize >= BLOCK_SIZE) {
        SHA256_Final(ctx, hash->hash);
        hash->hashSize = 0;
    }

    SHA256_Update(ctx, data, dataSize);
    hash->hashSize += dataSize;
}

void hashFinal(Hash *hash, unsigned char *digest) {
    SHA256_CTX *ctx = (SHA256_CTX *)hash->hash;

    if (hash->hashSize > 0) {
        SHA256_Update(ctx, (unsigned char *)"\200", 1);
        SHA256_Final(ctx, hash->hash);
    }

    memcpy(digest, hash->hash, HASH_SIZE);
}

void hashDestroy(Hash *hash) {
    free(hash);
}

int main() {
    Hash *hash = hashCreate();
    const char *message = "This is a message to hash";
    unsigned char digest[HASH_SIZE];

    hashUpdate(hash, (const unsigned char *)message, strlen(message));
    hashFinal(hash, digest);

    printf("Digest: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    hashDestroy(hash);
    return 0;
}