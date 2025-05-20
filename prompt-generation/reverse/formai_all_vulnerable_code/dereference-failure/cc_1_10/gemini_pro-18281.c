//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int len = strlen(hex);
    int base = 1;
    int val = 0;

    for (int i = len - 1; i >= 0; i--) {
        // Get the digit value
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else {
            return -1; // Invalid hexadecimal digit
        }

        // Add the digit value to the result
        val += digit * base;
        base *= 16;
    }

    return val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num) {
    char *hex = malloc(sizeof(char) * 11); // 10 digits + null terminator
    int i = 0;

    while (num != 0) {
        // Get the hexadecimal digit
        int digit = num % 16;
        if (digit < 10) {
            hex[i++] = digit + '0';
        } else {
            hex[i++] = digit - 10 + 'a';
        }

        // Divide the number by 16
        num /= 16;
    }

    hex[i] = '\0'; // Add null terminator

    // Reverse the hexadecimal string
    int j = 0;
    int k = i - 1;
    while (j < k) {
        char temp = hex[j];
        hex[j] = hex[k];
        hex[k] = temp;
        j++;
        k--;
    }

    return hex;
}

int main() {
    // Test the hex_to_int function
    char *hex = "10a";
    int num = hex_to_int(hex);
    printf("Hexadecimal: %s\n", hex);
    printf("Integer: %d\n\n", num);

    // Test the int_to_hex function
    num = 42;
    hex = int_to_hex(num);
    printf("Integer: %d\n", num);
    printf("Hexadecimal: %s\n", hex);

    free(hex); // Free the memory allocated for the hexadecimal string

    return 0;
}