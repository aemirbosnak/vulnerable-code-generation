//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Hexadecimal_Converter {
    char input[1024];
    char output[1024];
    int input_length;
    int output_length;
    int is_valid;
} Hexadecimal_Converter;

Hexadecimal_Converter* hexadecimal_converter_init() {
    Hexadecimal_Converter* converter = malloc(sizeof(Hexadecimal_Converter));
    converter->input_length = 0;
    converter->output_length = 0;
    converter->is_valid = 0;
    return converter;
}

void hexadecimal_converter_free(Hexadecimal_Converter* converter) {
    free(converter);
}

int hexadecimal_converter_convert(Hexadecimal_Converter* converter) {
    converter->is_valid = 1;
    int i = 0;
    char* input = converter->input;
    char* output = converter->output;
    converter->output_length = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (!isxdigit(input[i])) {
            converter->is_valid = 0;
            return -1;
        }
        output[converter->output_length++] = tolower(input[i]) - 87;
    }
    return 0;
}

int main() {
    Hexadecimal_Converter* converter = hexadecimal_converter_init();
    strcpy(converter->input, "F12A");
    hexadecimal_converter_convert(converter);
    if (converter->is_valid) {
        printf("Converted: %s", converter->output);
    } else {
        printf("Error: Invalid input");
    }
    hexadecimal_converter_free(converter);
    return 0;
}