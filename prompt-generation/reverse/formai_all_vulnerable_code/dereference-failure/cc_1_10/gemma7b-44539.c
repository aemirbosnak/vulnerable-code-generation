//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char* buffer;
    int bufferSize;
    int currentPosition;
    int isConverting;
    char* output;
    int outputSize;
    int outputPosition;
} HexadecimalConverter;

HexadecimalConverter* initializeHexadecimalConverter(int bufferSize, int outputSize)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));
    converter->buffer = malloc(bufferSize);
    converter->bufferSize = bufferSize;
    converter->currentPosition = 0;
    converter->isConverting = 0;
    converter->output = malloc(outputSize);
    converter->outputSize = outputSize;
    converter->outputPosition = 0;

    return converter;
}

void convertHexadecimal(HexadecimalConverter* converter)
{
    char input = getchar();

    if (converter->isConverting)
    {
        if (input >= 'a' && input <= 'f')
        {
            converter->buffer[converter->currentPosition++] = input - 'a' + 10;
        }
        else if (input >= 'A' && input <= 'F')
        {
            converter->buffer[converter->currentPosition++] = input - 'A' + 10;
        }
        else if (input >= '0' && input <= '9')
        {
            converter->buffer[converter->currentPosition++] = input - '0';
        }
        else if (input == '\n')
        {
            converter->isConverting = 0;
            converter->buffer[converter->currentPosition] = '\0';

            printf("Converted hexadecimal: %s\n", converter->buffer);
            converter->currentPosition = 0;
        }
    }
    else
    {
        if (input == 'h')
        {
            converter->isConverting = 1;
            printf("Enter hexadecimal number: ");
        }
    }
}

int main()
{
    HexadecimalConverter* converter = initializeHexadecimalConverter(MAX_BUFFER_SIZE, MAX_BUFFER_SIZE);

    while (1)
    {
        convertHexadecimal(converter);
    }

    return 0;
}