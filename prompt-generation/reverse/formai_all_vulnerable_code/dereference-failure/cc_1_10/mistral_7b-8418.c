//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: rigorous
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define WORD_SIZE 4
#define BLOCK_SIZE (sizeof(uint32_t) * WORD_SIZE)
#define ROUNDS 4

typedef struct {
    uint32_t state[WORD_SIZE];
} SimpleHashContext;

void SimpleHashTransform(SimpleHashContext *context, const uint32_t *block) {
    for (int i = 0; i < WORD_SIZE; i++) {
        uint32_t a = context->state[i];
        uint32_t b = block[i];
        context->state[i] = a + b + (a << 5) + 0x5a827999;
    }
}

void SimpleHashUpdate(SimpleHashContext *context, const void *data, size_t length) {
    const uint8_t *buffer = data;
    size_t remaining = length;
    uint32_t partial = 0;

    while (remaining >= BLOCK_SIZE) {
        uint32_t block[WORD_SIZE];
        memcpy(block, buffer, sizeof(block));
        SimpleHashTransform(context, block);
        buffer += BLOCK_SIZE;
        remaining -= BLOCK_SIZE;
    }

    if (remaining) {
        memcpy(&partial, buffer, remaining);
    }

    if (partial) {
        uint32_t padded_block[WORD_SIZE + 1];
        memcpy(padded_block, context->state, sizeof(context->state));
        padded_block[WORD_SIZE] = 0x80;
        uint32_t len_bits = ((length * 8) & 0xFFFFFFFF00000000) | (remaining * 8);
        padded_block[WORD_SIZE + 1] = len_bits;

        for (int i = 0; i < ROUNDS; i++) {
            SimpleHashTransform(context, padded_block);
        }

        memcpy(context->state, padded_block, sizeof(context->state));
    }
}

void SimpleHashInit(SimpleHashContext *context) {
    memset(context->state, 0, sizeof(context->state));
}

void SimpleHashFinal(SimpleHashContext *context, uint8_t *digest) {
    uint32_t padded_block[WORD_SIZE + 1];

    for (int i = 0; i < ROUNDS; i++) {
        SimpleHashUpdate(context, context->state, sizeof(context->state));
    }

    memcpy(padded_block, context->state, sizeof(context->state));
    padded_block[WORD_SIZE] = 0x80;
    uint32_t len_bits = ((sizeof(context->state) * 8) & 0xFFFFFFFF00000000) | (sizeof(context->state) * 8);
    padded_block[WORD_SIZE + 1] = len_bits;

    for (int i = 0; i < ROUNDS; i++) {
        SimpleHashTransform(context, padded_block);
    }

    memcpy(digest, padded_block, sizeof(padded_block));
}

int main() {
    const char *input = "Hello, World!";
    SimpleHashContext context;
    uint8_t digest[sizeof(context.state)];

    SimpleHashInit(&context);
    SimpleHashUpdate(&context, input, strlen(input));
    SimpleHashFinal(&context, digest);

    for (int i = 0; i < sizeof(digest); i++) {
        printf("%02X", digest[i]);
    }

    return 0;
}