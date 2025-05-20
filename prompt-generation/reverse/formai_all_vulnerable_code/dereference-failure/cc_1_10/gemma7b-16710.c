//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HexConverter
{
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int input_position;
    int output_position;
    int converted_bytes;
} HexConverter;

HexConverter* create_hex_converter()
{
    HexConverter* converter = malloc(sizeof(HexConverter));
    converter->input_position = 0;
    converter->output_position = 0;
    converter->converted_bytes = 0;
    return converter;
}

void convert_hex_string(HexConverter* converter)
{
    char input_byte;
    int i = 0;

    // Convert the input string into a series of hexadecimal bytes
    while (converter->input[i] != '\0')
    {
        input_byte = converter->input[i] - 'a' + 10;
        if (input_byte < 0 || input_byte > 15)
        {
            return;
        }
        converter->output[converter->output_position++] = input_byte;
        i++;
    }

    // Convert the hexadecimal bytes into a string
    converter->converted_bytes = i;
    converter->output[converter->output_position++] = '\0';
}

int main()
{
    HexConverter* converter = create_hex_converter();

    // Get the input string from the user
    printf("Enter a hexadecimal string: ");
    scanf("%s", converter->input);

    // Convert the input string into a hexadecimal number
    convert_hex_string(converter);

    // Print the converted number
    printf("Converted hexadecimal number: %s\n", converter->output);

    // Print the number of converted bytes
    printf("Number of converted bytes: %d\n", converter->converted_bytes);

    return 0;
}