//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexadecimalConverter
{
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int input_position;
    int output_position;
    int conversion_flag;
} HexadecimalConverter;

HexadecimalConverter* create_hexadecimal_converter(void)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));

    converter->input_position = 0;
    converter->output_position = 0;
    converter->conversion_flag = 0;

    return converter;
}

void convert_hexadecimal(HexadecimalConverter* converter)
{
    char input_character;
    int input_value;
    int output_value;
    char output_character;

    input_character = converter->input[converter->input_position];

    if (input_character >= 'a' && input_character <= 'f')
    {
        input_value = input_character - 'a' + 10;
    }
    else if (input_character >= 'A' && input_character <= 'F')
    {
        input_value = input_character - 'A' + 10;
    }
    else
    {
        converter->conversion_flag = 1;
        return;
    }

    output_value = input_value / 16;
    output_character = '0' + output_value;

    converter->output[converter->output_position++] = output_character;

    output_value = input_value % 16;
    output_character = '0' + output_value;

    converter->output[converter->output_position++] = output_character;

    converter->input_position++;
}

int main()
{
    HexadecimalConverter* converter = create_hexadecimal_converter();

    printf("Enter a hexadecimal number: ");
    fgets(converter->input, MAX_BUFFER_SIZE, stdin);

    while (!converter->conversion_flag)
    {
        convert_hexadecimal(converter);
    }

    printf("Converted hexadecimal number: ");
    printf("%s", converter->output);

    return 0;
}