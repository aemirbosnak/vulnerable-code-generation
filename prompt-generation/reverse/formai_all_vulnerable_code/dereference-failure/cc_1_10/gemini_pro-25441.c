//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a set of bits.
typedef struct {
    unsigned char *bits;
    size_t size;
} bitset_t;

// Create a new bitset with the given size.
bitset_t *bitset_new(size_t size) {
    bitset_t *bitset = malloc(sizeof(bitset_t));
    if (!bitset) {
        return NULL;
    }

    bitset->bits = calloc(size, sizeof(unsigned char));
    if (!bitset->bits) {
        free(bitset);
        return NULL;
    }

    bitset->size = size;

    return bitset;
}

// Destroy the given bitset.
void bitset_destroy(bitset_t *bitset) {
    free(bitset->bits);
    free(bitset);
}

// Set the bit at the given index to 1.
void bitset_set(bitset_t *bitset, size_t index) {
    if (index >= bitset->size) {
        return;
    }

    bitset->bits[index / 8] |= (1 << (index % 8));
}

// Clear the bit at the given index to 0.
void bitset_clear(bitset_t *bitset, size_t index) {
    if (index >= bitset->size) {
        return;
    }

    bitset->bits[index / 8] &= ~(1 << (index % 8));
}

// Toggle the bit at the given index (0 -> 1, 1 -> 0).
void bitset_toggle(bitset_t *bitset, size_t index) {
    if (index >= bitset->size) {
        return;
    }

    bitset->bits[index / 8] ^= (1 << (index % 8));
}

// Return the value of the bit at the given index.
int bitset_get(bitset_t *bitset, size_t index) {
    if (index >= bitset->size) {
        return -1;
    }

    return (bitset->bits[index / 8] & (1 << (index % 8))) != 0;
}

// Print the bitset to the console.
void bitset_print(bitset_t *bitset) {
    for (size_t i = 0; i < bitset->size; i++) {
        printf("%d", bitset_get(bitset, i));
    }

    printf("\n");
}

// A simple example of using the bitset API.
int main() {
    // Create a new bitset with 10 bits.
    bitset_t *bitset = bitset_new(10);

    // Set the 3rd and 7th bits.
    bitset_set(bitset, 2);
    bitset_set(bitset, 6);

    // Print the bitset.
    bitset_print(bitset); // Output: 0000101000

    // Clear the 3rd bit.
    bitset_clear(bitset, 2);

    // Print the bitset again.
    bitset_print(bitset); // Output: 0000100000

    // Toggle the 5th bit.
    bitset_toggle(bitset, 4);

    // Print the bitset again.
    bitset_print(bitset); // Output: 0000101010

    // Destroy the bitset.
    bitset_destroy(bitset);

    return 0;
}