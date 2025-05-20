//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BASE_MIN 2
#define BASE_MAX 4

int str2int(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

int strtol_base(const char *str, int base) {
    int num = 0, i = 0;
    int len = strlen(str);

    if (len == 0)
        return num;

    if (base < BASE_MIN || base > BASE_MAX) {
        fprintf(stderr, "Invalid base: %d\n", base);
        return num;
    }

    for (; i < len && isdigit(str[i]) || (base == 16 && isxdigit(str[i])); ++i) {
        num = num * base + str2int(str[i]);
    }

    if (i < len) {
        fprintf(stderr, "Invalid binary number: '%s'\n", str);
        return num;
    }

    return num;
}

int main(int argc, char *argv[]) {
    int decimal = 0;
    char *bin_str = NULL;
    int base = BASE_MIN;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <binary_number> <base>\n", argv[0]);
        return 1;
    }

    bin_str = argv[1];
    base = atoi(argv[2]);

    decimal = strtol_base(bin_str, base);
    if (decimal == -1)
        return 1;

    printf("Decimal equivalent of '%s' base %d is %d\n", argv[1], base, decimal);
    return 0;
}