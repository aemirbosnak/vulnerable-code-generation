//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int position;
    int input_size;
    int converted_size;
} HexadecimalConverter;

HexadecimalConverter* convert_hex(int input_size)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->position = 0;
    converter->input_size = input_size;
    converter->converted_size = 0;

    converter->buffer[0] = '\0';
    return converter;
}

void append_hex(HexadecimalConverter* converter, int value)
{
    char hex_digit[3];
    sprintf(hex_digit, "%x", value);

    if (converter->position + 1 > converter->input_size)
    {
        return;
    }

    converter->buffer[converter->position++] = hex_digit[0];
    converter->buffer[converter->position++] = hex_digit[1];
    converter->buffer[converter->position++] = ':';
    converter->converted_size++;
}

void print_hex(HexadecimalConverter* converter)
{
    printf("Converted hexadecimal: ");
    printf("%s", converter->buffer);
    printf("\n");
}

int main()
{
    HexadecimalConverter* converter = convert_hex(16);

    append_hex(converter, 0x12);
    append_hex(converter, 0x34);
    append_hex(converter, 0x56);

    print_hex(converter);

    free(converter);

    return 0;
}