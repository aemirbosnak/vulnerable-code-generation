//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char hex_chars[] = "0123456789abcdef";

char *decimal_to_hexadecimal(int decimal) {
    char *hexadecimal = malloc(sizeof(char) * 9); // 8 characters plus null terminator
    int index = 0;
    while (decimal!= 0) {
        int rem = decimal % 16;
        if (rem < 10) {
            hexadecimal[index++] = rem + '0';
        } else {
            hexadecimal[index++] = rem + 'A' - 10;
        }
        decimal /= 16;
    }
    hexadecimal[index] = '\0';
    return hexadecimal;
}

int hexadecimal_to_decimal(char *hexadecimal) {
    int decimal = 0;
    int length = strlen(hexadecimal);
    for (int i = 0; i < length; i++) {
        char c = toupper(hexadecimal[i]);
        if (c >= '0' && c <= '9') {
            decimal = decimal * 16 + c - '0';
        } else if (c >= 'A' && c <= 'F') {
            decimal = decimal * 16 + c - 'A' + 10;
        } else {
            printf("Error: Invalid hexadecimal character '%c'\n", c);
            exit(1);
        }
    }
    return decimal;
}

int main() {
    char input[100];
    printf("Enter a decimal number: ");
    scanf("%s", input);
    char *hexadecimal = decimal_to_hexadecimal(atoi(input));
    printf("Hexadecimal: %s\n", hexadecimal);
    int decimal = hexadecimal_to_decimal(hexadecimal);
    printf("Decimal: %d\n", decimal);
    free(hexadecimal);
    return 0;
}