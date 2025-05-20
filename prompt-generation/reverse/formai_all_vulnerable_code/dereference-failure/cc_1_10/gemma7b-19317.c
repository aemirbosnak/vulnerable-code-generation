//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int offset;
    int capacity;
} HexadecimalConverter;

HexadecimalConverter* createHexadecimalConverter(int capacity)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->offset = 0;
    converter->capacity = capacity;
    converter->buffer[0] = '\0';

    return converter;
}

void appendHexDigit(HexadecimalConverter* converter, int digit)
{
    if (converter->offset >= converter->capacity - 1)
    {
        return;
    }

    char hexDigit = digit & 0xf;
    converter->buffer[converter->offset++] = '0' + hexDigit;
    converter->buffer[converter->offset++] = ':';
}

void convertHex(int number)
{
    HexadecimalConverter* converter = createHexadecimalConverter(16);

    while (number)
    {
        appendHexDigit(converter, number % 16);
        number /= 16;
    }

    printf("%s\n", converter->buffer);
    free(converter);
}

int main()
{
    convertHex(12);
    convertHex(255);

    return 0;
}