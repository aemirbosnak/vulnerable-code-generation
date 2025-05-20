//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdint.h>

#define MAX_INPUT_SIZE 256
#define HEX_INPUT_SIZE 512

typedef struct {
    uint8_t hex[HEX_INPUT_SIZE];
    size_t index;
} HexInput;

bool is_hex_digit(char c) {
    return (isdigit(c) || (isalpha(c) && isupper(c) && (c - 'A') <= 0xF));
}

void hex_string_to_buffer(const char *str, HexInput *hex_input) {
    size_t i = 0;
    for (; i < MAX_INPUT_SIZE && str[i] != '\0'; i++) {
        if (is_hex_digit(str[i])) {
            hex_input->hex[hex_input->index++] = (uint8_t)str[i];
        } else if (i > 0 && is_hex_digit(str[i - 1])) {
            uint8_t high = hex_input->hex[hex_input->index - 1];
            uint8_t low = (uint8_t)str[i];
            hex_input->hex[hex_input->index++] = (high << 4) | low;
        } else {
            break;
        }
    }
}

size_t hex_input_length(const HexInput *hex_input) {
    return hex_input->index;
}

void print_hex(const uint8_t *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%02X", data[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal input>\n", argv[0]);
        return EXIT_FAILURE;
    }

    HexInput hex_input = {0};
    hex_string_to_buffer(argv[1], &hex_input);

    if (hex_input.index % 2 != 0) {
        printf("Invalid hexadecimal input: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Input: ");
    print_hex(hex_input.hex, hex_input_length(&hex_input));
    printf("\n");

    // Securely handling the user input by checking its length and validity
    // and allocating memory based on the actual length.
    size_t converted_data_length = hex_input_length(&hex_input) / 2;
    uint8_t *converted_data = (uint8_t *)calloc(1, converted_data_length);

    for (size_t i = 0; i < converted_data_length; i++) {
        converted_data[i] = (hex_input.hex[2 * i] << 4) | hex_input.hex[2 * i + 1];
    }

    printf("Converted data: ");
    print_hex(converted_data, converted_data_length);
    printf("\n");

    free(converted_data);

    return EXIT_SUCCESS;
}