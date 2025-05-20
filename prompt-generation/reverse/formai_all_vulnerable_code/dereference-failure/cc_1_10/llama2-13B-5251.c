//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <limits.h>

#define BINARY_MAX_LENGTH 32

// Structure to hold the binary and ASCII representations of a number
typedef struct {
    uint8_t binary[BINARY_MAX_LENGTH];
    char ascii[BINARY_MAX_LENGTH];
} binary_t;

// Function to convert a decimal number to binary
binary_t *dec2bin(uint32_t num) {
    binary_t *bin = malloc(sizeof(binary_t));
    uint8_t i = 0;

    do {
        bin->binary[i++] = (num % 2) ? 1 : 0;
        num /= 2;
    } while (num != 0);

    bin->ascii[i] = 0;
    return bin;
}

// Function to convert a binary number to ASCII
char *bin2asc(binary_t *bin) {
    char *asc = malloc(sizeof(char) * (bin->ascii[0] ? BINARY_MAX_LENGTH : 1));
    uint8_t i = 0;

    for (; i < bin->ascii[0]; i++) {
        asc[i] = bin->ascii[i];
    }

    for (; i < BINARY_MAX_LENGTH; i++) {
        asc[i] = '0' + (bin->binary[i] / 2);
    }

    return asc;
}

int main() {
    uint32_t num = 123;
    binary_t *bin = dec2bin(num);
    char *asc = bin2asc(bin);

    printf("Decimal: %u\n", num);
    printf("Binary: ");
    for (uint8_t i = 0; i < BINARY_MAX_LENGTH; i++) {
        printf("%c", bin->binary[i] ? '1' : '0');
    }
    printf("\nASCII: %s\n", asc);

    free(asc);
    free(bin);

    return 0;
}