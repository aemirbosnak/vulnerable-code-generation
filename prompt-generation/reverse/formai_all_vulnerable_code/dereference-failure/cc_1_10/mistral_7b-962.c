//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void hex_str_to_bin(const char *hex, unsigned char *bin, size_t len) {
    const char *p;
    unsigned char byte, bit;
    size_t i;

    p = hex;
    for (i = 0; i < len; ++i) {
        byte = 0;
        memset(bin, 0, sizeof(unsigned char) * 4);

        if (isxdigit(*p) && isxdigit(*(p + 1))) {
            if (isdigit(*p))
                byte = 16 * (isdigit(*p++) - '0');
            else if (isalpha(*p))
                byte = 16 * (tolower(*p++) - 'a' + 10);

            if (isdigit(*p))
                byte += (isdigit(*p++) - '0');
            else if (isalpha(*p))
                byte += (tolower(*p++) - 'a' + 10);
        } else {
            die("Invalid hex string\n");
        }

        for (size_t j = 0; j < 4; ++j) {
            bit = (byte >> (4 * (3 - j))) & 0x01;
            bin[3 - j] |= bit << (7 * j);
        }
        ++p;
    }
}

void bin_to_hex(const unsigned char *bin, char *hex, size_t len) {
    static const char *const digits = "0123456789ABCDEF";
    char *p = hex;
    unsigned char byte;
    size_t i;

    for (i = 0; i < len; ++i) {
        byte = bin[i];
        *p++ = digits[(byte >> 4) & 0x0F];
        *p++ = digits[byte & 0x0F];
    }
    *p = '\0';
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hex hex\n", argv[0]);
        return EXIT_FAILURE;
    }

    const size_t len_hex = strlen(argv[1]);
    if (len_hex % 2 == 1) {
        fprintf(stderr, "Error: odd length hex string\n");
        return EXIT_FAILURE;
    }

    unsigned char bin[len_hex / 2 * 4];
    hex_str_to_bin(argv[1], bin, len_hex / 2);

    char hex_out[len_hex * 2 + 1];
    bin_to_hex(bin, hex_out, len_hex / 2);

    printf("Original hex string : %s\n", argv[1]);
    printf("Binary representation: ");
    for (size_t i = 0; i < len_hex / 2 * 4; ++i)
        printf("%02X ", bin[i]);
    printf("\n");
    printf("Converted hex string: %s\n", hex_out);

    return EXIT_SUCCESS;
}