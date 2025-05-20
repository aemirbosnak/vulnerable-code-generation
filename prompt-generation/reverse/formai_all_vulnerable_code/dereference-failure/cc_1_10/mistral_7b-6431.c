//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define BINARY_SIZE (CHAR_BIT * sizeof(long) * 2)

void print_binary(long num) {
    char binary[BINARY_SIZE];
    long mask = 1 << (CHAR_BIT * sizeof(long) - 1);
    int i;

    memset(binary, '0', BINARY_SIZE);

    for (i = 0; i < CHAR_BIT * sizeof(long); ++i) {
        if (num & mask)
            binary[CHAR_BIT * sizeof(long) - 1 - i] = '1';
        mask >>= 1;
    }

    printf("%s\n", binary);
}

int main(int argc, char *argv[]) {
    long decimal;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <decimal number>\n", argv[0]);
        return 1;
    }

    decimal = strtol(argv[1], NULL, 10);

    if (decimal < 0) {
        fprintf(stderr, "Error: Negative decimal number detected.\n");
        return 1;
    }

    print_binary(decimal);

    for (i = 0; i < 80; ++i)
        putchar(' '); // Add some space for aesthetics

    printf("is the decimal representation.\n");
    print_binary(-decimal);

    return 0;
}