//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 64

typedef struct checksum_context {
    uint32_t total;
    uint32_t buffer[BLOCK_SIZE / sizeof(uint32_t)];
} checksum_context;

void checksum_init(checksum_context *ctx) {
    ctx->total = 0;
}

void checksum_update(checksum_context *ctx, const void *data, size_t size) {
    const uint8_t *src = data;
    size_t remaining = size;

    while (remaining) {
        size_t this_block = (remaining > BLOCK_SIZE) ? BLOCK_SIZE : remaining;

        while (this_block--) {
            uint32_t word = *src++;

            ctx->buffer[ctx->total & (BLOCK_SIZE / sizeof(uint32_t) - 1)] += word;
            ctx->total += sizeof(word);
        }

        remaining -= this_block;
    }
}

uint32_t checksum_final(checksum_context *ctx) {
    uint32_t sum = ctx->buffer[0];
    size_t index = 1;

    while (index < BLOCK_SIZE / sizeof(uint32_t)) {
        sum += ctx->buffer[index];
        index++;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum = (sum & 0xFFFF) + ((sum >> 8) & 0xFF);
    sum = (sum & 0xFF) + (sum >> 4);
    sum = (sum << 12) ^ (sum & 0xF);

    return sum;
}

int main(void) {
    const uint8_t test_data[] = {
        0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
        0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF
    };

    checksum_context ctx;
    checksum_init(&ctx);

    checksum_update(&ctx, test_data, sizeof(test_data));

    uint32_t checksum = checksum_final(&ctx);

    printf("Checksum: 0x%08X\n", checksum);

    return EXIT_SUCCESS;
}