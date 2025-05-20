//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char* buffer;
    int bufferSize;
    int position;
} HexadecimalConverter;

HexadecimalConverter* createConverter(int size)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));

    converter->buffer = malloc(size * MAX_BUFFER_SIZE);
    converter->bufferSize = size;
    converter->position = 0;

    return converter;
}

void convertHex(HexadecimalConverter* converter, char input)
{
    int number = input - 'a' + 10;
    if (number > 9)
    {
        number = input - 'A' + 10;
    }

    converter->buffer[converter->position++] = number & 0xf;
}

void printHex(HexadecimalConverter* converter)
{
    for (int i = 0; i < converter->position; i++)
    {
        printf("%02x ", converter->buffer[i]);
    }
    printf("\n");
}

int main()
{
    HexadecimalConverter* converter = createConverter(16);

    convertHex(converter, 'a');
    convertHex(converter, 'B');
    convertHex(converter, 'c');

    printHex(converter);

    free(converter->buffer);
    free(converter);

    return 0;
}