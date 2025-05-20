//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size;
    int current_position;
    int is_converting;
} HexadecimalConverter;

HexadecimalConverter* initialize_hexadecimal_converter(int buffer_size)
{
    HexadecimalConverter* converter = (HexadecimalConverter*)malloc(sizeof(HexadecimalConverter));
    converter->buffer_size = buffer_size;
    converter->current_position = 0;
    converter->is_converting = 0;
    return converter;
}

void convert_hexadecimal(HexadecimalConverter* converter, unsigned int number)
{
    int i = 0;
    char hex_digits[] = "0123456789abcdef";

    converter->buffer[converter->current_position++] = hex_digits[number & 0xf];
    if (number >> 4)
    {
        converter->buffer[converter->current_position++] = hex_digits[((number >> 4) & 0xf)];
    }

    converter->buffer[converter->current_position] = '\0';
}

void print_hexadecimal(HexadecimalConverter* converter)
{
    printf("%s", converter->buffer);
}

int main()
{
    HexadecimalConverter* converter = initialize_hexadecimal_converter(MAX_BUFFER_SIZE);

    convert_hexadecimal(converter, 0x12);
    convert_hexadecimal(converter, 0x2a);
    convert_hexadecimal(converter, 0x4f);

    print_hexadecimal(converter);

    return 0;
}