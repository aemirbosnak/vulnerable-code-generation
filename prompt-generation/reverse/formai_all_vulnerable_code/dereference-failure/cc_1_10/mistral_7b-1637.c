//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define MAX_NUM 100000
#define BITS 32
#define SIZE (sizeof(int) * BITS)

typedef unsigned int uint;
typedef unsigned char byte;

void print_binary(byte *bin, size_t len) {
    for (size_t i = len; i--;) {
        printf("%c", (bin[i] > 128) ? '1' : '0');
        bin[i] &= 127;
        putchar((i == 0) ? '\n' : ' ');
    }
}

void swap_bytes(void *data, size_t len) {
    byte tmp;
    for (size_t i = 0; i < len / 2; i++) {
        size_t pos = i * 2;
        tmp = ((byte *) data)[pos];
        ((byte *) data)[pos] = ((byte *) data)[pos + 1];
        ((byte *) data)[pos + 1] = tmp;
    }
}

uint multiply(uint a, uint b) {
    uint hi = a / b;
    uint lo = a % b;
    uint result = 0;
    while (hi) {
        if (hi & 1)
            result += lo;
        lo <<= 1;
        hi >>= 1;
    }
    return result;
}

void power(uint base, uint exponent, uint *result) {
    *result = 1;
    for (uint i = 1; i <= exponent; i++)
        *result = multiply(*result, base);
}

int main() {
    srand(time(NULL));
    uint num = rand();
    printf("Number before: %d\n", num);

    print_binary((byte *) &num, SIZE);
    swap_bytes(&num, SIZE);
    printf("Number after swapping bytes: ");
    print_binary((byte *) &num, SIZE);

    uint base = 2, exponent;
    uint result;
    printf("\nCalculating 2 ^ %d:\n", rand() % 16 + 1);
    power(base, &exponent, &result);
    printf("Base: %d, Exponent: %d, Result: %d\n", base, exponent, result);

    printf("\nMultiplying %d and %d:\n", rand() % 101 + 10, rand() % 101 + 10);
    uint a = rand() % 101 + 10, b = rand() % 101 + 10;
    uint product = multiply(a, b);
    printf("A: %d, B: %d, Product: %d\n", a, b, product);

    return 0;
}