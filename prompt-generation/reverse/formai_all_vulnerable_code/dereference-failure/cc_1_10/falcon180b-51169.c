//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 64

typedef struct {
    char* message;
    unsigned char hash[HASH_SIZE];
} hash_t;

void hash_init(hash_t* hash) {
    memset(hash->hash, 0, HASH_SIZE);
}

void hash_update(hash_t* hash, const char* message) {
    strcat(hash->message, message);
}

void hash_final(hash_t* hash) {
    char* message_copy = strdup(hash->message);
    char* salt = "SALT";
    int salt_len = strlen(salt);
    int message_len = strlen(message_copy);
    int i;

    for (i = 0; i < message_len + salt_len; i++) {
        char c = message_copy[i % message_len];
        c ^= salt[i % salt_len];
        hash->hash[i % HASH_SIZE] = (unsigned char)c;
    }

    free(message_copy);
}

void hash_print(hash_t* hash) {
    int i;

    for (i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash->hash[i]);
    }
}

int main() {
    hash_t hash;
    char* message = "Hello, world!";

    hash_init(&hash);
    hash_update(&hash, message);
    hash_final(&hash);
    hash_print(&hash);

    return 0;
}