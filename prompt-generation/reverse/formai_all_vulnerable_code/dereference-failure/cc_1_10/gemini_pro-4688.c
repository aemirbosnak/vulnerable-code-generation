//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex)
{
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;

    // Iterate through the hexadecimal string from right to left
    for (int i = len - 1; i >= 0; i--)
    {
        // Extract the digit from the hexadecimal string
        char digit = hex[i];

        // Convert the digit to its decimal equivalent
        int digit_val;
        if (digit >= '0' && digit <= '9')
        {
            digit_val = digit - '0';
        }
        else if (digit >= 'A' && digit <= 'F')
        {
            digit_val = digit - 'A' + 10;
        }
        else if (digit >= 'a' && digit <= 'f')
        {
            digit_val = digit - 'a' + 10;
        }
        else
        {
            return -1; // Invalid hexadecimal digit
        }

        // Multiply the digit by the appropriate power of 16 and add it to the decimal value
        dec_val += digit_val * base;
        base *= 16;
    }

    return dec_val;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int dec)
{
    char *hex = malloc(256); // Allocate enough memory to store the hexadecimal string
    int i = 0;

    // Iterate until the decimal value is 0
    while (dec > 0)
    {
        // Get the remainder of the division by 16
        int remainder = dec % 16;

        // Convert the remainder to a hexadecimal digit
        char digit;
        if (remainder >= 0 && remainder <= 9)
        {
            digit = remainder + '0';
        }
        else if (remainder >= 10 && remainder <= 15)
        {
            digit = remainder - 10 + 'A';
        }

        // Append the hexadecimal digit to the string
        hex[i++] = digit;

        // Divide the decimal value by 16
        dec /= 16;
    }

    // Reverse the hexadecimal string
    int len = strlen(hex);
    for (int j = 0; j < len / 2; j++)
    {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }

    // Add a null terminator to the end of the string
    hex[i] = '\0';

    return hex;
}

int main()
{
    // Get the hexadecimal string from the user
    char hex[256];
    printf("Enter a hexadecimal string: ");
    scanf("%s", hex);

    // Convert the hexadecimal string to an integer
    int dec = hex_to_int(hex);
    printf("The decimal equivalent of %s is %d\n", hex, dec);

    // Convert the integer to a hexadecimal string
    char *new_hex = int_to_hex(dec);
    printf("The hexadecimal equivalent of %d is %s\n", dec, new_hex);

    // Free the memory allocated for the hexadecimal string
    free(new_hex);

    return 0;
}