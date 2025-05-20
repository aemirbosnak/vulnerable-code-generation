//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char *buffer;
    int bufferSize;
    int currentPosition;
    int isNumberValid;
    int isHexValid;
    int isConversionComplete;
} HexadecimalConverter;

HexadecimalConverter *createHexadecimalConverter(int bufferSize)
{
    HexadecimalConverter *converter = (HexadecimalConverter *)malloc(sizeof(HexadecimalConverter));

    converter->buffer = (char *)malloc(bufferSize);
    converter->bufferSize = bufferSize;
    converter->currentPosition = 0;
    converter->isNumberValid = 0;
    converter->isHexValid = 0;
    converter->isConversionComplete = 0;

    return converter;
}

void convertHexadecimal(HexadecimalConverter *converter, char number)
{
    if (converter->currentPosition >= converter->bufferSize - 1)
    {
        converter->isConversionComplete = 1;
        return;
    }

    if (number >= 'a' && number <= 'f')
    {
        converter->isHexValid = 1;
        converter->buffer[converter->currentPosition++] = number - 'a' + 10;
    }
    else if (number >= 'A' && number <= 'F')
    {
        converter->isHexValid = 1;
        converter->buffer[converter->currentPosition++] = number - 'A' + 10;
    }
    else if (number >= '0' && number <= '9')
    {
        converter->isHexValid = 1;
        converter->buffer[converter->currentPosition++] = number - '0';
    }
    else
    {
        converter->isNumberValid = 0;
    }
}

void printConvertedHexadecimal(HexadecimalConverter *converter)
{
    printf("Converted hexadecimal: ");

    for (int i = 0; i < converter->currentPosition; i++)
    {
        printf("%c ", converter->buffer[i]);
    }

    printf("\n");
}

int main()
{
    HexadecimalConverter *converter = createHexadecimalConverter(MAX_BUFFER_SIZE);

    convertHexadecimal(converter, 'a');
    convertHexadecimal(converter, 'f');
    convertHexadecimal(converter, '1');
    convertHexadecimal(converter, 'A');
    convertHexadecimal(converter, 'F');

    printConvertedHexadecimal(converter);

    return 0;
}