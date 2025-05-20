//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 10000
#define MAX_DEC_LENGTH 10000

void print_usage(void) {
    printf("Usage:./cyberhex [hexadecimal number]\n");
    printf("Example:./cyberhex 1A2B3C\n");
    exit(1);
}

int is_valid_hex(char c) {
    if (isdigit(c)) {
        return 1;
    } else if (isalpha(c)) {
        if (tolower(c) >= 'a' && tolower(c) <= 'f') {
            return 1;
        }
    }
    return 0;
}

int hex_to_dec(char* hex_str) {
    int i = 0, j = 0, dec_num = 0;
    char dec_str[MAX_DEC_LENGTH];

    while (hex_str[i]) {
        if (is_valid_hex(hex_str[i])) {
            if (isdigit(hex_str[i])) {
                dec_num = dec_num * 16 + hex_str[i] - '0';
            } else {
                dec_num = dec_num * 16 + hex_str[i] - 'a' + 10;
            }
        } else {
            printf("Invalid hexadecimal character '%c'\n", hex_str[i]);
            return 1;
        }
        i++;
    }

    sprintf(dec_str, "%d", dec_num);

    printf("Hexadecimal: %s\n", hex_str);
    printf("Decimal: %s\n", dec_str);

    return 0;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage();
    }

    char hex_str[MAX_HEX_LENGTH];
    strcpy(hex_str, argv[1]);

    hex_to_dec(hex_str);

    return 0;
}