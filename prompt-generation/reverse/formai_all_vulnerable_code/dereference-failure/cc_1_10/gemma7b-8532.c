//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char *buffer;
    int size;
    int currentPosition;
    int isHexUppercase;
} HexadecimalConverter;

HexadecimalConverter *createHexadecimalConverter(int size)
{
    HexadecimalConverter *converter = malloc(sizeof(HexadecimalConverter));
    converter->buffer = malloc(size * MAX_BUFFER_SIZE);
    converter->size = size;
    converter->currentPosition = 0;
    converter->isHexUppercase = 0;

    return converter;
}

void convertHexadecimal(HexadecimalConverter *converter, unsigned int number)
{
    int i = 0;
    char *hexString = converter->buffer;

    converter->currentPosition = 0;

    do
    {
        int digit = number % 16;
        number /= 16;

        if (digit < 10)
        {
            hexString[converter->currentPosition++] = '0' + digit;
        }
        else
        {
            hexString[converter->currentPosition++] = 'a' + digit - 10 + converter->isHexUppercase;
        }
    } while (number);

    hexString[converter->currentPosition] = '\0';
}

int main()
{
    HexadecimalConverter *converter = createHexadecimalConverter(16);

    convertHexadecimal(converter, 12);
    printf("%s\n", converter->buffer);

    convertHexadecimal(converter, 255);
    printf("%s\n", converter->buffer);

    free(converter->buffer);
    free(converter);

    return 0;
}