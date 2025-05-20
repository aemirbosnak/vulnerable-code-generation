//FormAI DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(char *binary);
char *decimalToBinary(int decimal);

int main()
{
    // Binary to Decimal Conversion
    char *binary = "10101010";
    int decimal = binaryToDecimal(binary);
    printf("Binary %s is equal to Decimal %d\n", binary, decimal);

    // Decimal to Binary Conversion
    int number = 42;
    char *convertedBinary = decimalToBinary(number);
    printf("Decimal %d is equal to Binary %s\n", number, convertedBinary);

    free(convertedBinary);
    return 0;
}

int binaryToDecimal(char *binary)
{
    int length = strlen(binary);
    int decimal = 0;
    int power = 1;

    for (int i = length - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += power;
        }
        power *= 2;
    }

    return decimal;
}

char *decimalToBinary(int decimal)
{
    int temp = decimal;
    int binaryLength = 0;

    while (temp > 0)
    {
        temp /= 2;
        binaryLength++;
    }

    char *binary = (char *)malloc(binaryLength + 1);
    binary[binaryLength] = '\0';

    temp = decimal;
    for (int i = binaryLength - 1; i >= 0; i--)
    {
        binary[i] = ((temp % 2) == 1) ? '1' : '0';
        temp /= 2;
    }

    return binary;
}