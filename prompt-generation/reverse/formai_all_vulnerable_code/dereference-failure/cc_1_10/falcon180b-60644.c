//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LENGTH 32
#define MAX_BIN_LENGTH 8

int is_valid_binary(char* binary) {
    int i = 0;
    while (binary[i]) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_valid_decimal(char* decimal) {
    int i = 0;
    while (decimal[i]) {
        if (!isdigit(decimal[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int decimal_to_binary(char* decimal, char* binary) {
    int i = 0, j = 0;
    while (decimal[i]) {
        binary[j++] = decimal[i++] - '0';
    }
    binary[j] = '\0';
    return strlen(binary);
}

int binary_to_decimal(char* binary) {
    int decimal = 0, i = 0;
    while (binary[i]) {
        decimal = decimal * 2 + binary[i++] - '0';
    }
    return decimal;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <decimal|binary> <number>\n", argv[0]);
        return 1;
    }

    char* input = argv[1];
    char* number = argv[2];

    if (strcmp(input, "decimal") == 0) {
        if (!is_valid_decimal(number)) {
            printf("Invalid decimal number.\n");
            return 1;
        }

        char binary[MAX_BIN_LENGTH];
        int binary_length = decimal_to_binary(number, binary);

        printf("Binary: ");
        for (int i = binary_length - 1; i >= 0; i--) {
            printf("%c", binary[i]);
        }
        printf("\n");
    } else if (strcmp(input, "binary") == 0) {
        if (!is_valid_binary(number)) {
            printf("Invalid binary number.\n");
            return 1;
        }

        int decimal = binary_to_decimal(number);

        printf("Decimal: %d\n", decimal);
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    return 0;
}