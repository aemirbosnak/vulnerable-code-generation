//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 1000000

int main(int argc, char **argv) {
    char hex_str[MAX_HEX_LENGTH];
    char *ptr;
    int i, j, k, hex_len, decimal_len;

    if (argc < 2) {
        printf("Usage: %s hex_string\n", argv[0]);
        exit(1);
    }

    strcpy(hex_str, argv[1]);
    hex_len = strlen(hex_str);

    if (hex_len % 2!= 0) {
        printf("Invalid hexadecimal string\n");
        exit(1);
    }

    decimal_len = hex_len / 2;
    char decimal_str[decimal_len + 1];
    decimal_str[decimal_len] = '\0';

    for (i = 0, j = 0; i < hex_len; i += 2, j++) {
        if (isxdigit(hex_str[i]) && isxdigit(hex_str[i + 1])) {
            if (isupper(hex_str[i])) {
                decimal_str[j] = hex_str[i] - 'A' + 10;
            } else {
                decimal_str[j] = hex_str[i] - 'a' + 10;
            }

            if (isupper(hex_str[i + 1])) {
                decimal_str[j] = (decimal_str[j] << 4) + hex_str[i + 1] - 'A' + 10;
            } else {
                decimal_str[j] = (decimal_str[j] << 4) + hex_str[i + 1] - 'a' + 10;
            }
        } else {
            printf("Invalid hexadecimal string\n");
            exit(1);
        }
    }

    printf("Hexadecimal: %s\n", hex_str);
    printf("Decimal: %s\n", decimal_str);

    return 0;
}