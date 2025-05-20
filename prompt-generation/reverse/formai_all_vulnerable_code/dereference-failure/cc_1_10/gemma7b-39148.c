//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *input_string = NULL;
    char *hex_string = NULL;
    int input_length = 0;
    int hex_length = 0;
    int i = 0;
    int j = 0;
    int valid = 0;
    unsigned int number = 0;
    unsigned int hex_number = 0;

    // Allocate memory for input and hex strings
    input_string = malloc(256);
    hex_string = malloc(256);

    // Get the input string from the user
    printf("Enter an hexadecimal number: ");
    fgets(input_string, 256, stdin);

    // Calculate the length of the input string
    input_length = strlen(input_string);

    // Calculate the length of the hex string
    hex_length = input_length * 2 + 1;

    // Allocate memory for the hex string
    hex_string = malloc(hex_length);

    // Convert the input string to uppercase
    for (i = 0; i < input_length; i++)
    {
        input_string[i] = toupper(input_string[i]);
    }

    // Validate the input string
    valid = 1;
    for (i = 0; i < input_length; i++)
    {
        if (!((input_string[i] >= 'A' && input_string[i] <= 'F') || (input_string[i] >= '0' && input_string[i] <= '9')))
        {
            valid = 0;
        }
    }

    // Convert the input string to a hexadecimal number
    if (valid)
    {
        number = strtol(input_string, NULL, 16);
    }

    // Convert the hexadecimal number to a hex string
    hex_number = number;
    hex_length = 0;
    while (hex_number)
    {
        hex_string[hex_length++] = '0' + hex_number % 16;
        hex_number /= 16;
    }

    // Print the hex string
    printf("The hexadecimal number is: ");
    for (i = hex_length - 1; i >= 0; i--)
    {
        printf("%c", hex_string[i]);
    }

    // Free memory
    free(input_string);
    free(hex_string);

    return;
}