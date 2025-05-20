//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BINARY_MAX_DIGITS 32
#define DECIMAL_MAX_DIGITS 10

typedef struct {
    int digits[BINARY_MAX_DIGITS];
    int len;
} binary_t;

typedef struct {
    int digits[DECIMAL_MAX_DIGITS];
    int len;
} decimal_t;

void binary_to_decimal(binary_t *binary, decimal_t *decimal);
void decimal_to_binary(decimal_t *decimal, binary_t *binary);

int main() {
    binary_t binary;
    decimal_t decimal;

    // Test cases
    binary.digits[0] = 1;
    binary.len = 1;
    decimal_to_binary(&decimal, &binary);
    printf("Decimal: %d\n", decimal.digits[0]);

    binary.digits[0] = 1;
    binary.digits[1] = 1;
    binary.len = 2;
    decimal_to_binary(&decimal, &binary);
    printf("Decimal: %d\n", decimal.digits[0]);

    binary.digits[0] = 1;
    binary.digits[1] = 1;
    binary.digits[2] = 1;
    binary.len = 3;
    decimal_to_binary(&decimal, &binary);
    printf("Decimal: %d\n", decimal.digits[0]);

    // Convert binary to decimal
    binary.digits[0] = 1;
    binary.digits[1] = 1;
    binary.digits[2] = 0;
    binary.len = 3;
    decimal_to_binary(&decimal, &binary);
    printf("Decimal: %d\n", decimal.digits[0]);

    // Convert decimal to binary
    decimal.digits[0] = 5;
    decimal.digits[1] = 3;
    decimal.digits[2] = 1;
    decimal.len = 3;
    binary_to_decimal(&binary, &decimal);
    printf("Binary: %d\n", binary.digits[0]);

    return 0;
}

void binary_to_decimal(binary_t *binary, decimal_t *decimal) {
    int i, j;
    int power = 1;

    for (i = 0; i < binary->len; i++) {
        j = binary->digits[i] - '0';
        decimal->digits[power * j] = j;
        power *= 2;
    }

    decimal->len = power;
}

void decimal_to_binary(decimal_t *decimal, binary_t *binary) {
    int i, j;
    int power = 1;

    for (i = 0; i < decimal->len; i++) {
        j = decimal->digits[i] - '0';
        binary->digits[power * j] = j;
        power *= 2;
    }

    binary->len = power;
}