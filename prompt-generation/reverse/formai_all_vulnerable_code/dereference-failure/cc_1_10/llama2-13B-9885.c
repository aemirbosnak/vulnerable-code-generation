//LLAMA2-13B DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#define BIT_VECTOR_SIZE (1 << 12)
#define BIT_VECTOR_MASK (BIT_VECTOR_SIZE - 1)

struct bit_vector {
    unsigned char *data;
    size_t size;
};

struct bit_vector *bit_vector_create(size_t size) {
    struct bit_vector *bv = malloc(sizeof(struct bit_vector) + size * sizeof(unsigned char));
    bv->data = (unsigned char *)(bv + 1);
    bv->size = size;
    return bv;
}

void bit_vector_set(struct bit_vector *bv, size_t index) {
    if (index >= bv->size) {
        return;
    }
    bv->data[index / 8] |= (1 << (index % 8));
}

void bit_vector_clear(struct bit_vector *bv, size_t index) {
    if (index >= bv->size) {
        return;
    }
    bv->data[index / 8] &= ~(1 << (index % 8));
}

int bit_vector_get(struct bit_vector *bv, size_t index) {
    if (index >= bv->size) {
        return 0;
    }
    return (bv->data[index / 8] & (1 << (index % 8))) != 0;
}

void bit_vector_free(struct bit_vector *bv) {
    free(bv->data);
    free(bv);
}

int main() {
    struct bit_vector *bv = bit_vector_create(BIT_VECTOR_SIZE);

    // Set some bits
    bit_vector_set(bv, 3);
    bit_vector_set(bv, 7);
    bit_vector_set(bv, 12);

    // Clear some bits
    bit_vector_clear(bv, 5);
    bit_vector_clear(bv, 10);

    // Get some bits
    if (bit_vector_get(bv, 3)) {
        printf("Bit 3 is set\n");
    }
    if (bit_vector_get(bv, 7)) {
        printf("Bit 7 is set\n");
    }
    if (bit_vector_get(bv, 12)) {
        printf("Bit 12 is set\n");
    }

    // Free the bit vector
    bit_vector_free(bv);

    return 0;
}