//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char *hex_string = argv[1];
    char *dec_string = argv[2];
    int hex_len = strlen(hex_string);
    int dec_len = strlen(dec_string);
    int i;
    int j = 0;
    int k = strlen(dec_string) - 1;
    int num = 0;
    int digit = 0;
    int power = 0;
    int decimal = 0;
    int hexadecimal = 0;
    int remainder = 0;
    int quotient = 0;

    for (i = 0; i < hex_len; i++) {
        if (isxdigit(hex_string[i])) {
            digit = tolower(hex_string[i]) - '0';
            if (digit > 9) {
                digit -= 7;
            }
            num = (num << 4) | digit;
            power++;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex_string[i]);
            return 1;
        }
    }

    if (power == 0) {
        printf("Empty hexadecimal string\n");
        return 1;
    }

    for (i = 0; i < dec_len; i++) {
        if (isdigit(dec_string[i])) {
            decimal = (decimal << 3) | (dec_string[i] - '0');
            quotient++;
        } else {
            printf("Invalid decimal character: %c\n", dec_string[i]);
            return 1;
        }
    }

    if (quotient == 0) {
        printf("Empty decimal string\n");
        return 1;
    }

    for (i = 0; i < power; i++) {
        remainder = num % 10;
        num /= 10;
        hexadecimal = (hexadecimal << 4) | remainder;
    }

    for (i = 0; i < quotient; i++) {
        remainder = decimal % 10;
        decimal /= 10;
        hexadecimal = (hexadecimal << 3) | remainder;
    }

    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", hexadecimal);

    return 0;
}