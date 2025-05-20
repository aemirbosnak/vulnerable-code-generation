//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000

int hex_to_dec(char *hex) {
    int dec = 0;
    int hex_digit = 0;
    int i = strlen(hex) - 1;

    while (i >= 0) {
        hex_digit = tolower(hex[i]) - '0';
        if (hex_digit < 0 || hex_digit > 9) {
            hex_digit = tolower(hex[i]) - 'a' + 10;
        }
        dec += hex_digit * pow(16, strlen(hex) - 1 - i);
        i--;
    }

    return dec;
}

char *dec_to_hex(int dec) {
    char *hex = malloc(MAX_HEX_LENGTH * sizeof(char));
    int i = MAX_HEX_LENGTH - 1;
    while (dec > 0) {
        int hex_digit = dec % 16;
        if (hex_digit < 10) {
            hex[i--] = hex_digit + '0';
        } else {
            hex[i--] = hex_digit + 'A';
        }
        dec /= 16;
    }
    hex[i] = '\0';
    return hex;
}

int main() {
    char input[MAX_HEX_LENGTH];
    char *dec_hex;
    int dec_val;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    dec_val = hex_to_dec(input);
    dec_hex = dec_to_hex(dec_val);

    printf("Decimal equivalent: %s\n", dec_hex);

    free(dec_hex);
    return 0;
}