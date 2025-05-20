//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function to validate hexadecimal string
int is_valid_hex(const char *hex) {
    int i, len = strlen(hex);
    for (i = 0; i < len; ++i) {
        if (isxdigit(hex[i]) && (hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= 'a' && hex[i] <= 'f'))
            continue;
        else
            return 0;
    }
    return 1;
}

// Function to convert hexadecimal string to decimal number
unsigned long long hex_to_decimal(const char *hex) {
    unsigned long long decimal = 0, temp = 0;
    int len = strlen(hex), i;
    for (i = len - 1; i >= 0; --i) {
        if (isxdigit(hex[i])) {
            temp = (isdigit(hex[i]) ? hex[i] - '0' : hex[i] - 'A' + 10);
            decimal += temp * pow(16, len - i - 1);
        }
    }
    return decimal;
}

int main(int argc, char *argv[]) {
    char hex[MAX_INPUT_LENGTH];
    unsigned long long decimal;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal_string>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);

    if (!is_valid_hex(hex)) {
        printf("Error: Invalid hexadecimal string.\n");
        return 1;
    }

    decimal = hex_to_decimal(hex);
    printf("The decimal equivalent of the hexadecimal number '%s' is %llu.\n", hex, decimal);

    return 0;
}