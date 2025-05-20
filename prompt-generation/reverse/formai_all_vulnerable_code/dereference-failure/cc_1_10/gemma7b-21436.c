//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void convert_binary_to_hex(int n)
{
    int i = 0;
    char *hex_str = malloc(16);
    hex_str[0] = '0';

    while (n)
    {
        int digit = n % 16;
        n /= 16;
        hex_str[i++] = digit + 0x30;
    }

    printf("%s", hex_str);
    free(hex_str);
}

void convert_decimal_to_hex(int n)
{
    int i = 0;
    char *hex_str = malloc(16);
    hex_str[0] = '0';

    while (n)
    {
        int digit = n % 16;
        n /= 16;
        hex_str[i++] = digit + 0x30;
    }

    printf("%s", hex_str);
    free(hex_str);
}

void convert_octal_to_hex(int n)
{
    int i = 0;
    char *hex_str = malloc(16);
    hex_str[0] = '0';

    while (n)
    {
        int digit = n % 16;
        n /= 16;
        hex_str[i++] = digit + 0x30;
    }

    printf("%s", hex_str);
    free(hex_str);
}

int main()
{
    convert_binary_to_hex(10);
    convert_decimal_to_hex(10);
    convert_octal_to_hex(10);

    return 0;
}