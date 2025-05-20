//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program converts a hexadecimal number to an integer.

int main(int argc, char *argv[])
{
    // Check if the user has provided a hexadecimal number.

    if (argc != 2)
    {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    // Get the hexadecimal number from the command line.

    char *hexadecimal_number = argv[1];

    // Check if the hexadecimal number is valid.

    int i;
    for (i = 0; i < strlen(hexadecimal_number); i++)
    {
        if (!isxdigit(hexadecimal_number[i]))
        {
            printf("Invalid hexadecimal number: %s\n", hexadecimal_number);
            return 1;
        }
    }

    // Convert the hexadecimal number to an integer.

    int integer_number = 0;
    for (i = 0; i < strlen(hexadecimal_number); i++)
    {
        int digit_value;
        if (isdigit(hexadecimal_number[i]))
        {
            digit_value = hexadecimal_number[i] - '0';
        }
        else
        {
            digit_value = 10 + hexadecimal_number[i] - 'a';
        }
        integer_number = integer_number * 16 + digit_value;
    }

    // Print the integer number.

    printf("Integer number: %d\n", integer_number);

    return 0;
}