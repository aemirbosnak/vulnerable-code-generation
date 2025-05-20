//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void hex_to_decimal(char hex[]) {
    int decimal = 0;
    int base = 1;

    for (int i = 0; hex[i] != '\0'; i++) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * base;
            base *= 16;
        } else if (isalpha(hex[i])) {
            decimal += (hex[i] - 'A' + 10) * base;
            base *= 16;
        }
    }

    printf("%d\n", decimal);
}

void decimal_to_hex(int decimal) {
    char hex[MAX_INPUT_SIZE];
    int index = 0;
    int quotient;

    while (decimal != 0) {
        quotient = decimal % 16;
        if (quotient < 10) {
            hex[index++] = quotient + '0';
            decimal /= 16;
        } else {
            hex[index++] = quotient + 'A' - 10;
            decimal /= 16;
        }
    }

    hex[index] = '\0';
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char hex_input[MAX_INPUT_SIZE];
    int decimal_input;

    if (argc != 3) {
        printf("Usage: %s <hex_input> <decimal_output|decimal_input>\n", argv[0]);
        return 1;
    }

    strcpy(hex_input, argv[1]);

    if (strlen(argv[2]) > 2 || (strlen(argv[2]) == 1 && argv[2][0] == '-')) {
        printf("Invalid argument: %s\n", argv[2]);
        return 1;
    }

    if (argv[2][0] == 'd') {
        sscanf(argv[1], "%d", &decimal_input);
        hex_to_decimal(argv[1]);
        decimal_to_hex(decimal_input);
    } else {
        hex_to_decimal(hex_input);
        sscanf(argv[2], "%d", &decimal_input);
        decimal_to_hex(decimal_input);
    }

    return 0;
}