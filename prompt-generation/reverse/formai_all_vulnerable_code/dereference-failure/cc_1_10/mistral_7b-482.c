//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 32
#define MAX_INPUT_SIZE 100

void binary_to_decimal(char binary[], int *decimal) {
    int len = strlen(binary);
    int power = 0;
    int decimal_value = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal_value += pow(2, power);
        power++;
    }

    *decimal = decimal_value;
}

void print_decimal(int decimal) {
    int index = 1;
    int divisor = 10;
    char digits[MAX_DIGITS];

    while (decimal != 0) {
        digits[index++] = (decimal % 10) + '0';
        decimal /= divisor;
        divisor *= 10;
    }

    for (int i = index - 1; i >= 0; i--)
        putchar(digits[i]);
    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary_number>\n", argv[0]);
        return 1;
    }

    char binary[MAX_INPUT_SIZE];
    strcpy(binary, argv[1]);

    int decimal;
    binary_to_decimal(binary, &decimal);

    printf("Binary number: %s\n", binary);
    printf("Decimal value: ");
    print_decimal(decimal);

    return 0;
}