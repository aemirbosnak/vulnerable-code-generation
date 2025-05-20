//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal digit to its decimal equivalent
int hex_to_dec(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    } else {
        // Invalid hexadecimal digit
        return -1;
    }
}

// Function to convert a hexadecimal number to its decimal equivalent
int hex_to_dec_num(char *hex_num) {
    int len = strlen(hex_num);
    int dec_num = 0;
    int base = 1;

    for (int i = len - 1; i >= 0; i--) {
        int hex_digit = hex_to_dec(hex_num[i]);
        if (hex_digit == -1) {
            // Invalid hexadecimal number
            return -1;
        }
        dec_num += hex_digit * base;
        base *= 16;
    }

    return dec_num;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *dec_to_hex(int dec_num) {
    char *hex_num = malloc(sizeof(char) * 100);
    int i = 0;

    while (dec_num != 0) {
        int hex_digit = dec_num % 16;
        if (hex_digit < 10) {
            hex_num[i++] = '0' + hex_digit;
        } else {
            hex_num[i++] = 'a' + hex_digit - 10;
        }
        dec_num /= 16;
    }

    hex_num[i] = '\0';

    // Reverse the hexadecimal string
    int len = strlen(hex_num);
    for (int j = 0; j < len / 2; j++) {
        char temp = hex_num[j];
        hex_num[j] = hex_num[len - j - 1];
        hex_num[len - j - 1] = temp;
    }

    return hex_num;
}

int main() {
    // Get the hexadecimal number from the user
    char hex_num[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    // Convert the hexadecimal number to its decimal equivalent
    int dec_num = hex_to_dec_num(hex_num);
    if (dec_num == -1) {
        printf("Invalid hexadecimal number\n");
        return 1;
    }

    // Print the decimal equivalent of the hexadecimal number
    printf("Decimal equivalent: %d\n", dec_num);

    // Convert the decimal number back to its hexadecimal equivalent
    char *hex_num_2 = dec_to_hex(dec_num);

    // Print the hexadecimal equivalent of the decimal number
    printf("Hexadecimal equivalent: %s\n", hex_num_2);

    return 0;
}