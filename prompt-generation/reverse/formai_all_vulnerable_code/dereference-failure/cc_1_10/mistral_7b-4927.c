//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFER_SIZE 100

void convert_hex_to_decimal(char *hex) {
    int decimal = 0;
    int power = 0;

    for (int i = strlen(hex) - 1; i >= 0; i--) {
        if (isxdigit(hex[i])) {
            int digit = isdigit(hex[i]) ? hex[i] - '0' : hex[i] - 'A' + 10;
            decimal += digit * (16 << power);
            power++;
        }
    }

    printf("Decimal representation of %s is %d\n", hex, decimal);
}

void convert_decimal_to_hex(int decimal) {
    char hex[BUFFER_SIZE];
    int index = 0;
    int divisor = 16;

    while (decimal > 0) {
        int digit = decimal % divisor;
        if (digit < 10) {
            hex[index++] = digit + '0';
        } else {
            hex[index++] = digit + 'A' - 10;
        }
        decimal /= divisor;
    }

    for (int i = index; i < BUFFER_SIZE; i++) {
        hex[i] = '0';
    }

    hex[BUFFER_SIZE - 1] = '\0';

    printf("Hexadecimal representation of %d is %s\n", decimal, hex);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hexadecimal number or decimal number> <convert_to_hex or convert_to_decimal>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char *convert_to = argv[2];

    if (strcmp(convert_to, "convert_to_hex") == 0) {
        int decimal = atoi(input);
        convert_decimal_to_hex(decimal);
    } else if (strcmp(convert_to, "convert_to_decimal") == 0) {
        convert_hex_to_decimal(input);
    } else {
        printf("Invalid option: %s\n", convert_to);
        return 1;
    }

    return 0;
}