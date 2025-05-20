//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define MAX_HEX_CHARS 16

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal_string>\n", argv[0]);
        return 1;
    }

    char hex_str[MAX_HEX_CHARS];
    strcpy(hex_str, argv[1]);

    // Convert hexadecimal string to uppercase
    for (int i = 0; i < strlen(hex_str); i++) {
        if (isxdigit(hex_str[i])) {
            hex_str[i] = toupper(hex_str[i]);
        }
    }

    // Check if input string is a valid hexadecimal string
    if (!is_valid_hex(hex_str)) {
        printf("Invalid hexadecimal string\n");
        return 1;
    }

    // Convert hexadecimal to decimal
    int decimal = hex_to_dec(hex_str);

    // Convert decimal to binary
    char binary[33];
    sprintf(binary, "%032b", decimal);

    // Print results
    printf("Hexadecimal: %s\n", hex_str);
    printf("Decimal: %d\n", decimal);
    printf("Binary: %s\n", binary);

    return 0;
}

// Function to check if input string is a valid hexadecimal string
int is_valid_hex(char *hex_str) {
    for (int i = 0; i < strlen(hex_str); i++) {
        if (!isxdigit(hex_str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert hexadecimal string to decimal
int hex_to_dec(char *hex_str) {
    int decimal = 0;
    int len = strlen(hex_str);
    for (int i = 0; i < len; i++) {
        if (isdigit(hex_str[i])) {
            decimal = decimal * 16 + hex_str[i] - '0';
        } else {
            decimal = decimal * 16 + hex_str[i] - 'A' + 10;
        }
    }
    return decimal;
}