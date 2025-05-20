//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int currentPosition;
    int targetPosition;
} HexadecimalConverter;

HexadecimalConverter* convertHexadecimal(int targetPosition)
{
    HexadecimalConverter* converter = (HexadecimalConverter*)malloc(sizeof(HexadecimalConverter));

    converter->currentPosition = 0;
    converter->targetPosition = targetPosition;

    return converter;
}

void convertHexadecimalValue(HexadecimalConverter* converter, int value)
{
    int quotient = value / 16;
    int remainder = value % 16;

    if (converter->currentPosition < converter->targetPosition)
    {
        converter->buffer[converter->currentPosition++] = '0' + quotient;
    }

    if (converter->currentPosition < converter->targetPosition)
    {
        converter->buffer[converter->currentPosition++] = '0' + remainder;
    }
}

void printHexadecimal(HexadecimalConverter* converter)
{
    for (int i = 0; i < converter->currentPosition; i++)
    {
        printf("%c", converter->buffer[i]);
    }

    printf("\n");
}

int main()
{
    HexadecimalConverter* converter = convertHexadecimal(10);

    convertHexadecimalValue(converter, 15);
    convertHexadecimalValue(converter, 22);
    convertHexadecimalValue(converter, 29);

    printHexadecimal(converter);

    free(converter);

    return 0;
}