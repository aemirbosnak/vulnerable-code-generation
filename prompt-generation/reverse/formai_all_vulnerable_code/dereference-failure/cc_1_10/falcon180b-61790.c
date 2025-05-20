//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 32
#define HASH_ROUNDS 1000

typedef struct {
    unsigned char hash[HASH_LENGTH];
    int index;
} hash_state;

void hash_init(hash_state* state) {
    state->index = 0;
    memset(state->hash, 0, HASH_LENGTH);
}

void hash_update(hash_state* state, const unsigned char* data, int length) {
    int index = state->index;
    int i;

    for (i = 0; i < length; i++) {
        state->hash[index] ^= data[i];
        index = (index + 1) % HASH_LENGTH;
    }

    state->index = index;
}

void hash_final(hash_state* state, unsigned char* digest) {
    int index = state->index;
    int i;

    for (i = 0; i < HASH_ROUNDS; i++) {
        index = (index + 1) % HASH_LENGTH;

        state->hash[index] ^= state->hash[index - 1];
        state->hash[index - 1] ^= state->hash[index - 2];
        state->hash[index - 2] ^= state->hash[index - 3];
    }

    memcpy(digest, state->hash, HASH_LENGTH);
}

int main() {
    hash_state state;
    unsigned char digest[HASH_LENGTH];
    unsigned char message[] = "Hello, world! ";
    int message_length = strlen(message);

    hash_init(&state);
    hash_update(&state, message, message_length);
    hash_final(&state, digest);

    printf("Message: %s\n", message);
    printf("Digest: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}