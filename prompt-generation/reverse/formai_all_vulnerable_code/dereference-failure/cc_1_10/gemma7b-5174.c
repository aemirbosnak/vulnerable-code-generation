//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexConverter
{
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int input_size;
    int output_size;
    int offset;
} HexConverter;

HexConverter* hex_converter_init(int input_size, int output_size)
{
    HexConverter* converter = (HexConverter*)malloc(sizeof(HexConverter));

    converter->input_size = input_size;
    converter->output_size = output_size;
    converter->offset = 0;

    converter->input[0] = '\0';
    converter->output[0] = '\0';

    return converter;
}

void hex_converter_add_input(HexConverter* converter, char input)
{
    if (converter->input_size - converter->offset - 1 >= 0)
    {
        converter->input[converter->offset] = input;
        converter->offset++;
    }
}

void hex_converter_convert(HexConverter* converter)
{
    int i = 0;
    int j = 0;

    converter->output_size = 0;

    for (i = 0; i < converter->input_size; i++)
    {
        if (converter->input[i] >= 'a')
        {
            converter->output[j] = converter->input[i] - 'a' + 10;
            j++;
        }
        else
        {
            converter->output[j] = converter->input[i] - 'A' + 10;
            j++;
        }
    }

    converter->output[j] = '\0';
}

void hex_converter_print_output(HexConverter* converter)
{
    printf("%s", converter->output);
}

int main()
{
    HexConverter* converter = hex_converter_init(10, 20);

    hex_converter_add_input(converter, 'a');
    hex_converter_add_input(converter, 'b');
    hex_converter_add_input(converter, 'c');
    hex_converter_add_input(converter, 'D');

    hex_converter_convert(converter);

    hex_converter_print_output(converter);

    free(converter);

    return 0;
}