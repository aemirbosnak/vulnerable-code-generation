//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(const char *hex_string) {
    int len = strlen(hex_string);
    int base = 1;
    int value = 0;

    for (int i = len - 1; i >= 0; i--) {
        char c = hex_string[i];
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            return -1;  // Invalid character in hex string
        }

        value += digit * base;
        base *= 16;
    }

    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int value) {
    char *hex_string = malloc(11);  // 10 characters for the hex string + 1 for the null-terminator
    int i = 0;

    do {
        int digit = value % 16;
        char c;

        if (digit < 10) {
            c = '0' + digit;
        } else {
            c = 'a' + (digit - 10);
        }

        hex_string[i++] = c;
        value /= 16;
    } while (value > 0);

    hex_string[i] = '\0';  // Null-terminate the string

    return hex_string;
}

// Main function
int main() {
    // Initialize a hexadecimal string and an integer
    char hex_string[] = "12345";
    int value = 0x12345;

    // Convert the hexadecimal string to an integer
    int converted_value = hex_to_int(hex_string);

    // Check if the conversion was successful
    if (converted_value == -1) {
        printf("Invalid hexadecimal string\n");
        return -1;
    }

    // Convert the integer to a hexadecimal string
    char *converted_hex_string = int_to_hex(value);

    // Print the original and converted values
    printf("Original hexadecimal string: %s\n", hex_string);
    printf("Converted integer: %d\n", converted_value);
    printf("Converted hexadecimal string: %s\n", converted_hex_string);

    // Free the allocated memory
    free(converted_hex_string);

    return 0;
}