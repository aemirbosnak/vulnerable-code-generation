//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            val += (hex[i] - 'a' + 10) * base;
        }
        base *= 16;
    }

    return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
    int len = 0;
    int temp = num;

    // Find the length of the hexadecimal string
    while (temp != 0) {
        len++;
        temp /= 16;
    }

    // Allocate memory for the hexadecimal string
    char *hex = malloc(len + 1);

    // Convert the integer to a hexadecimal string
    for (int i = len - 1; i >= 0; i--) {
        int rem = num % 16;
        if (rem >= 0 && rem <= 9) {
            hex[i] = rem + '0';
        } else if (rem >= 10 && rem <= 15) {
            hex[i] = rem - 10 + 'A';
        }
        num /= 16;
    }

    hex[len] = '\0';

    return hex;
}

int main() {
    // Let's play a game! Convert between hexadecimal and decimal.
    // First, let's convert hexadecimal to decimal.
    char *hex = "ABCDEF";
    int decimal = hex_to_int(hex);
    printf("The hexadecimal number %s is equal to the decimal number %d.\n", hex, decimal);

    // Now, let's convert decimal to hexadecimal.
    int num = 12345;
    char *hex2 = int_to_hex(num);
    printf("The decimal number %d is equal to the hexadecimal number %s.\n", num, hex2);

    // Yay! We did it!
    return 0;
}