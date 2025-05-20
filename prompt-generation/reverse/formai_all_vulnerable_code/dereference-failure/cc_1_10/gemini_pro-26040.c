//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to decimal
int hex_to_decimal(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 'A' + 10) * base;
            base *= 16;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 'a' + 10) * base;
            base *= 16;
        }
    }

    return dec;
}

// Function to convert a decimal number to hexadecimal
char *decimal_to_hex(int dec) {
    char *hex = (char *)malloc(sizeof(char) * 100);
    int i = 0;

    while (dec != 0) {
        int temp = dec % 16;

        if (temp < 10) {
            hex[i++] = temp + '0';
        } else {
            hex[i++] = temp + 'A' - 10;
        }

        dec /= 16;
    }

    hex[i] = '\0';

    // Reverse the string
    int len = strlen(hex);
    for (int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }

    return hex;
}

int main() {
    // Get the hexadecimal number from the user
    char hex[100];
    printf("Enter the hexadecimal number: ");
    scanf("%s", hex);

    // Convert the hexadecimal number to decimal
    int dec = hex_to_decimal(hex);

    // Print the decimal number
    printf("The decimal equivalent of %s is: %d\n", hex, dec);

    // Convert the decimal number to hexadecimal
    char *hex_result = decimal_to_hex(dec);

    // Print the hexadecimal result
    printf("The hexadecimal equivalent of %d is: %s\n", dec, hex_result);

    return 0;
}