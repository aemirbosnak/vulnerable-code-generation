//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100
#define MAX_DEC_LENGTH 33

void print_usage() {
    printf("Usage:./program [hexadecimal_number]\n");
}

int is_valid_hex(char *hex) {
    int i = 0;
    while (hex[i]!= '\0') {
        if (!isxdigit(hex[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int hex_to_dec(char *hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        int digit = 0;
        if (isdigit(hex[i])) {
            digit = hex[i] - '0';
        } else if (isupper(hex[i])) {
            digit = hex[i] - 'A' + 10;
        } else {
            digit = hex[i] - 'a' + 10;
        }
        dec = dec * 16 + digit;
    }
    return dec;
}

void dec_to_hex(int dec, char *hex) {
    sprintf(hex, "%X", dec);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }
    char hex[MAX_HEX_LENGTH];
    strcpy(hex, argv[1]);
    if (!is_valid_hex(hex)) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }
    int dec = hex_to_dec(hex);
    char dec_hex[MAX_HEX_LENGTH];
    dec_to_hex(dec, dec_hex);
    printf("Hexadecimal: %s\nDecimal: %s\n", hex, dec_hex);
    return 0;
}