//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int offset;
    int conversion_state;
    int number_of_digits;
} HexadecimalConverter;

HexadecimalConverter* initialize_hexadecimal_converter(int number_of_digits)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->offset = 0;
    converter->conversion_state = 0;
    converter->number_of_digits = number_of_digits;
    return converter;
}

void convert_hexadecimal(HexadecimalConverter* converter, int number)
{
    char digit;
    int i = converter->offset;

    converter->buffer[i++] = number & 0xf;
    converter->buffer[i++] = (number >> 4) & 0xf;

    if (converter->offset - converter->number_of_digits - 1 >= 0)
    {
        converter->buffer[i++] = ',';
    }

    converter->conversion_state++;
    converter->offset += 2;
}

void print_hexadecimal(HexadecimalConverter* converter)
{
    int i = 0;

    for (; converter->buffer[i] != '\0'; i++)
    {
        printf("%c", converter->buffer[i]);
    }

    printf("\n");
}

int main()
{
    HexadecimalConverter* converter = initialize_hexadecimal_converter(3);

    convert_hexadecimal(converter, 0x12);
    convert_hexadecimal(converter, 0x2a);
    convert_hexadecimal(converter, 0x4f);

    print_hexadecimal(converter);

    return 0;
}