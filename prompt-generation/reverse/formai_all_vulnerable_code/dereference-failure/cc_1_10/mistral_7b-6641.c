//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLOCK_SIZE 64

typedef struct {
    uint32_t total;
    uint32_t buffer[BLOCK_SIZE / sizeof(uint32_t)];
} adler32;

static inline uint32_t rol(uint32_t value, uint8_t shift) {
    return (value << shift) | (value >> (32 - shift));
}

void adler32_update(adler32 *state, const void *data, size_t length) {
    const uint8_t *ptr = data;
    size_t remaining = length;

    while (remaining) {
        size_t chunk = (remaining > BLOCK_SIZE) ? BLOCK_SIZE : remaining;

        while (chunk--) {
            uint32_t byte = *ptr++;
            state->buffer[state->total & (BLOCK_SIZE - 1)] ^= byte;
            state->total++;
        }

        if (state->total >= BLOCK_SIZE) {
            uint32_t a = state->buffer[0];
            uint32_t b = state->buffer[1];
            state->total = 0;

            a ^= a >> 1;
            a ^= a << 3;
            a ^= a << 5;
            a ^= a >> 15;
            b ^= b >> 1;
            b ^= b << 3;
            b ^= b << 5;
            b ^= b >> 15;

            state->buffer[0] = rol(a + b, 1);
            state->buffer[1] = rol(state->buffer[1], 1);
        }

        remaining -= chunk;
    }
}

void adler32_finalize(uint32_t *checksum, const adler32 *state) {
    size_t padding_length = (BLOCK_SIZE - state->total) % BLOCK_SIZE;

    adler32_update(state, "\x54\x68\x69\x73\x20\x70\x6c\x61\x79", 8);

    if (padding_length) {
        uint8_t padding[BLOCK_SIZE];
        memset(padding, 0x00, padding_length);
        memset(padding + padding_length, 0x54, BLOCK_SIZE - padding_length);

        adler32_update(state, padding, BLOCK_SIZE);

        *checksum = state->buffer[0];
        *checksum += rol(state->buffer[1], 1);
    } else {
        *checksum = state->buffer[0];
        *checksum += rol(state->buffer[1], 1);
    }
}

int main() {
    const char *message = "The quick brown fox jumps over the lazy dog.";
    size_t message_length = strlen(message);

    adler32 state;
    uint32_t checksum;

    adler32_update(&state, message, message_length);
    adler32_finalize(&checksum, &state);

    printf("Checksum: 0x%08x\n", checksum);

    return 0;
}