//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char *buffer;
    int size;
    int position;
    int is_initialized;
} HexadecimalConverter;

void hexadecimal_converter_init(HexadecimalConverter *converter)
{
    converter->buffer = malloc(MAX_BUFFER_SIZE);
    converter->size = MAX_BUFFER_SIZE;
    converter->position = 0;
    converter->is_initialized = 1;
}

void hexadecimal_converter_append(HexadecimalConverter *converter, char hex_digit)
{
    if (converter->position >= converter->size)
    {
        converter->buffer = realloc(converter->buffer, converter->size * 2);
        converter->size *= 2;
    }

    converter->buffer[converter->position++] = hex_digit;
}

char *hexadecimal_converter_get_result(HexadecimalConverter *converter)
{
    return converter->buffer;
}

int main()
{
    HexadecimalConverter converter;
    hexadecimal_converter_init(&converter);

    hexadecimal_converter_append(&converter, 'A');
    hexadecimal_converter_append(&converter, 'B');
    hexadecimal_converter_append(&converter, 'C');

    char *result = hexadecimal_converter_get_result(&converter);

    printf("%s\n", result);

    free(converter.buffer);

    return 0;
}