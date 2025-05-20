//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: light-weight
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define NUM_PERMUTATIONS 10

void swap(uint64_t* a, uint64_t* b) {
    uint64_t temp = *a;
    *a = *b;
    *b = temp;
}

void permute(uint64_t* data, int len) {
    for (int i = 0; i < NUM_PERMUTATIONS; i++) {
        for (int j = 0; j < len - 1; j++) {
            int r = rand() % (len - j);
            swap(&data[j], &data[j + r]);
        }
    }
}

uint64_t simhash(const uint8_t* data, size_t length) {
    const size_t block_length = BLOCK_SIZE / 8;
    const size_t num_blocks = (length + block_length - 1) / block_length;

    uint64_t* blocks = malloc(num_blocks * sizeof(uint64_t));

    for (size_t i = 0; i < num_blocks; i++) {
        memcpy(&blocks[i], data + i * block_length, block_length * sizeof(uint8_t));
    }

    permute(blocks, num_blocks);

    uint64_t hash = 0;
    for (size_t i = 0; i < num_blocks; i++) {
        hash ^= blocks[i];
    }

    free(blocks);

    return hash;
}

int main() {
    const uint8_t test_data[] = "This is a test string.";

    size_t test_data_length = sizeof(test_data);

    uint64_t hash = simhash(test_data, test_data_length);

    printf("Hash value: %lx\n", hash);

    return 0;
}