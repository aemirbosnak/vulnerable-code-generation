//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexa_converter(char *num)
{
    int i = 0, j, k, n, hex_num[10], count = 0;
    char *hex_str = NULL;

    n = strlen(num);

    // Allocate memory for the hexadecimal string
    hex_str = malloc(n + 1);

    // Convert the decimal number to hexadecimal
    while (i < n)
    {
        int digit = num[i] - '0';
        hex_num[count++] = digit / 16;
        hex_num[count++] = digit % 16;
        i++;
    }

    // Create the hexadecimal string
    for (j = count - 1; j >= 0; j--)
    {
        if (hex_num[j] < 10)
        {
            hex_str[j] = hex_num[j] + '0';
        }
        else
        {
            hex_str[j] = hex_num[j] - 10 + 'a';
        }
    }

    // Add a null terminator to the end of the string
    hex_str[count] = '\0';

    // Print the hexadecimal string
    printf("Hexadecimal equivalent: %s\n", hex_str);

    // Free the memory allocated for the hexadecimal string
    free(hex_str);
}

int main()
{
    char num[20] = "123";

    hexa_converter(num);

    return 0;
}