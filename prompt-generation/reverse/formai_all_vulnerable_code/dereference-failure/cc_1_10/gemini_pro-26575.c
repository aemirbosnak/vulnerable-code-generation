//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef enum {BINARY = 1, DECIMAL} num_type_t;

/**
 * Converts a string representation of a binary number to a decimal number.
 *
 * @param binary_str The string representation of the binary number.
 * @return The decimal representation of the binary number, or -1 if the string is not a valid binary number.
 */
int binary_to_decimal(char *binary_str) {
    int decimal_num = 0;
    int len = strlen(binary_str);
    for (int i = 0; i < len; i++) {
        if (binary_str[i] != '0' && binary_str[i] != '1') {
            return -1;
        }
        decimal_num *= 2;
        decimal_num += binary_str[i] - '0';
    }
    return decimal_num;
}

/**
 * Converts a decimal number to a string representation of a binary number.
 *
 * @param decimal_num The decimal number.
 * @return The string representation of the binary number.
 */
char *decimal_to_binary(int decimal_num) {
    int len = 32; // Assuming the maximum decimal number is 32 bits
    char *binary_str = malloc(len + 1);
    binary_str[len] = '\0';
    int i = len - 1;
    while (decimal_num > 0) {
        binary_str[i] = (decimal_num % 2) + '0';
        decimal_num /= 2;
        i--;
    }
    return binary_str;
}

/**
 * Prints the usage information for the program.
 */
void print_usage() {
    printf("Usage: binary_converter <input_type> <input_value>\n");
    printf("Where <input_type> is either \"binary\" or \"decimal\".\n");
    printf("And <input_value> is the value to be converted.\n");
}

/**
 * Main function.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 * @return 0 if successful, 1 otherwise.
 */
int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *input_type_str = argv[1];
    char *input_value_str = argv[2];

    num_type_t input_type;
    if (strcmp(input_type_str, "binary") == 0) {
        input_type = BINARY;
    } else if (strcmp(input_type_str, "decimal") == 0) {
        input_type = DECIMAL;
    } else {
        printf("Invalid input type: %s\n", input_type_str);
        print_usage();
        return 1;
    }

    int input_value;
    if (input_type == BINARY) {
        input_value = binary_to_decimal(input_value_str);
        if (input_value == -1) {
            printf("Invalid binary number: %s\n", input_value_str);
            return 1;
        }
    } else if (input_type == DECIMAL) {
        input_value = atoi(input_value_str);
        if (input_value < 0) {
            printf("Invalid decimal number: %s\n", input_value_str);
            return 1;
        }
    }

    char *output_value_str;
    if (input_type == BINARY) {
        output_value_str = decimal_to_binary(input_value);
    } else if (input_type == DECIMAL) {
        output_value_str = decimal_to_binary(input_value);
    }

    printf("%s\n", output_value_str);

    return 0;
}