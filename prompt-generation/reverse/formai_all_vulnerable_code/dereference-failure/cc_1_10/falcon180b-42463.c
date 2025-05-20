//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_HEX_CHARS 8
#define MAX_BIN_CHARS 33

char *hex_to_bin(char *hex) {
    char *bin = (char *) malloc(MAX_BIN_CHARS * sizeof(char));
    int bin_len = 0;
    bool is_hex = true;

    for (int i = 0; i < strlen(hex); i++) {
        if (!isxdigit(hex[i])) {
            is_hex = false;
            break;
        }

        if (isdigit(hex[i])) {
            bin[bin_len++] = hex[i];
        } else {
            bin[bin_len++] = hex[i] - 'A' + 10;
        }
    }

    if (!is_hex) {
        sprintf(bin, "Invalid hexadecimal input");
    }

    return bin;
}

char *bin_to_hex(char *bin) {
    char *hex = (char *) malloc(MAX_HEX_CHARS * sizeof(char));
    int hex_len = 0;

    for (int i = 0; i < strlen(bin); i++) {
        if (!isdigit(bin[i])) {
            sprintf(hex, "Invalid binary input");
            return hex;
        }

        if (hex_len >= MAX_HEX_CHARS) {
            sprintf(hex, "Binary input too long");
            return hex;
        }

        if (bin[i] == '0') {
            hex[hex_len++] = '0';
        } else if (bin[i] == '1') {
            hex[hex_len++] = '1';
        } else {
            sprintf(hex, "Invalid binary input");
            return hex;
        }
    }

    return hex;
}

int main() {
    char *hex = "1A2B3C4D5E6F";
    char *bin = hex_to_bin(hex);
    char *hex_back = bin_to_hex(bin);

    printf("Hexadecimal: %s\n", hex);
    printf("Binary: %s\n", bin);
    printf("Hexadecimal (converted back): %s\n", hex_back);

    return 0;
}