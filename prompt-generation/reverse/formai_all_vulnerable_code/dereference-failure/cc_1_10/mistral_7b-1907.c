//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
#define CHECKSUM_SIZE 4

typedef struct {
    uint8_t data[BLOCK_SIZE];
    uint32_t checksum;
} Block;

void calculate_checksum(Block* block) {
    uint32_t sum = 0;
    uint32_t index = 0;

    for (; index < BLOCK_SIZE; index++) {
        sum += block->data[index];
    }

    block->checksum = sum;

    // Brave magic: swap the least and most significant bytes
    sum = ((sum & 0xFF) << 24) |
         ((sum & 0xFF00) >> 8) |
         ((sum & 0xFF0000) >> 16) |
         ((sum >> 24) << 8);

    block->checksum = sum;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    size_t message_length = strlen(argv[1]);
    if (message_length > BLOCK_SIZE) {
        printf("Message too long. Max message size is %d bytes.\n", BLOCK_SIZE);
        return 1;
    }

    Block block;
    memset(&block, 0, sizeof(Block));

    // Store message in the block
    memcpy(block.data, argv[1], message_length);

    // Calculate the checksum
    calculate_checksum(&block);

    // Print the checksum in hexadecimal format
    printf("Checksum: ");
    for (int i = 0; i < CHECKSUM_SIZE * 2; i += 2) {
        printf("%02X", (uint8_t) ((block.checksum >> i) & 0xFF));
    }
    printf("\n");

    return 0;
}