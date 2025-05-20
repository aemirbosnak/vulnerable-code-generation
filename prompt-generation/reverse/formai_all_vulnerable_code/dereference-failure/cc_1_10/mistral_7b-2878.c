//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void print_hex(unsigned char *input, size_t size) {
    size_t i;
    for (i = 0; i < size; ++i) {
        printf("%02X", input[i]);
    }
    putchar('\n');
}

void hex_string_to_binary(const char *hex_string, unsigned char *binary_output, size_t *binary_output_size) {
    size_t hex_string_length = strlen(hex_string);
    size_t binary_output_index = 0;
    unsigned char current_byte = 0;
    int nibble_count = 0;

    for (size_t i = 0; i < hex_string_length; ++i) {
        char hex_character = toupper(hex_string[i]);

        if (isdigit(hex_character)) {
            current_byte *= 16;
            current_byte += (hex_character - '0');
        } else if (isalpha(hex_character)) {
            current_byte *= 16;
            current_byte += (hex_character - 'A' + 10);
        }

        if (nibble_count == 2) {
            binary_output[binary_output_index++] = current_byte;
            *binary_output_size += sizeof(unsigned char);
            current_byte = 0;
            nibble_count = 0;
        } else {
            current_byte >>= 4;
            binary_output[binary_output_index++] = current_byte;
            *binary_output_size += sizeof(unsigned char);
            current_byte = (current_byte << 4) | ((current_byte << 4) | (hex_character - '0') >> 4);
            nibble_count = 1;
        }
    }

    if (nibble_count == 1) {
        binary_output[binary_output_index++] = current_byte;
        *binary_output_size += sizeof(unsigned char);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hexadecimal string> <output binary file>\n", argv[0]);
        return 1;
    }

    size_t input_string_length = strlen(argv[1]);
    unsigned char *binary_output = malloc(input_string_length / 2 * sizeof(unsigned char));
    size_t binary_output_size = 0;

    if (binary_output == NULL) {
        perror("malloc");
        return 1;
    }

    hex_string_to_binary(argv[1], binary_output, &binary_output_size);

    FILE *output_file = fopen(argv[2], "wb");

    if (output_file == NULL) {
        perror("fopen");
        free(binary_output);
        return 1;
    }

    fwrite(binary_output, binary_output_size, 1, output_file);

    fclose(output_file);
    free(binary_output);

    print_hex(binary_output, binary_output_size);

    return 0;
}