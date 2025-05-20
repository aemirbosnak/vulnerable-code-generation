//FormAI DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 16

void print_binary(unsigned int decimal);
char* convert_decimal_to_binary(unsigned int decimal);
unsigned int convert_binary_to_decimal(char* binary);

int main() {
    unsigned int decimal_input;
    char binary_input[MAX_BINARY_LENGTH];
    char c;

    printf("Enter a decimal number: ");
    scanf("%u", &decimal_input);
    print_binary(decimal_input);

    printf("Enter a binary number (up to %d bits): ", MAX_BINARY_LENGTH);
    scanf("%s", binary_input);
    printf("Decimal equivalent: %u\n", convert_binary_to_decimal(binary_input));

    return 0;
}

void print_binary(unsigned int decimal) {
    char* binary = convert_decimal_to_binary(decimal);
    printf("Binary equivalent: %s\n", binary);
    free(binary);
}

char* convert_decimal_to_binary(unsigned int decimal) {
    char* binary = (char*) malloc((MAX_BINARY_LENGTH + 1) * sizeof(char));
    binary[MAX_BINARY_LENGTH] = '\0';

    for (int i = MAX_BINARY_LENGTH - 1; i >= 0; i--) {
        if (decimal % 2 == 0) {
            binary[i] = '0';
        } else {
            binary[i] = '1';
        }
        decimal /= 2;
    }

    return binary;
}

unsigned int convert_binary_to_decimal(char* binary) {
    int length = strlen(binary);
    unsigned int decimal = 0;

    for (int i = length - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            decimal += 1 << j;
        }
    }

    return decimal;
}