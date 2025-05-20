//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void hexadecimal_converter(char* input_string, char* output_string) {
    int input_length = strlen(input_string);
    int output_length = 0;

    // Check if input string is valid hexadecimal
    for (int i = 0; i < input_length; i++) {
        if (!isxdigit(input_string[i])) {
            printf("Error: Input string is not valid hexadecimal.\n");
            exit(1);
        }
    }

    // Convert input string to uppercase
    for (int i = 0; i < input_length; i++) {
        if (isxdigit(input_string[i])) {
            input_string[i] = toupper(input_string[i]);
        }
    }

    // Convert hexadecimal to decimal
    int decimal_value = 0;
    for (int i = input_length - 1; i >= 0; i--) {
        int digit_value = 0;
        if (isdigit(input_string[i])) {
            digit_value = input_string[i] - '0';
        } else {
            digit_value = input_string[i] - 'A' + 10;
        }
        decimal_value += digit_value * pow(16, input_length - 1 - i);
    }

    // Convert decimal to binary
    char binary_value[MAX_SIZE];
    sprintf(binary_value, "%d", decimal_value);

    // Convert binary to hexadecimal
    output_string = malloc(MAX_SIZE * sizeof(char));
    sprintf(output_string, "%X", decimal_value);

    printf("Input: %s\n", input_string);
    printf("Output: %s\n", output_string);
}

int main() {
    char input_string[MAX_SIZE];
    char output_string[MAX_SIZE];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input_string);

    hexadecimal_converter(input_string, output_string);

    return 0;
}