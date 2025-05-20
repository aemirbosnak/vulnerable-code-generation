//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *input;
    char *output;
} ConversionResult;

bool is_valid_binary(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i]!= '0' && str[i]!= '1') {
            return false;
        }
    }
    return true;
}

ConversionResult convert_binary_to_decimal(const char *input) {
    int decimal = 0;
    int length = strlen(input);
    for (int i = length - 1; i >= 0; i--) {
        if (input[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    char *output = malloc(sizeof(char) * (MAX_LINE_LENGTH));
    sprintf(output, "Decimal: %d", decimal);
    ConversionResult result = {.input = input,.output = output};
    return result;
}

ConversionResult convert_decimal_to_binary(const char *input) {
    int decimal = atoi(input);
    char *binary = malloc(sizeof(char) * (MAX_LINE_LENGTH));
    while (decimal > 0) {
        int remainder = decimal % 2;
        strcat(binary, remainder == 0? "0" : "1");
        decimal /= 2;
    }
    char *output = malloc(sizeof(char) * (MAX_LINE_LENGTH));
    sprintf(output, "Binary: %s", binary);
    ConversionResult result = {.input = input,.output = output};
    return result;
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter a binary number: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    ConversionResult result = convert_binary_to_decimal(input);
    printf("Result: %s\n", result.output);

    free(result.output);
    free(result.input);

    return 0;
}