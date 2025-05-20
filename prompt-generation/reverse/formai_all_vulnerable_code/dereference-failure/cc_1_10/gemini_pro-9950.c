//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8
#define MAX_BITS 256

typedef struct {
    unsigned char *data;
    int num_bits;
} bitset;

bitset *bitset_create(int num_bits) {
    bitset *set = malloc(sizeof(bitset));
    set->data = calloc((num_bits + BITS_PER_BYTE - 1) / BITS_PER_BYTE, sizeof(unsigned char));
    set->num_bits = num_bits;
    return set;
}

void bitset_destroy(bitset *set) {
    free(set->data);
    free(set);
}

int bitset_get(bitset *set, int bit) {
    if (bit < 0 || bit >= set->num_bits) {
        return -1;
    }
    return (set->data[bit / BITS_PER_BYTE] >> (bit % BITS_PER_BYTE)) & 1;
}

void bitset_set(bitset *set, int bit, int value) {
    if (bit < 0 || bit >= set->num_bits) {
        return;
    }
    if (value) {
        set->data[bit / BITS_PER_BYTE] |= 1 << (bit % BITS_PER_BYTE);
    } else {
        set->data[bit / BITS_PER_BYTE] &= ~(1 << (bit % BITS_PER_BYTE));
    }
}

int main() {
    // Create a bitset with 100 bits
    bitset *set = bitset_create(100);

    // Set the 10th bit
    bitset_set(set, 10, 1);

    // Get the 10th bit
    int bit = bitset_get(set, 10);

    // Print the bit
    printf("The 10th bit is %d\n", bit);

    // Destroy the bitset
    bitset_destroy(set);

    return 0;
}