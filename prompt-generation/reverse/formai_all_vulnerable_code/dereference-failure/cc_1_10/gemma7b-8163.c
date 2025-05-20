//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

typedef struct HexadecimalConverter
{
    int number;
    char* digits;
    int digits_used;
} HexadecimalConverter;

HexadecimalConverter* create_hexadecimal_converter(int number)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->number = number;
    converter->digits = malloc(MAX_DIGITS * sizeof(char));
    converter->digits_used = 0;
    return converter;
}

void convert_hexadecimal(HexadecimalConverter* converter)
{
    int quotient, remainder;
    char digit;

    converter->digits_used = 0;

    while (converter->number > 0)
    {
        quotient = converter->number / 16;
        remainder = converter->number % 16;

        digit = remainder + 'a' - 10;
        converter->digits[converter->digits_used++] = digit;

        converter->number = quotient;
    }

    converter->digits[converter->digits_used] = '\0';
}

int main()
{
    HexadecimalConverter* converter = create_hexadecimal_converter(12);
    convert_hexadecimal(converter);
    printf("%s", converter->digits);

    free(converter->digits);
    free(converter);

    return 0;
}