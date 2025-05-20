//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int num)
{
    char *binary = malloc(sizeof(char) * 33);
    int i = 0;

    // Check if the number is negative
    if (num < 0)
    {
        binary[i++] = '1';
        num = -num;
    }
    else
    {
        binary[i++] = '0';
    }

    // Convert the number to binary
    while (num > 0)
    {
        if (num % 2 == 0)
        {
            binary[i++] = '0';
        }
        else
        {
            binary[i++] = '1';
        }
        num /= 2;
    }

    // Reverse the binary string
    int len = strlen(binary);
    for (int j = 0; j < len / 2; j++)
    {
        char temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }

    // Add the null terminator
    binary[i] = '\0';

    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary)
{
    int num = 0;
    int len = strlen(binary);

    // Check if the binary string is valid
    for (int i = 0; i < len; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            return -1;
        }
    }

    // Convert the binary number to decimal
    for (int i = 0; i < len; i++)
    {
        if (binary[len - i - 1] == '1')
        {
            num += 1 << i;
        }
    }

    return num;
}

// Driver code
int main()
{
    // Convert a decimal number to binary
    int num = 12345;
    char *binary = decimalToBinary(num);
    printf("%d in decimal is %s in binary\n", num, binary);

    // Convert a binary number to decimal
    char *binary2 = "110010010110101";
    int num2 = binaryToDecimal(binary2);
    printf("%s in binary is %d in decimal\n", binary2, num2);

    return 0;
}