//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexadecimalConverter
{
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int input_position;
    int output_position;
    int conversion_flag;
} HexadecimalConverter;

HexadecimalConverter* hexadecimal_converter_init(void)
{
    HexadecimalConverter* converter = malloc(sizeof(HexadecimalConverter));

    converter->input_position = 0;
    converter->output_position = 0;
    converter->conversion_flag = 0;

    return converter;
}

void hexadecimal_converter_convert(HexadecimalConverter* converter)
{
    char input_hex_char;
    int input_hex_value;
    int output_hex_value;
    char output_hex_char;

    converter->input[converter->input_position++] = '\0';

    if (converter->input[0] == '0' && converter->input[1] == 'x')
    {
        converter->conversion_flag = 1;
    }

    input_hex_char = converter->input[0];
    input_hex_value = strtol(converter->input, NULL, 16);

    output_hex_value = input_hex_value / 16;
    output_hex_char = '0' + output_hex_value;

    converter->output[converter->output_position++] = output_hex_char;

    output_hex_value = input_hex_value % 16;
    output_hex_char = '0' + output_hex_value;

    converter->output[converter->output_position++] = output_hex_char;

    converter->output[converter->output_position++] = ':';
}

int main()
{
    HexadecimalConverter* converter = hexadecimal_converter_init();

    printf("Enter a hexadecimal number: ");
    fgets(converter->input, MAX_BUFFER_SIZE, stdin);

    hexadecimal_converter_convert(converter);

    printf("Converted hexadecimal number: ");
    printf("%s", converter->output);

    return 0;
}