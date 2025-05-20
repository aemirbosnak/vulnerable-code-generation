//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to convert hexadecimal string to decimal integer
int hexToDecimal(char *hex) {
    int decimal = 0;
    int i;
    for (i = 0; i < strlen(hex); i++) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                decimal += hex[i] - '0';
            } else {
                decimal += hex[i] - 'A' + 10;
            }
        } else {
            printf("\nInvalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
    }
    return decimal;
}

// Function to convert decimal integer to hexadecimal string
char *decimalToHex(int decimal) {
    char *hex = malloc(sizeof(char) * 8);
    int i = 0;
    while (decimal > 0) {
        hex[i] = (decimal % 16) + '0';
        if (decimal % 16 > 9) {
            hex[i] += 7;
        }
        decimal /= 16;
        i++;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    char *hex;
    int decimal;

    // Get hexadecimal string from user
    printf("\nEnter hexadecimal string: ");
    scanf("%s", hex);

    // Convert hexadecimal string to decimal integer
    decimal = hexToDecimal(hex);

    // Convert decimal integer to hexadecimal string
    char *result = decimalToHex(decimal);

    // Print result
    printf("\nDecimal equivalent of %s: %s\n", hex, result);

    return 0;
}