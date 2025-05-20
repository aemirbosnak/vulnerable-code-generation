//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

typedef struct hex_t {
    char str[33];
    uint32_t value;
} hex_t;

void hex_parse(hex_t *hex, const char *str, size_t len) {
    size_t i;
    uint32_t value = 0;

    for (i = 0; i < len; i++) {
        char c = toupper(str[i]);

        if (c >= '0' && c <= '9') {
            value = (value << 4) | (c - '0');
        } else if (c >= 'A' && c <= 'F') {
            value = (value << 4) | (c - 'A' + 10);
        } else {
            fprintf(stderr, "Invalid hexadecimal character '%c'\n", c);
            exit(EXIT_FAILURE);
        }

        if (i >= 28) {
            hex->value = value;
            return;
        }

        if (i % 2 == 1) {
            hex->str[i / 2] = (value & 0xf) < 0xA ? value & 0xf + '0' : value & 0xf + 'A' - 10;
            value >>= 4;
        }
    }

    hex->value = value;
}

void print_hex(const hex_t *hex) {
    printf("%s\n", hex->str);
}

int main(int argc, char **argv) {
    hex_t hex;
    size_t i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t len = strlen(argv[1]);

    if (len & 1) {
        fprintf(stderr, "Hexadecimal string must have an even number of characters\n");
        return EXIT_FAILURE;
    }

    hex_parse(&hex, argv[1], len);
    print_hex(&hex);
    printf("Decimal: %u\n", hex.value);

    for (i = 0; i < 32; i++) {
        putchar(hex.str[i]);
        if (i % 2 == 1 && i != 31)
            putchar(' ');
    }
    putchar('\n');

    return EXIT_SUCCESS;
}