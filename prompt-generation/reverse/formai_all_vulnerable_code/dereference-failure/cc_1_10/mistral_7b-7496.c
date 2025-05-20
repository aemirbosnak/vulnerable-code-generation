//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 32

typedef struct {
    uint32_t bits[SIZE / (sizeof(uint32_t) * 8)];
    size_t length;
} BitVector;

BitVector createBitVector() {
    BitVector bv;
    bv.length = 0;
    return bv;
}

void setBit(BitVector* bv, size_t index) {
    size_t byte = index / 8;
    size_t bit = index % 8;

    bv->bits[byte] |= (1 << bit);
    bv->length++;
}

bool getBit(const BitVector* bv, size_t index) {
    size_t byte = index / 8;
    size_t bit = index % 8;

    return (bv->bits[byte] & (1 << bit)) != 0;
}

void printBitVector(const BitVector* bv) {
    for (size_t i = 0; i < bv->length; i++) {
        printf("%d", getBit(bv, i));
    }
    printf("\n");
}

void randomizeBitVector(BitVector* bv, size_t size) {
    srand(time(NULL));

    for (size_t i = 0; i < size; i++) {
        size_t index = rand() % (bv->length);
        setBit(bv, index);
    }
}

int main() {
    BitVector bv = createBitVector();

    printf("Empty BitVector:\n");
    printBitVector(&bv);

    size_t size = SIZE;
    for (size_t i = 0; i < size; i++) {
        setBit(&bv, i);
    }

    printf("BitVector with %d set bits:\n", size);
    printBitVector(&bv);

    printf("Randomly set %d bits:\n", rand() % 10 + 5);
    randomizeBitVector(&bv, rand() % (SIZE - bv.length) + bv.length);
    printBitVector(&bv);

    return 0;
}