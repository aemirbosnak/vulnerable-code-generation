//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_LENGTH 100

int is_valid_hex(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    if (c >= 'A' && c <= 'F') {
        return 1;
    }
    if (c >= 'a' && c <= 'f') {
        return 1;
    }
    return 0;
}

int hex_to_decimal(char* hex) {
    int decimal = 0;
    int i = 0;
    while (i < strlen(hex)) {
        if (is_valid_hex(hex[i])) {
            decimal = decimal * 16 + hex[i] - '0';
        } else {
            decimal = decimal * 16 + hex[i] - 'A' + 10;
        }
        i++;
    }
    return decimal;
}

char* decimal_to_hex(int decimal) {
    char* hex = malloc(MAX_LENGTH * sizeof(char));
    int i = 0;
    int j = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder + 'A' - 10;
        }
        i++;
        decimal /= 16;
    }
    for (int k = 0; k < i / 2; k++) {
        char temp = hex[k];
        hex[k] = hex[i - k - 1];
        hex[i - k - 1] = temp;
    }
    return hex;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <hexadecimal number> <decimal number>\n", argv[0]);
        return 1;
    }
    char* hex = argv[1];
    int decimal = atoi(argv[2]);

    printf("Hexadecimal number: %s\n", hex);
    printf("Decimal number: %d\n", decimal);

    return 0;
}