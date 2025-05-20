//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char *buffer;
    int bufferSize;
    int currentPosition;
    int targetPosition;
} HexadecimalConverter;

void convertHexadecimal(HexadecimalConverter *converter)
{
    char inputCharacter;
    int inputValue;
    int conversionFactor = 1;
    int i = 0;

    printf("Enter hexadecimal number: ");
    inputCharacter = getchar();

    while (inputCharacter != '\n')
    {
        inputValue = inputCharacter - 'a' + 10;
        if (inputValue < 0 || inputValue > 15)
        {
            printf("Invalid input. Please try again: ");
            return;
        }

        converter->buffer[converter->currentPosition++] = inputValue;

        printf("Enter next character (optional): ");
        inputCharacter = getchar();
    }

    converter->buffer[converter->currentPosition] = '\0';
    printf("Converted hexadecimal number: %s\n", converter->buffer);
}

int main()
{
    HexadecimalConverter converter;
    converter.buffer = malloc(MAX_BUFFER_SIZE);
    converter.bufferSize = MAX_BUFFER_SIZE;
    converter.currentPosition = 0;
    converter.targetPosition = 0;

    convertHexadecimal(&converter);

    free(converter.buffer);
    return 0;
}