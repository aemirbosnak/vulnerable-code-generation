//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32

typedef struct {
    unsigned char hash[HASH_SIZE];
    int hash_size;
} Hash;

Hash* hash_create() {
    Hash* hash = malloc(sizeof(Hash));
    hash->hash_size = HASH_SIZE;
    for (int i = 0; i < HASH_SIZE; i++) {
        hash->hash[i] = 0;
    }
    return hash;
}

void hash_update(Hash* hash, unsigned char* data, int data_len) {
    for (int i = 0; i < data_len; i++) {
        hash->hash[i % HASH_SIZE] ^= data[i];
    }
}

void hash_final(Hash* hash, unsigned char* digest) {
    for (int i = 0; i < HASH_SIZE; i++) {
        sprintf(&digest[i * 2], "%02x", hash->hash[i]);
    }
}

int main() {
    Hash* hash = hash_create();
    unsigned char* message = "This is a test message.";
    int message_len = strlen(message);

    hash_update(hash, (unsigned char*)message, message_len);
    unsigned char digest[HASH_SIZE * 2 + 1];
    hash_final(hash, digest);

    printf("Message: %s\n", message);
    printf("Digest:  ");
    for (int i = 0; i < HASH_SIZE * 2; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}