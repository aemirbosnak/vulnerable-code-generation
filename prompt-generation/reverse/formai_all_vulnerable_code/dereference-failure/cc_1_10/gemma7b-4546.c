//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex;
    int conversionFlag;
    char input[MAX_BUFFER_SIZE];
    int inputIndex;
    int inputFlag;
} HexadecimalConverter;

HexadecimalConverter* createHexadecimalConverter()
{
    HexadecimalConverter* converter = (HexadecimalConverter*)malloc(sizeof(HexadecimalConverter));

    converter->bufferIndex = 0;
    converter->conversionFlag = 0;
    converter->inputIndex = 0;
    converter->inputFlag = 0;

    return converter;
}

void convertHexadecimal(HexadecimalConverter* converter)
{
    int inputValue = 0;
    int i = 0;

    converter->bufferIndex = 0;

    for (i = 0; converter->input[i] != '\0'; i++)
    {
        if (converter->input[i] >= 'a' && converter->input[i] <= 'f')
        {
            inputValue = inputValue * 16 + converter->input[i] - 'a' + 10;
        }
        else if (converter->input[i] >= 'A' && converter->input[i] <= 'F')
        {
            inputValue = inputValue * 16 + converter->input[i] - 'A' + 10;
        }
        else if (converter->input[i] >= '0' && converter->input[i] <= '9')
        {
            inputValue = inputValue * 16 + converter->input[i] - '0';
        }

        converter->buffer[converter->bufferIndex++] = (inputValue & 0xf) + '0';
    }

    converter->buffer[converter->bufferIndex] = '\0';
}

int main()
{
    HexadecimalConverter* converter = createHexadecimalConverter();

    printf("Enter a hexadecimal number: ");
    fgets(converter->input, MAX_BUFFER_SIZE, stdin);

    convertHexadecimal(converter);

    printf("Converted hexadecimal number: %s\n", converter->buffer);

    free(converter);

    return 0;
}