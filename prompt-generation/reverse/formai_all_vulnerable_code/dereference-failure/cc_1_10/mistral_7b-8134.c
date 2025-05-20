//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BIT_SIZE 32
#define NUM_BITS 64

typedef struct {
    uint32_t data[NUM_BITS / BIT_SIZE];
} BitVector;

void createBitVector(BitVector *bitVector) {
    bitVector->data[0] = 0;
    for (size_t i = 1; i < NUM_BITS / BIT_SIZE; i++) {
        bitVector->data[i] = 0xFFFFFFFF;
    }
}

void setBit(BitVector *bitVector, size_t index) {
    size_t bitIndex = index % BIT_SIZE;
    size_t byteIndex = index / BIT_SIZE;

    bitVector->data[byteIndex] |= (1 << bitIndex);
}

int getBit(const BitVector *bitVector, size_t index) {
    size_t bitIndex = index % BIT_SIZE;
    size_t byteIndex = index / BIT_SIZE;

    uint32_t byte = bitVector->data[byteIndex];
    int bit = (int) (byte >> bitIndex) & 0x1;

    return bit;
}

void printBitVector(const BitVector *bitVector) {
    for (size_t i = 0; i < NUM_BITS / BIT_SIZE; i++) {
        printf("%08X ", bitVector->data[i]);
    }
    printf("\n");
}

int main() {
    BitVector bitVector;
    createBitVector(&bitVector);

    size_t bitIndex = 0;

    for (size_t i = 0; i < NUM_BITS; i += BIT_SIZE) {
        setBit(&bitVector, i);
        if (i % (BIT_SIZE * 4) == 0) {
            printf("Setting bit %llu:\n", i);
            printBitVector(&bitVector);
        }
    }

    printf("Bit 0: %d\n", getBit(&bitVector, 0));
    printf("Bit 33: %d\n", getBit(&bitVector, 33));
    printf("Bit 64: %d\n", getBit(&bitVector, 64));

    return 0;
}