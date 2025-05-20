//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void print_hex(unsigned char hex) {
    if (hex >= 0x10) printf(":%X", hex - 0x10);
    else printf(":0%X", hex);
}

void hex_to_bin(unsigned char hex, char* bin) {
    int i;

    for (i = 0; i < 4; i++) {
        bin[i] = hex % 2 + '0';
        hex /= 2;
    }

    for (i = 3; i >= 0; i--) putchar(bin[i]);
}

void print_binary(unsigned char byte) {
    char bin[5];
    hex_to_bin(byte, bin);
    putchar(':');
    printf("B%s", bin);
}

void print_byte(unsigned char byte) {
    print_hex(byte);
    print_binary(byte);
}

void print_string_hex(char* str) {
    int i;

    printf(":");
    for (i = 0; str[i]; i++) {
        if (isalnum(str[i])) print_hex((unsigned char)str[i]);
        else printf(":.");
    }
    putchar('\n');
}

int main(int argc, char* argv[]) {
    int i;

    if (argc != 2) {
        printf("Usage: %s <hex string>\n", argv[0]);
        return 1;
    }

    for (i = 0; argv[1][i]; i++) {
        if (!isxdigit(argv[1][i])) {
            printf("Error: Invalid character '%c' in hex string.\n", argv[1][i]);
            return 1;
        }
    }

    print_string_hex(argv[1]);

    return 0;
}