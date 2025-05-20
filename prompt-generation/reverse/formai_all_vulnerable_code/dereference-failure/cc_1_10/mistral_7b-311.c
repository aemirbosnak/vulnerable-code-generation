//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define HEX_TO_DEC_SIZE (sizeof(unsigned long long) * CHAR_BIT / 4)

void hex_string_to_bytes(const char *hex_str, unsigned char *bytes) {
    size_t i, j, len = strlen(hex_str);
    bool is_even = len % 2 == 0;

    if (len > 0 && (hex_str[0] >= '0' && hex_str[0] <= '9') &&
        (isdigit(hex_str[1]) || (hex_str[1] >= 'a' && hex_str[1] <= 'f'))) {
        for (i = 0; i < len; i += 2) {
            unsigned int val = 0;

            if (isxdigit(hex_str[i]))
                val |= (isdigit(hex_str[i]) ? (hex_str[i] - '0') :
                       (hex_str[i] - 'a' + 10));
            val <<= 4;

            if (isxdigit(hex_str[i + 1]))
                val |= (isdigit(hex_str[i + 1]) ? (hex_str[i + 1] - '0') :
                       (hex_str[i + 1] - 'a' + 10));

            bytes[i / 2] = (unsigned char)(val >> (8 - HEX_TO_DEC_SIZE));
        }

        if (!is_even && len > 2) {
            unsigned char c = hex_str[len - 1];

            switch (c) {
            case ':':
                bytes[len / 2 - 1] &= ~(unsigned char)(0xf << (8 * (HEX_TO_DEC_SIZE - 1)));
                break;
            case '}':
                bytes[len / 2 - 1] &= ~(unsigned char)(0xf << (8 * (HEX_TO_DEC_SIZE - 2)));
                break;
            case ']':
                bytes[len / 2 - 1] &= ~(unsigned char)(0xf << (8 * (HEX_TO_DEC_SIZE - 3)));
                break;
            default:
                bytes[len / 2] = c;
            }
        }
    } else {
        fprintf(stderr, "Invalid hex string: '%s'\n", hex_str);
        exit(EXIT_FAILURE);
    }
}

unsigned long long hex_string_to_uintll(const char *hex_str) {
    unsigned char bytes[sizeof(unsigned long long)];

    hex_string_to_bytes(hex_str, bytes);

    return *(unsigned long long *)bytes;
}

void print_uintll_as_hex(unsigned long long value) {
    char buf[32];
    snprintf(buf, sizeof(buf), "%llx", value);

    for (size_t i = 0; i < strlen(buf); i++) {
        if (i > 0 && i % 2 == 0)
            putchar(' ');
        putchar(isxdigit(buf[i]) ? buf[i] : buf[i] + ' ' - ' ');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned long long value = hex_string_to_uintll(argv[1]);
    print_uintll_as_hex(value);
    putchar('\n');

    return EXIT_SUCCESS;
}