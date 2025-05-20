//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char hex_digits[] = "0123456789abcdef";

// Function to convert decimal to hexadecimal
char *dec2hex(unsigned int n)
{
    char *hex_string = malloc(sizeof(char) * 9);
    int index = 0;

    while (n > 0) {
        hex_string[index++] = hex_digits[n % 16]; // Convert the last four bits
        n /= 16;
    }
    hex_string[index] = '\0';

    // Reverse the string
    for (int i = 0, j = strlen(hex_string) - 1; i < j; i++, j--)
    {
        char temp = hex_string[i];
        hex_string[i] = hex_string[j];
        hex_string[j] = temp;
    }
    return hex_string;
}

// Function to convert hexadecimal to decimal
unsigned int hex2dec(char *hex_string)
{
    unsigned int decimal = 0;

    for (int i = 0; hex_string[i] != '\0'; i++)
    {
        char c = hex_string[i];
        if (!isxdigit(c))
            return 0; // Invalid hex string, return 0

        int decimal_value;
        if (isdigit(c))
            decimal_value = c - '0';
        else if (islower(c))
            decimal_value = c - 'a' + 10;
        else
            decimal_value = c - 'A' + 10;

        decimal = (decimal << 4) + decimal_value; // Shift by 4 bits and add decimal value
    }
    return decimal;
}

int main()
{
    unsigned int decimal;
    char *hex_string = malloc(sizeof(char) * 9);

    printf("Enter decimal number : ");
    scanf("%u", &decimal);

    hex_string = dec2hex(decimal);
    printf("Hexadecimal : %s\n", hex_string);

    printf("Enter hexadecimal number : ");
    scanf("%s", hex_string);

    decimal = hex2dec(hex_string);
    printf("Decimal : %u\n", decimal);

    free(hex_string);
    return 0;
}