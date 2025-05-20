//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[])
{
    int decimal = 0;
    int i = strlen(hex) - 1;
    while (i >= 0)
    {
        if (isdigit(hex[i]))
        {
            decimal += (hex[i] - '0');
        }
        else if (isalpha(hex[i]))
        {
            if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                decimal += (hex[i] - 'A' + 10);
            }
            else if (hex[i] >= 'a' && hex[i] <= 'f')
            {
                decimal += (hex[i] - 'a' + 10);
            }
        }
        else
        {
            printf("Invalid character found in hexadecimal number!\n");
            exit(1);
        }
        i--;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decToHex(int decimal, char hex[])
{
    int i = strlen(hex) - 1;
    while (decimal > 0)
    {
        if (decimal % 16 >= 10)
        {
            hex[i] = 'A' + (decimal % 16) - 10;
        }
        else
        {
            hex[i] = '0' + (decimal % 16);
        }
        decimal /= 16;
        i--;
    }
    hex[i + 1] = '\0';
}

int main()
{
    char hex[100];
    int decimal;
    int choice;
    while (1)
    {
        printf("Enter 1 to convert hexadecimal to decimal\n");
        printf("Enter 2 to convert decimal to hexadecimal\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter hexadecimal number: ");
            scanf("%s", hex);
            decimal = hexToDec(hex);
            printf("Decimal equivalent: %d\n", decimal);
            break;
        case 2:
            printf("Enter decimal number: ");
            scanf("%d", &decimal);
            strcpy(hex, "");
            decToHex(decimal, hex);
            printf("Hexadecimal equivalent: %s\n", hex);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}