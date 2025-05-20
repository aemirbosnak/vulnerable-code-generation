//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal number to hexadecimal string
char* dec_to_hex(int dec_num) {
    int i;
    int digit;
    static char hex[32];

    for (i = 0; dec_num > 0; i++) {
        digit = dec_num % 16;
        dec_num /= 16;

        // Convert decimal digit to hexadecimal character
        if (digit < 10)
            hex[i] = digit + '0';
        else
            hex[i] = digit + 'A' - 10;
    }

    // Add a null terminator to the hexadecimal string
    hex[i] = '\0';

    // Reverse the string since hexadecimal numbers are stored in reverse order
    for (i = 0; hex[i] != '\0'; i++) {
        int j = sizeof(hex) / sizeof(hex[0]) - 1 - i;
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }

    return hex;
}

int main() {
    int decimal_number;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    // Convert decimal number to hexadecimal string
    char* hex_string = dec_to_hex(decimal_number);

    printf("The hexadecimal representation of %d is: %s\n", decimal_number, hex_string);

    // Free the memory allocated by the dec_to_hex function
    free(hex_string);

    return 0;
}