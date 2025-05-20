//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 16

typedef struct HexadecimalConverter {
    char *hex_string;
    int max_digits;
    int current_digit;
    unsigned int value;
} HexadecimalConverter;

HexadecimalConverter *initialize_converter(int max_digits) {
    HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));
    converter->hex_string = malloc(max_digits * 3);
    converter->max_digits = max_digits;
    converter->current_digit = 0;
    converter->value = 0;
    return converter;
}

void convert_decimal_to_hex(HexadecimalConverter *converter, int decimal) {
    int quotient = decimal / MAX_DIGITS;
    int remainder = decimal % MAX_DIGITS;

    if (converter->current_digit == 0) {
        converter->hex_string[0] = '0';
    }

    converter->hex_string[converter->current_digit++] = '0' + remainder;

    if (quotient) {
        convert_decimal_to_hex(converter, quotient);
    }
}

void print_hex_string(HexadecimalConverter *converter) {
    for (int i = 0; i < converter->current_digit; i++) {
        printf("%c ", converter->hex_string[i]);
    }
    printf("\n");
}

int main() {
    HexadecimalConverter *converter = initialize_converter(MAX_DIGITS);
    convert_decimal_to_hex(converter, 15);
    print_hex_string(converter);

    convert_decimal_to_hex(converter, 22);
    print_hex_string(converter);

    return 0;
}