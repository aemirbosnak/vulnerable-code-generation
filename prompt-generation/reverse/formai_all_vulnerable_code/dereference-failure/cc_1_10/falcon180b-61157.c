//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} BitArray;

void createBitArray(BitArray *array, int size) {
    array->data = (int *)malloc(size * sizeof(int));
    array->size = size;
    memset(array->data, 0, size * sizeof(int));
}

void setBit(BitArray *array, int index, int value) {
    if (index >= 0 && index < array->size) {
        if (value == 1) {
            array->data[index / 32] |= (1 << (index % 32));
        } else if (value == 0) {
            array->data[index / 32] &= ~(1 << (index % 32));
        }
    }
}

int getBit(BitArray *array, int index) {
    if (index >= 0 && index < array->size) {
        return (array->data[index / 32] & (1 << (index % 32)))? 1 : 0;
    }
    return -1;
}

void printBitArray(BitArray *array) {
    int i, j;
    for (i = 0; i < array->size; i++) {
        for (j = 0; j < 32; j++) {
            printf("%d", getBit(array, i * 32 + j));
        }
        printf("\n");
    }
}

int main() {
    BitArray bitArray1, bitArray2;

    createBitArray(&bitArray1, MAX_SIZE);
    createBitArray(&bitArray2, MAX_SIZE);

    setBit(&bitArray1, 0, 1);
    setBit(&bitArray1, 1, 0);
    setBit(&bitArray1, 2, 1);

    setBit(&bitArray2, 0, 0);
    setBit(&bitArray2, 1, 1);
    setBit(&bitArray2, 2, 0);

    printf("BitArray 1:\n");
    printBitArray(&bitArray1);

    printf("BitArray 2:\n");
    printBitArray(&bitArray2);

    BitArray result;
    createBitArray(&result, MAX_SIZE);

    result.data[0] = bitArray1.data[0] | bitArray2.data[0];
    result.data[1] = bitArray1.data[1] ^ bitArray2.data[1];
    result.data[2] = bitArray1.data[2] & bitArray2.data[2];

    printf("BitArray result:\n");
    printBitArray(&result);

    return 0;
}