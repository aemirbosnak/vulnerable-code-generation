//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Modular function to convert hexadecimal to decimal
int hex_to_dec(char hex)
{
    // Convert hex character to upper case
    hex = toupper(hex);

    // Check if character is a number or letter
    if (hex >= 'A' && hex <= 'F')
    {
        // Subtract 58 from character to get decimal value
        return hex - 58;
    }
    else
    {
        // Return -1 for invalid input
        return -1;
    }
}

// Modular function to convert decimal to hexadecimal
char dec_to_hex(int dec)
{
    // Calculate the number of digits in the hexadecimal representation
    int num_digits = dec / 16;

    // Allocate memory for the hexadecimal representation
    char *hex_rep = malloc(num_digits + 1);

    // Convert decimal to hexadecimal
    hex_rep[num_digits] = '\0';
    for (int i = num_digits - 1; i >= 0; i--)
    {
        int hex_digit = dec % 16;
        hex_rep[i] = hex_digit + 58;
        dec /= 16;
    }

    // Return the hexadecimal representation
    return *hex_rep;
}

int main()
{
    // Convert hexadecimal to decimal
    char hex_str[] = "A";
    int dec_value = hex_to_dec(hex_str[0]);
    printf("Decimal value: %d\n", dec_value);

    // Convert decimal to hexadecimal
    int dec_num = 15;
    char *hex_rep = dec_to_hex(dec_num);
    printf("Hexadecimal representation: %s\n", hex_rep);

    return 0;
}