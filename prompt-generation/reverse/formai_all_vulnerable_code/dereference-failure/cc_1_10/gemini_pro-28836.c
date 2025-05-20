//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_NUM_DIGITS 64

char *bin_to_dec(const char *bin) {
    uint64_t dec = 0;
    uint8_t i;

    for (i = 0; bin[i] != '\0'; i++) {
        dec <<= 1;
        if (bin[i] == '1') {
            dec |= 1;
        }
    }

    char *dec_str = malloc(MAX_NUM_DIGITS + 1);
    snprintf(dec_str, MAX_NUM_DIGITS + 1, "%llu", dec);
    return dec_str;
}

char *dec_to_bin(uint64_t dec) {
    char *bin = malloc(MAX_NUM_DIGITS + 1);
    uint8_t i, j;

    for (i = 0; i <= MAX_NUM_DIGITS; i++) {
        bin[i] = '0';
    }

    i = MAX_NUM_DIGITS - 1;
    while (dec > 0) {
        if (dec % 2 == 1) {
            bin[i--] = '1';
        }
        dec /= 2;
    }

    return bin;
}

int main(void) {
    char *bin = "10100011";
    char *dec = bin_to_dec(bin);
    printf("Binary: %s\n", bin);
    printf("Decimal: %s\n", dec);
    free(dec);

    uint64_t dec_num = 123456789;
    char *bin_num = dec_to_bin(dec_num);
    printf("Decimal: %llu\n", dec_num);
    printf("Binary: %s\n", bin_num);
    free(bin_num);

    return 0;
}