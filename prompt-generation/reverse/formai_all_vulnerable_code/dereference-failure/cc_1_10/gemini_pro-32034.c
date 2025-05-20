//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int val = 0;

    // Iterate over the hexadecimal string from right to left
    for (int i = len - 1; i >= 0; i--) {
        // Get the digit value of the current character
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else {
            // Invalid character in the hexadecimal string
            return -1;
        }

        // Multiply the digit by the corresponding base and add it to the result
        val += digit * base;
        base *= 16;
    }

    return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
    // Allocate memory for the hexadecimal string
    char *hex = malloc(sizeof(char) * 11);

    // Convert the integer to a hexadecimal string
    int i = 0;
    while (num != 0) {
        int digit = num % 16;
        if (digit < 10) {
            hex[i++] = digit + '0';
        } else {
            hex[i++] = digit - 10 + 'a';
        }
        num /= 16;
    }

    // Reverse the hexadecimal string
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }

    // Terminate the hexadecimal string
    hex[i] = '\0';

    // Return the hexadecimal string
    return hex;
}

// Main function
int main() {
    // Get the hexadecimal string from the user
    char hex_str[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);

    // Convert the hexadecimal string to an integer
    int num = hex_to_int(hex_str);
    if (num == -1) {
        printf("Invalid hexadecimal string\n");
        return 1;
    }

    // Convert the integer to a hexadecimal string
    char *hex_result = int_to_hex(num);

    // Print the hexadecimal result
    printf("Hexadecimal result: %s\n", hex_result);

    // Free the allocated memory
    free(hex_result);

    return 0;
}