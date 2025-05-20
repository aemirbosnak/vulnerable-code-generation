//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary number to decimal
int binaryToDecimal(char *binary)
{
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);

    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Function to convert decimal number to binary
char *decimalToBinary(int decimal)
{
    char *binary = malloc(33);
    int i = 0;

    while (decimal > 0)
    {
        if (decimal % 2 == 0)
        {
            binary[i] = '0';
        }
        else
        {
            binary[i] = '1';
        }
        i++;
        decimal /= 2;
    }

    binary[i] = '\0';

    // Reverse the binary string
    char temp;
    int start = 0;
    int end = strlen(binary) - 1;
    while (start < end)
    {
        temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }

    return binary;
}

int main()
{
    // Get the input from the user
    char binary[33];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert the binary number to decimal
    int decimal = binaryToDecimal(binary);

    // Print the decimal number
    printf("Decimal number: %d\n", decimal);

    // Convert the decimal number to binary
    char *newBinary = decimalToBinary(decimal);

    // Print the binary number
    printf("Binary number: %s\n", newBinary);

    return 0;
}