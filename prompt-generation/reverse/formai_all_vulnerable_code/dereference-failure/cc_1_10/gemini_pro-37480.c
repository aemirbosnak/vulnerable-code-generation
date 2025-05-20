//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex_str) {
    int i = 0;
    int len = strlen(hex_str);
    int base = 1;
    int dec_num = 0;

    // Iterate through the hexadecimal string in reverse order
    for (i = len - 1; i >= 0; i--) {
        // Convert the current character to its corresponding decimal value
        int digit;
        if (hex_str[i] >= '0' && hex_str[i] <= '9') {
            digit = hex_str[i] - '0';
        } else if (hex_str[i] >= 'A' && hex_str[i] <= 'F') {
            digit = hex_str[i] - 'A' + 10;
        } else if (hex_str[i] >= 'a' && hex_str[i] <= 'f') {
            digit = hex_str[i] - 'a' + 10;
        } else {
            // Invalid character encountered
            return -1;
        }

        // Multiply the current digit by the appropriate base and add it to the decimal number
        dec_num += digit * base;

        // Update the base for the next iteration
        base *= 16;
    }

    return dec_num;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int dec_num) {
    char *hex_str = (char *)malloc(sizeof(char) * 100);
    int i = 0;

    // Iterate until the decimal number is 0
    while (dec_num != 0) {
        // Get the remainder of the decimal number when divided by 16
        int remainder = dec_num % 16;

        // Convert the remainder to its corresponding hexadecimal digit
        char hex_digit;
        if (remainder < 10) {
            hex_digit = remainder + '0';
        } else {
            hex_digit = remainder - 10 + 'A';
        }

        // Append the hexadecimal digit to the hexadecimal string
        hex_str[i] = hex_digit;
        i++;

        // Divide the decimal number by 16 to get the next digit
        dec_num /= 16;
    }

    // Reverse the hexadecimal string
    char temp;
    for (int j = 0; j < i / 2; j++) {
        temp = hex_str[j];
        hex_str[j] = hex_str[i - j - 1];
        hex_str[i - j - 1] = temp;
    }

    // Add the null-terminator to the hexadecimal string
    hex_str[i] = '\0';

    return hex_str;
}

int main() {
    // Get the hexadecimal string from the user
    char hex_str[100];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex_str);

    // Convert the hexadecimal string to an integer
    int dec_num = hex_to_int(hex_str);

    // Check if the conversion was successful
    if (dec_num == -1) {
        printf("Invalid hexadecimal string.\n");
    } else {
        // Convert the integer to a hexadecimal string
        char *new_hex_str = int_to_hex(dec_num);

        // Print the converted hexadecimal string
        printf("The converted hexadecimal string is: %s\n", new_hex_str);

        // Free the allocated memory
        free(new_hex_str);
    }

    return 0;
}