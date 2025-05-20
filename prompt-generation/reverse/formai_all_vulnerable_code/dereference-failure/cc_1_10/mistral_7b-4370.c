//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

void hex_string_to_decimal(char *hex_string, unsigned long *decimal) {
    unsigned long decimal_value = 0;
    int length = strlen(hex_string);

    for (int i = 0; i < length; i++) {
        char hex_char = tolower(hex_string[i]);

        if ((hex_char >= '0' && hex_char <= '9') || (hex_char >= 'a' && hex_char <= 'f')) {
            int nibble_value;

            if (hex_char >= '0' && hex_char <= '9') {
                nibble_value = hex_char - '0';
            } else {
                nibble_value = hex_char - 'a' + 10;
            }

            decimal_value <<= 4;
            decimal_value += nibble_value;

            if (i < length - 1) {
                char next_hex_char = hex_string[i + 1];

                if (isxdigit(next_hex_char)) {
                    hex_string[i] = next_hex_char;
                    i++;
                }
            }
        } else {
            fprintf(stderr, "Invalid hexadecimal character '%c'\n", hex_char);
            exit(1);
        }
    }

    *decimal = decimal_value;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hexadecimal string>\n", argv[0]);
        exit(1);
    }

    char *hex_string = argv[1];
    unsigned long decimal;

    if (strlen(hex_string) > MAX_INPUT_LENGTH) {
        fprintf(stderr, "Input string too long\n");
        exit(1);
    }

    hex_string_to_decimal(hex_string, &decimal);

    printf("Decimal value of '%s' is %lu\n", hex_string, decimal);

    return 0;
}