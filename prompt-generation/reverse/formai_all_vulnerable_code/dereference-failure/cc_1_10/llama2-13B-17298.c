//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define BINARY_SIZE 16

typedef struct binary_t {
    uint8_t data[BINARY_SIZE];
    size_t len;
} binary_t;

static void binary_to_decimal(binary_t *bin) {
    size_t i;
    uint8_t mask = 1;
    uint64_t dec = 0;

    for (i = 0; i < BINARY_SIZE; i++) {
        dec += (bin->data[i] & mask) * (1 << (i % 4));
        mask <<= 1;
    }

    printf("%" PRIu64 "\n", dec);
}

static void decimal_to_binary(uint64_t dec) {
    size_t i;
    binary_t bin;
    uint8_t mask = 1;

    for (i = 0; i < 64; i++) {
        if (dec & mask) {
            bin.data[i] |= mask;
        }
        mask <<= 1;
    }

    bin.len = i;

    printf("%s\n", bin.data);
}

int main() {
    binary_t bin;
    uint64_t dec;

    printf("Enter a binary number (max 16 digits): ");
    scanf("%15s", bin.data);
    bin.len = strlen(bin.data);

    printf("Binary: %s\n", bin.data);

    decimal_to_binary(strtoull(bin.data, NULL, 2));

    return 0;
}