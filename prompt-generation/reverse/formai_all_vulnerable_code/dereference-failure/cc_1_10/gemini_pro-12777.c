//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex)
{
    int len = strlen(hex);
    int base = 1;
    int value = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            value += (hex[i] - '0') * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            value += (hex[i] - 'A' + 10) * base;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            value += (hex[i] - 'a' + 10) * base;
        }

        base *= 16;
    }

    return value;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int num)
{
    char *hex = (char *)malloc(sizeof(char) * 100);
    int i = 0;

    while (num != 0)
    {
        int temp = num % 16;

        if (temp < 10)
        {
            hex[i] = temp + '0';
        }
        else
        {
            hex[i] = temp + 'A' - 10;
        }

        i++;
        num /= 16;
    }

    hex[i] = '\0';

    return hex;
}

// Main function
int main()
{
    // Example hexadecimal string
    char *hex = "ABCDEF";

    // Convert hexadecimal string to integer
    int num = hex_to_int(hex);

    // Convert integer to hexadecimal string
    char *result = int_to_hex(num);

    // Print the results
    printf("Hexadecimal string: %s\n", hex);
    printf("Integer: %d\n", num);
    printf("Hexadecimal string (converted from integer): %s\n", result);

    return 0;
}