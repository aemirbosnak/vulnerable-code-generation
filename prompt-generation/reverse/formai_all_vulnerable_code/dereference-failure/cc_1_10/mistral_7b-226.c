//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char hex[3];
    unsigned int decimal;
} HexToDec;

void hex_to_decimal(HexToDec *hex_dec) {
    hex_dec->decimal = 0;
    int power = 0;
    for (int i = strlen(hex_dec->hex) - 1; i >= 0; i--) {
        if (isdigit(hex_dec->hex[i])) {
            hex_dec->decimal += (hex_dec->hex[i] - '0') * pow(16, power);
            power++;
        } else {
            hex_dec->decimal += (hex_dec->hex[i] - 'A' + 10) * pow(16, power);
            power++;
        }
    }
}

void dec_to_hex(unsigned int decimal, char *hex) {
    int *digits = (int*) malloc(sizeof(int) * 16);
    int index = 0;

    while (decimal > 0) {
        digits[index++] = decimal % 16;
        decimal /= 16;
    }

    int length = index;

    for (int i = length; i < 4; i++) {
        digits[i] = 0;
    }

    for (int i = 0; i < 4; i++) {
        if (digits[i] >= 10) {
            hex[i] = (digits[i] - 10) + 'A';
        } else {
            hex[i] = digits[i] + '0';
        }
    }

    for (int i = length - 1; i >= 0; i--) {
        hex[length - i - 1] = digits[i] + '0';
    }

    free(digits);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hexadecimal number> <decimal number>\n", argv[0]);
        return 1;
    }

    HexToDec hex_dec;
    strcpy(hex_dec.hex, argv[1]);

    hex_to_decimal(&hex_dec);

    if (atoi(argv[2]) != hex_dec.decimal) {
        printf("Error: Hexadecimal number '%s' does not correspond to decimal number '%s'\n", argv[1], argv[2]);
        return 1;
    }

    char hex[5];
    dec_to_hex(hex_dec.decimal, hex);

    printf("Decimal number '%s' is equal to hexadecimal number '%s'\n", argv[2], hex);

    return 0;
}