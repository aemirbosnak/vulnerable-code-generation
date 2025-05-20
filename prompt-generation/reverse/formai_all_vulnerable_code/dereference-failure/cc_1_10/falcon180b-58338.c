//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_HEX_LEN 32

// Function to convert a hexadecimal string to a decimal integer
int hex_to_dec(char *hex) {
    int hex_val = 0, base = 1, len = strlen(hex);
    for (int i = len - 1; i >= 0; i--, base *= 16) {
        if (isdigit(hex[i])) {
            hex_val += hex[i] - '0';
        } else {
            hex_val += toupper(hex[i]) - 'A' + 10;
        }
    }
    return hex_val;
}

// Function to convert a decimal integer to a hexadecimal string
void dec_to_hex(int dec, char *hex) {
    sprintf(hex, "%X", dec);
}

// Function to validate hexadecimal input
int is_valid_hex(char *hex) {
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        if (!isxdigit(hex[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hexadecimal_number> <decimal_number>\n", argv[0]);
        return 1;
    }

    char hex[MAX_HEX_LEN] = {0};
    strcpy(hex, argv[1]);

    int dec = hex_to_dec(hex);
    if (dec == -1) {
        printf("Invalid hexadecimal number\n");
        return 1;
    }

    char dec_hex[MAX_HEX_LEN] = {0};
    dec_to_hex(dec, dec_hex);

    printf("Hexadecimal number: %s\n", hex);
    printf("Decimal number: %s\n", dec_hex);

    return 0;
}