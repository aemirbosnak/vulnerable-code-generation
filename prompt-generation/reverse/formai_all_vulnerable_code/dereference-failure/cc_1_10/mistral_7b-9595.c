//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BITS_PER_BYTE 8
#define MAX_HEX_STRING_LENGTH 32

void bin2hex(unsigned char byte, char *hex) {
    unsigned char bit;
    char hex_chars[4];

    for (int i = 0; i < BITS_PER_BYTE * 2; i++) {
        bit = (byte >> i) & 0x01;
        sprintf(hex_chars, "%s%s", i % 2 ? (bit ? "1" : "0") : "%s%s", hex_chars);
    }

    strncpy(hex, &hex_chars[2], 3);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hex string>\n", argv[0]);
        return 1;
    }

    unsigned int decimal_number = 0;
    char hex_string[MAX_HEX_STRING_LENGTH];

    strcpy(hex_string, argv[1]);

    for (int i = 0; hex_string[i]; i++) {
        if (isxdigit(hex_string[i])) {
            if (isdigit(hex_string[i])) {
                decimal_number += (hex_string[i] - '0') << (4 * (sizeof(unsigned char) * 2 - 1 - (i % 2)));
            } else {
                decimal_number += (hex_string[i] & 0xdf) << (4 * (sizeof(unsigned char) * 2 - 1 - (i % 2)));
                decimal_number |= (hex_string[i] & 0xf) << (4 * (sizeof(unsigned char) * 2 - 1 - (i % 2)) - 4);
            }
        }
    }

    unsigned char byte;
    for (int i = 0; decimal_number; i++) {
        byte = (decimal_number & 0xff);
        decimal_number >>= 8;

        char hex[3];
        bin2hex(byte, hex);
        printf("%s ", hex);
    }

    printf("\n");

    return 0;
}