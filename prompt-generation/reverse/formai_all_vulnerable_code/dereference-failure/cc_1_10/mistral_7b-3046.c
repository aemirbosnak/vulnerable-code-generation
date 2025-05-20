//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>

#define MAX_BINARY_LEN 1024

void bin_to_decimal(const uint8_t *binary, size_t length, uintmax_t *decimal) {
    uintmax_t num = 0;
    size_t i;

    for (i = 0; i < length; i++) {
        if (binary[i] > '1' || binary[i] < '0') {
            fprintf(stderr, "Invalid binary input: %c\n", binary[i]);
            *decimal = 0;
            return;
        }

        num *= 2;
        num += binary[i] - '0';
    }

    *decimal = num;
}

int main(int argc, char *argv[]) {
    uint8_t binary[MAX_BINARY_LEN];
    size_t binary_len = 0;
    uintmax_t decimal;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <binary_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(binary, argv[1], MAX_BINARY_LEN);

    // Remove any leading zeros and calculate length
    binary_len = strlen(binary);
    while (binary[binary_len - 1] == '0') {
        binary[binary_len - 1] = '\0';
        binary_len--;
    }

    if (binary_len > MAX_BINARY_LEN - 1) {
        fprintf(stderr, "Binary string too long\n");
        return EXIT_FAILURE;
    }

    // Convert binary to decimal
    bin_to_decimal(binary, binary_len, &decimal);

    printf("Decimal equivalent of binary string \"%s\" is %ju\n", binary, decimal);

    return EXIT_SUCCESS;
}