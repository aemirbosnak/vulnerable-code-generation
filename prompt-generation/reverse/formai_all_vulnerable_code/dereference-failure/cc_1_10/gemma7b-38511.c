//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex;
    int isConversionComplete;
} HexadecimalConverter;

HexadecimalConverter* createHexadecimalConverter(void)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->bufferIndex = 0;
    converter->isConversionComplete = 0;
    return converter;
}

void convertHexadecimal(HexadecimalConverter* converter, unsigned int number)
{
    char hexCharacters[] = "0123456789abcdef";

    converter->buffer[converter->bufferIndex++] = hexCharacters[number & 0xf];
    converter->buffer[converter->bufferIndex++] = hexCharacters[number >> 4 & 0xf];

    if (converter->bufferIndex >= MAX_BUFFER_SIZE - 1)
    {
        converter->isConversionComplete = 1;
    }
}

void printHexadecimal(HexadecimalConverter* converter)
{
    int i = 0;
    for (; i < converter->bufferIndex && converter->buffer[i] != '\0'; i++)
    {
        printf("%c ", converter->buffer[i]);
    }
    printf("\n");
}

int main(void)
{
    HexadecimalConverter* converter = createHexadecimalConverter();
    convertHexadecimal(converter, 0x12);
    convertHexadecimal(converter, 0x3a);
    printHexadecimal(converter);

    if (converter->isConversionComplete)
    {
        printf("Conversion complete.\n");
    }

    return 0;
}