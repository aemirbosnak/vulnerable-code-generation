//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

void hex_to_decimal(const char *hex_str, int *decimal) {
    int len = strlen(hex_str);
    int i, j;
    int decimal_value = 0;

    for (i = len - 1, j = 0; i >= 0; i--, j += 2) {
        char hex_digit = hex_str[i];
        int digit;

        if (isdigit(hex_digit)) {
            digit = hex_digit - '0';
        } else if (isalpha(hex_digit)) {
            digit = hex_digit - 'A' + 10;
        } else {
            printf("Invalid hexadecimal digit: %c\n", hex_digit);
            exit(EXIT_FAILURE);
        }

        decimal_value += digit << j;
    }

    *decimal = decimal_value;
}

void decimal_to_hex(int decimal, char *hex_str, int *length) {
    char *hex_digits = "0123456789ABCDEF";
    char *hex_str_ptr = hex_str;
    int decimal_copy = decimal;
    int i;

    while (decimal_copy != 0) {
        int digit = decimal_copy % 16;
        decimal_copy /= 16;

        *hex_str_ptr++ = hex_digits[digit];
    }

    if (decimal < 0) {
        *hex_str_ptr++ = '-';
        decimal_copy = -decimal;

        while (decimal_copy != 0) {
            int digit = decimal_copy % 16;
            decimal_copy /= 16;

            *hex_str_ptr++ = hex_digits[digit];
        }
    }

    *hex_str_ptr = '\0';
    *length = strlen(hex_str);
}

int main() {
    char hex_str[MAX_LENGTH];
    int decimal, decimal_value;

    printf("Enter hexadecimal string: ");
    fgets(hex_str, sizeof(hex_str), stdin);
    hex_str[strcspn(hex_str, "\n")] = '\0';

    hex_to_decimal(hex_str, &decimal_value);
    decimal = decimal_value;

    char hex_str_out[MAX_LENGTH];
    int length;

    printf("Decimal value: %d\n", decimal);
    decimal_to_hex(decimal, hex_str_out, &length);
    printf("Hexadecimal value: %s\n", hex_str_out);

    return EXIT_SUCCESS;
}