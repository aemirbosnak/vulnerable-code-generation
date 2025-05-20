//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_HEX_STRING_LENGTH 1000

int hex_to_int(char* hex_str) {
    int value = 0;
    int i = 0;
    while (hex_str[i]!= '\0') {
        if (isxdigit(hex_str[i])) {
            value = value * 16 + (hex_str[i] - '0');
        } else if (isupper(hex_str[i])) {
            value = value * 16 + (hex_str[i] - 'A' + 10);
        } else {
            value = value * 16 + (hex_str[i] - 'a' + 10);
        }
        i++;
    }
    return value;
}

void int_to_hex(int decimal, char* hex_str) {
    int i = 0;
    while (decimal!= 0) {
        hex_str[i] = (decimal % 16) + '0';
        if (decimal % 16 < 10) {
            hex_str[i] += '0';
        }
        decimal /= 16;
        i++;
    }
    hex_str[i] = '\0';
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        exit(1);
    }

    char hex_str[MAX_HEX_STRING_LENGTH] = {0};
    strcpy(hex_str, argv[1]);

    int decimal = hex_to_int(hex_str);
    printf("Decimal equivalent: %d\n", decimal);

    char result[MAX_HEX_STRING_LENGTH] = {0};
    int_to_hex(decimal, result);
    printf("Hexadecimal equivalent: %s\n", result);

    return 0;
}