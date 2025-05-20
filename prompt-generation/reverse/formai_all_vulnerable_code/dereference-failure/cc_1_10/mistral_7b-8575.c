//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_OUTPUT_SIZE 33

void print_hex(unsigned char hex) {
    if (hex >= 0x0 && hex <= 0x9) {
        printf("%c", hex + '0');
    } else if (hex >= 0xA && hex <= 0xF) {
        printf("%c", hex + 'A' - 0x0A);
    } else {
        printf("Invalid hexadecimal character: %#x", hex);
        exit(EXIT_FAILURE);
    }
}

int hex_to_decimal(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else {
        fprintf(stderr, "Invalid hexadecimal character: %c\n", hex);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    unsigned char *output;
    size_t input_length, output_length;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(input, argv[1]);

    // Remove leading '0x'
    if (strlen(input) >= 2 && input[0] == '0' && input[1] == 'x') {
        memmove(input, input + 2, strlen(input) - 2);
    }

    input_length = strlen(input);

    // Calculate output length
    output_length = input_length / 2;
    if (input_length % 2 == 1) {
        output_length++;
    }

    // Allocate memory for output
    output = malloc(output_length);

    // Convert hex to binary
    for (size_t i = 0; i < input_length; i += 2) {
        unsigned char byte;

        byte = (hex_to_decimal(input[i]) << 4) | hex_to_decimal(input[i + 1]);

        *output++ = byte;
    }

    printf("Converted hexadecimal string '%s' to binary:\n", input);
    printf("0b");

    for (size_t i = 0; i < output_length; i++) {
        print_hex(*output++);

        for (int j = 7; j >= 0; j--) {
            print_hex((*output - 1) & (1 << j) ? '1' : '0');
        }

        if (i < output_length - 1) {
            printf(" ");
        }
    }

    printf("\n");

    free(output);

    return EXIT_SUCCESS;
}