//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_CHARS 16
#define MAX_DEC_DIGITS 11

void print_usage_and_exit() {
    printf("-----------------------------------------------------\n");
    printf("|                     HEX2DEC                        |\n");
    printf("|                  A Hexadecimal to Decimal Converter |\n");
    printf("-----------------------------------------------------\n");
    printf("Usage: %s <hexadecimal_number>\n", __FILE__);
    exit(EXIT_FAILURE);
}

int hex_char_to_decimal(char hex_char) {
    if (isdigit(hex_char)) {
        return hex_char - '0';
    }
    if (isalpha(hex_char)) {
        return hex_char - 'A' + 10;
    }
    fprintf(stderr, "Invalid hexadecimal character: %c\n", hex_char);
    print_usage_and_exit();
}

void hex_string_to_decimal(const char *hex_str, unsigned long long *decimal) {
    unsigned long long result = 0;
    int length = strlen(hex_str);

    for (int i = length - 1; i >= 0; --i) {
        char hex_char = hex_str[i];
        int decimal_value = hex_char_to_decimal(hex_char);
        result = result * 16 + decimal_value;
    }

    *decimal = result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage_and_exit();
    }

    unsigned long long decimal_number;
    hex_string_to_decimal(argv[1], &decimal_number);

    printf("The decimal equivalent of the hexadecimal number %s is: %llu\n", argv[1], decimal_number);

    return EXIT_SUCCESS;
}