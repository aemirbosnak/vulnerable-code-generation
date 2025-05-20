//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int i = 0;
    int power = 0;

    for (i = strlen(binary) - 1; i >= 0; i--)
    {
        int digit = binary[i] - '0';
        decimal += digit * pow(2, power);
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
char *decimalToBinary(int decimal)
{
    char *binary = malloc(10);
    int i = 0;

    while (decimal)
    {
        int digit = decimal % 2;
        binary[i++] = digit + '0';
        decimal /= 2;
    }

    binary[i] = '\0';
    return binary;
}

int main()
{
    char *binary = "1010";
    int decimal = binaryToDecimal(binary);
    printf("Decimal: %d\n", decimal);

    char *converted_binary = decimalToBinary(decimal);
    printf("Converted binary: %s\n", converted_binary);

    free(converted_binary);
    return 0;
}