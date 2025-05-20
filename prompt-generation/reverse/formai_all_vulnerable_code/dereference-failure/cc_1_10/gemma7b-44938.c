//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int offset;
} HexadecimalConverter;

HexadecimalConverter* convert_hex_to_decimal(HexadecimalConverter* converter)
{
    converter->position = 0;
    converter->offset = 0;

    printf("Enter hexadecimal number: ");
    fgets(converter->buffer, MAX_BUFFER_SIZE, stdin);

    return converter;
}

int convert_hex_to_decimal_value(HexadecimalConverter* converter)
{
    int value = 0;
    int i = 0;

    while (converter->buffer[i] != '\0')
    {
        int digit = converter->buffer[i] - 'a' + 10;
        value += digit * pow(16, converter->offset) ;
        converter->offset++;
        i++;
    }

    return value;
}

int main()
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));

    converter = convert_hex_to_decimal(converter);
    int decimal_value = convert_hex_to_decimal_value(converter);

    printf("Decimal value: %d\n", decimal_value);

    free(converter);

    return 0;
}