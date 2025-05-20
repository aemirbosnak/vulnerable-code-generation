//Falcon2-11B DATASET v1.0 Category: Binary Converter ; Style: irregular
#include <stdio.h>
#include <string.h>

// Function to convert binary to decimal
int binToDec(char *bin)
{
    int dec = 0;
    int i = 0;
    while (bin[i]!= '\0')
    {
        dec = dec + (bin[i] - '0') * (1 << i);
        i++;
    }
    return dec;
}

// Function to convert decimal to binary
char *decToBin(int dec)
{
    char *bin = (char *)malloc(sizeof(char) * (dec + 1));
    bin[dec] = '\0';
    int i = 0;
    while (dec > 0)
    {
        if (dec % 2 == 1)
            bin[i] = '1';
        else
            bin[i] = '0';
        dec = dec / 2;
        i++;
    }
    return bin;
}

// Function to convert hexadecimal to binary
char *hexToBin(char *hex)
{
    char *bin = (char *)malloc(sizeof(char) * (strlen(hex) * 2 + 1));
    bin[strlen(hex) * 2] = '\0';
    int i = 0;
    while (hex[i]!= '\0')
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            bin[i * 2] = hex[i] - '0';
            bin[i * 2 + 1] = '0';
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            bin[i * 2] = hex[i] - 'a' + 10;
            bin[i * 2 + 1] = '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            bin[i * 2] = hex[i] - 'A' + 10;
            bin[i * 2 + 1] = '0';
        }
        i++;
    }
    return bin;
}

// Function to convert decimal to hexadecimal
char *decToHex(int dec)
{
    char *hex = (char *)malloc(sizeof(char) * (2 * dec + 1));
    hex[2 * dec] = '\0';
    int i = 0;
    while (dec > 0)
    {
        if (dec % 16 < 10)
            hex[i] = dec % 16 + '0';
        else
            hex[i] = dec % 16 + 'a' - 10;
        dec = dec / 16;
        i++;
    }
    return hex;
}

int main()
{
    char binary[100];
    char hexadecimal[100];
    int decimal;

    printf("Enter binary number: ");
    scanf("%s", binary);
    decimal = binToDec(binary);
    printf("Decimal equivalent: %d\n", decimal);
    printf("Binary to decimal: %s\n", decToBin(decimal));
    printf("Decimal to binary: %s\n", decToBin(decimal));

    printf("Enter hexadecimal number: ");
    scanf("%s", hexadecimal);
    decimal = strtol(hexadecimal, NULL, 16);
    printf("Decimal equivalent: %d\n", decimal);
    printf("Hexadecimal to binary: %s\n", hexToBin(hexadecimal));
    printf("Decimal to hexadecimal: %s\n", decToHex(decimal));

    return 0;
}