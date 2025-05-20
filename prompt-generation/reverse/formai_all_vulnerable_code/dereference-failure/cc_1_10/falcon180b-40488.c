//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 1000
#define NUM_BITS 8

typedef struct {
    int size;
    int *data;
} BitArray;

BitArray *createBitArray(int size) {
    BitArray *array = (BitArray *)malloc(sizeof(BitArray));
    if (array == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    array->size = size;
    array->data = (int *)malloc(sizeof(int) * size);
    if (array->data == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        array->data[i] = 0;
    }
    return array;
}

void destroyBitArray(BitArray *array) {
    free(array->data);
    free(array);
}

void setBit(BitArray *array, int index, bool value) {
    if (value) {
        array->data[index / NUM_BITS] |= (1 << (index % NUM_BITS));
    } else {
        array->data[index / NUM_BITS] &= ~(1 << (index % NUM_BITS));
    }
}

bool getBit(BitArray *array, int index) {
    return (array->data[index / NUM_BITS] & (1 << (index % NUM_BITS)))!= 0;
}

void printBitArray(BitArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d", getBit(array, i));
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    BitArray *array = createBitArray(MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        setBit(array, i, rand() % 2);
    }
    printf("Initial bit array:\n");
    printBitArray(array);
    printf("Inverting bit array:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        setBit(array, i,!getBit(array, i));
    }
    printBitArray(array);
    printf("Flipping bit array:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        setBit(array, i,!getBit(array, i));
    }
    printBitArray(array);
    destroyBitArray(array);
    return 0;
}