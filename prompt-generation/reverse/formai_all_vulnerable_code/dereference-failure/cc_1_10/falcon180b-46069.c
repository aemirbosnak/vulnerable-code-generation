//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

void convert_hex_to_decimal(char *hex_string, int *decimal_value) {
    int i, j, decimal = 0, power = 0;
    for (i = strlen(hex_string) - 1, j = 0; i >= 0; i--, j++) {
        if (isdigit(hex_string[i])) {
            decimal += (int) hex_string[i] - 48;
        } else {
            decimal += (int) hex_string[i] - 55;
        }
        power = (int) pow(16, j);
        decimal += power;
    }
    *decimal_value = decimal;
}

void convert_decimal_to_hex(int decimal_value, char *hex_string) {
    char hex_buffer[MAX_HEX_LENGTH];
    int i, j, remainder;
    sprintf(hex_buffer, "%X", decimal_value);
    for (i = 0, j = strlen(hex_buffer) - 1; i < strlen(hex_buffer); i++, j--) {
        strncat(hex_string, &hex_buffer[j], 1);
    }
}

int main(int argc, char *argv[]) {
    char hex_string[MAX_HEX_LENGTH], decimal_string[20];
    int decimal_value;

    if (argc!= 3) {
        printf("Usage: %s <hex_value> <decimal_value>\n", argv[0]);
        return 1;
    }

    strcpy(hex_string, argv[1]);
    strcpy(decimal_string, argv[2]);

    convert_hex_to_decimal(hex_string, &decimal_value);
    sprintf(hex_string, "%X", decimal_value);

    printf("Hexadecimal: %s\n", hex_string);
    printf("Decimal: %s\n", decimal_string);

    return 0;
}