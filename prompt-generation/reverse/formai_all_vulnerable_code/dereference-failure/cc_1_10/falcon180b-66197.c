//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
// C Hexadecimal Converter Example Program

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LENGTH 32

int is_valid_hex(char c);
int is_valid_decimal(char c);
int hex_to_dec(char *hex);
char *dec_to_hex(int dec);

int main() {

    char hex[MAX_HEX_LENGTH];
    int dec;

    printf("Enter a hexadecimal number: ");
    fgets(hex, MAX_HEX_LENGTH, stdin);
    hex[strcspn(hex, "\n")] = '\0';

    if (!is_valid_hex(hex[0])) {
        printf("Invalid hexadecimal number\n");
        exit(1);
    }

    dec = hex_to_dec(hex);

    printf("Decimal equivalent: %d\n", dec);
    printf("Hexadecimal equivalent: %s\n", dec_to_hex(dec));

    return 0;
}

int is_valid_hex(char c) {
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int is_valid_decimal(char c) {
    return isdigit(c);
}

int hex_to_dec(char *hex) {
    int dec = 0;
    int i;

    for (i = 0; i < strlen(hex); i++) {
        if (isdigit(hex[i])) {
            dec = dec * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            dec = dec * 16 + hex[i] - 'A' + 10;
        } else {
            dec = dec * 16 + hex[i] - 'a' + 10;
        }
    }

    return dec;
}

char *dec_to_hex(int dec) {
    char *hex = malloc(MAX_HEX_LENGTH * sizeof(char));
    int i;

    sprintf(hex, "%X", dec);

    for (i = strlen(hex) - 1; i >= 0; i--) {
        if (i % 2 == 0) {
            hex[i] = hex[i] + '0';
        } else {
            hex[i] = hex[i] + 'A' - 10;
        }
    }

    return hex;
}