//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inv_hex_converter(int argc, char **argv)
{
    char *input_str = NULL;
    char *hex_str = NULL;
    int input_len = 0;
    int i = 0;
    int j = 0;

    // Allocate memory for input and hex strings
    input_str = malloc(1024);
    hex_str = malloc(256);

    // Get the input string from the user
    printf("Enter an hexadecimal number: ");
    fgets(input_str, 1024, stdin);

    // Calculate the length of the input string
    input_len = strlen(input_str);

    // Convert the input string to uppercase
    for (i = 0; i < input_len; i++)
    {
        input_str[i] = toupper(input_str[i]);
    }

    // Convert the input string to hexadecimal
    for (i = 0; i < input_len; i++)
    {
        int num = input_str[i] - 0x30;
        hex_str[j++] = num >> 4 & 0x0F;
        hex_str[j++] = num & 0x0F;
    }

    // Print the hexadecimal string
    printf("Hexadecimal equivalent: ");
    for (i = 0; i < j; i++)
    {
        printf("%02x ", hex_str[i]);
    }

    // Free the allocated memory
    free(input_str);
    free(hex_str);
}

int main(int argc, char **argv)
{
    inv_hex_converter(argc, argv);

    return 0;
}