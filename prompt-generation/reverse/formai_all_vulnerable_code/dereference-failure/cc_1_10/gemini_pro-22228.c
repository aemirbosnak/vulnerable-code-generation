//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH (MAX_INPUT_LENGTH * 8)

typedef enum {
    BINARY,
    DECIMAL,
    OCTAL,
    HEXADECIMAL
} number_base_t;

typedef struct {
    char *input;
    size_t input_length;
    number_base_t input_base;
    number_base_t output_base;
    char *output;
    size_t output_length;
} conversion_params_t;

void print_usage(char *program_name) {
    printf("Usage: %s <input> <input_base> <output_base>\n", program_name);
    printf("Where:\n");
    printf("  <input> is the number to be converted.\n");
    printf("  <input_base> is the base of the input number (2, 8, 10, or 16).\n");
    printf("  <output_base> is the base of the output number (2, 8, 10, or 16).\n");
    printf("\nExamples:\n");
    printf("  %s 10101010 2 10\n", program_name);
    printf("  %s 1234 10 16\n", program_name);
    printf("  %s 777 8 10\n", program_name);
    printf("  %s FABC 16 10\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    conversion_params_t params = {
        .input = argv[1],
        .input_length = strlen(argv[1]),
        .input_base = atoi(argv[2]),
        .output_base = atoi(argv[3]),
        .output = malloc(MAX_OUTPUT_LENGTH),
        .output_length = 0
    };

    if (params.input_base < 2 || params.input_base > 16 || params.output_base < 2 || params.output_base > 16) {
        fprintf(stderr, "Error: Invalid input or output base.\n");
        return EXIT_FAILURE;
    }

    if (convert_number(&params) == -1) {
        fprintf(stderr, "Error: Conversion failed.\n");
        return EXIT_FAILURE;
    }

    printf("%s\n", params.output);

    free(params.output);

    return EXIT_SUCCESS;
}

int convert_number(conversion_params_t *params) {
    int input_value = 0;
    int output_value = 0;
    int i, j, k;

    // Convert the input number to base 10.

    for (i = 0; i < params->input_length; i++) {
        char c = params->input[i];
        int digit_value;

        if (isdigit(c)) {
            digit_value = c - '0';
        } else if (isupper(c)) {
            digit_value = c - 'A' + 10;
        } else if (islower(c)) {
            digit_value = c - 'a' + 10;
        } else {
            return -1;
        }

        if (digit_value < 0 || digit_value >= params->input_base) {
            return -1;
        }

        input_value *= params->input_base;
        input_value += digit_value;
    }

    // Convert the base 10 number to the output base.

    i = 0;
    while (input_value > 0) {
        output_value += (input_value % params->output_base) * pow(params->output_base, i);
        input_value /= params->output_base;
        i++;
    }

    // Convert the output value to a string.

    j = 0;
    do {
        params->output[j++] = "0123456789ABCDEF"[output_value % params->output_base];
        output_value /= params->output_base;
    } while (output_value > 0);

    // Reverse the output string.

    for (i = 0, j = strlen(params->output) - 1; i < j; i++, j--) {
        char c = params->output[i];
        params->output[i] = params->output[j];
        params->output[j] = c;
    }

    params->output_length = strlen(params->output);

    return 0;
}