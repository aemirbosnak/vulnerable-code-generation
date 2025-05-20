//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to a hexadecimal number
char* decimalToHexadecimal(int decimal)
{
    char* hexadecimal = (char*) malloc(sizeof(char) * 10);
    int index = 0;

    while (decimal > 0)
    {
        int remainder = decimal % 16;

        if (remainder < 10)
            hexadecimal[index++] = 48 + remainder;

        else
            hexadecimal[index++] = 55 + remainder;

        decimal /= 16;
    }

    // Reverse the string before returning it
    char* reversedHexadecimal = (char*) malloc(sizeof(char) * (strlen(hexadecimal) + 1));
    int i, j;

    for (i = strlen(hexadecimal) - 1, j = 0; i >= 0; i--, j++)
        reversedHexadecimal[j] = hexadecimal[i];

    reversedHexadecimal[j] = '\0';

    free(hexadecimal);

    return reversedHexadecimal;
}

// Function to convert a hexadecimal number to a decimal number
int hexadecimalToDecimal(char* hexadecimal)
{
    int decimal = 0;
    int length = strlen(hexadecimal);
    int i;

    for (i = 0; hexadecimal[i] != '\0'; i++)
    {
        if (hexadecimal[i] >= 48 && hexadecimal[i] <= 57)
        {
            decimal += (hexadecimal[i] - 48) * pow(16, length - 1);
            length--;
        }

        else if (hexadecimal[i] >= 65 && hexadecimal[i] <= 70)
        {
            decimal += (hexadecimal[i] - 55) * pow(16, length - 1);
            length--;
        }

        else if (hexadecimal[i] >= 97 && hexadecimal[i] <= 102)
        {
            decimal += (hexadecimal[i] - 87) * pow(16, length - 1);
            length--;
        }
    }

    return decimal;
}

int main()
{
    int choice;
    int decimal;
    char hexadecimal[10];

    printf("Select an option:\n");
    printf("1. Decimal to Hexadecimal conversion.\n");
    printf("2. Hexadecimal to Decimal conversion.\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            printf("The hexadecimal representation of %d is %s.\n", decimal, decimalToHexadecimal(decimal));
            break;

        case 2:
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexadecimal);
            printf("The decimal representation of %s is %d.\n", hexadecimal, hexadecimalToDecimal(hexadecimal));
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}