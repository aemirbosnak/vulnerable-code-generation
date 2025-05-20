//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Rotate left macro */
#define ROTL(x, n) ((((uint64_t)x) << n) | (((uint64_t)x) >> (64 - n)))

/* Pseudo-random generation function */
uint64_t prf(uint64_t x, uint64_t y) {
    return ROTL(x, 7) ^ ROTL(y, 13);
}

/* Cryptographic hash function */
void hash(const char* message, size_t length, uint64_t* out) {
    /* Set initial state */
    uint64_t state[4] = { 0xbaadf00d, 0xcafebeef, 0xdeadbeef, 0xdeafbeef };

    /* Pad the message */
    size_t padded_length = ((length + 15) / 16) * 16;
    uint8_t* padded = (uint8_t*)calloc(padded_length, sizeof(uint8_t));
    memcpy(padded, message, length);

    /* Loop through message blocks */
    for (size_t i = 0; i < padded_length; i += 16) {
        /* Parse block */
        uint64_t block[2];
        memcpy(block, &padded[i], 16);

        /* Mix block with state */
        uint64_t x = block[0] ^ state[0];
        uint64_t y = block[1] ^ state[1];
        for (int j = 0; j < 10; j++) {
            uint64_t temp = y;
            y = prf(x, y) ^ state[j % 4];
            x = temp;
        }

        /* Update state */
        for (int j = 0; j < 4; j++) {
            state[j] ^= block[j % 2];
        }
    }

    /* Output hash */
    memcpy(out, state, 4 * sizeof(uint64_t));

    /* Free memory */
    free(padded);
}

int main(void) {
    /* Test input message */
    const char* message = "Hello, world!";

    /* Hash the message */
    uint64_t hashval[4];
    hash(message, strlen(message), hashval);

    /* Print the hash */
    printf("Hash of '%s': 0x%lx%lx%lx%lx\n", message, hashval[0], hashval[1], hashval[2], hashval[3]);

    /* Test empty message */
    hash("", 0, hashval);
    printf("Hash of empty message: 0x%lx%lx%lx%lx\n", hashval[0], hashval[1], hashval[2], hashval[3]);

    return 0;
}