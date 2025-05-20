//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Convert a hexadecimal string to an integer.
 *
 * @param str The hexadecimal string to convert.
 * @return The integer value of the string.
 */
int hex_to_int(const char *str)
{
    int value = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        if (c >= '0' && c <= '9')
        {
            value = (value << 4) + (c - '0');
        }
        else if (c >= 'A' && c <= 'F')
        {
            value = (value << 4) + (c - 'A' + 10);
        }
        else if (c >= 'a' && c <= 'f')
        {
            value = (value << 4) + (c - 'a' + 10);
        }
        else
        {
            fprintf(stderr, "Invalid hexadecimal character: '%c'\n", c);
            exit(1);
        }
    }

    return value;
}

/*
 * Convert an integer to a hexadecimal string.
 *
 * @param value The integer to convert.
 * @return The hexadecimal string value of the integer.
 */
char *int_to_hex(int value)
{
    char *str = malloc(11);
    int i;

    for (i = 10; i >= 0; i--)
    {
        int digit = value & 0xF;

        if (digit < 10)
        {
            str[i] = digit + '0';
        }
        else
        {
            str[i] = digit - 10 + 'A';
        }

        value >>= 4;
    }

    str[11] = '\0';

    return str;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), input) != NULL)
    {
        int value = hex_to_int(line);
        char *hex = int_to_hex(value);

        fprintf(output, "%s\n", hex);

        free(hex);
    }

    fclose(input);
    fclose(output);

    return 0;
}