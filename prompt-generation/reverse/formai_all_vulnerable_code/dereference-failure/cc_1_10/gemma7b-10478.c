//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct HexConverter {
    char input[MAX_BUFFER_SIZE];
    char output[MAX_BUFFER_SIZE];
    int input_length;
    int output_length;
} HexConverter;

HexConverter* hex_converter_init(int input_length) {
    HexConverter* converter = (HexConverter*)malloc(sizeof(HexConverter));
    converter->input_length = input_length;
    converter->output_length = 0;
    converter->input[0] = '\0';
    converter->output[0] = '\0';
    return converter;
}

void hex_converter_add_input(HexConverter* converter, char data) {
    if (converter->input_length - converter->input_length) {
        return;
    }
    converter->input[converter->input_length++] = data;
    converter->input[converter->input_length] = '\0';
}

void hex_converter_convert(HexConverter* converter) {
    int i = 0;
    char hex_digits[] = "0123456789abcdef";
    converter->output_length = 0;
    for (i = 0; i < converter->input_length; i++) {
        char nibble = (converter->input[i] & 0xf0) >> 4;
        char low_nibble = converter->input[i] & 0x0f;
        converter->output[converter->output_length++] = hex_digits[nibble];
        converter->output[converter->output_length++] = hex_digits[low_nibble];
        converter->output[converter->output_length++] = ':';
    }
    converter->output[converter->output_length - 1] = '\0';
}

int main() {
    HexConverter* converter = hex_converter_init(20);
    hex_converter_add_input(converter, 0x12);
    hex_converter_add_input(converter, 0x34);
    hex_converter_add_input(converter, 0x56);
    hex_converter_convert(converter);
    printf("%s\n", converter->output);
    return 0;
}