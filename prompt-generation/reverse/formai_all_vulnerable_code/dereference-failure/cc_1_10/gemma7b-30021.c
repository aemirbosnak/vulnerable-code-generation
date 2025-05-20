//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexConverter
{
    char *buffer;
    int size;
    int position;
} HexConverter;

HexConverter *createHexConverter(int size)
{
    HexConverter *converter = malloc(sizeof(HexConverter));
    converter->buffer = malloc(size * MAX_BUFFER_SIZE);
    converter->size = size;
    converter->position = 0;

    return converter;
}

void addHexChar(HexConverter *converter, char hexChar)
{
    if (converter->position >= converter->size)
    {
        converter->buffer = realloc(converter->buffer, (converter->size + 1) * MAX_BUFFER_SIZE);
        converter->size++;
    }

    converter->buffer[converter->position++] = hexChar;
}

void printHex(HexConverter *converter)
{
    for (int i = 0; i < converter->position; i++)
    {
        printf("%c ", converter->buffer[i]);
    }

    printf("\n");
}

int main()
{
    HexConverter *converter = createHexConverter(16);

    addHexChar(converter, 0x12);
    addHexChar(converter, 0x34);
    addHexChar(converter, 0x56);
    addHexChar(converter, 0x78);

    printHex(converter);

    return 0;
}