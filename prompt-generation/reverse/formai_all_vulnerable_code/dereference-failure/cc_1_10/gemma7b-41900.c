//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void convertHex(int num, char *hex)
{
    int quotient = num / 16;
    int remainder = num % 16;

    if (quotient)
    {
        convertHex(quotient, hex);
    }

    switch (remainder)
    {
        case 0:
            hex[0] = '0';
            break;
        case 1:
            hex[0] = '1';
            break;
        case 2:
            hex[0] = '2';
            break;
        case 3:
            hex[0] = '3';
            break;
        case 4:
            hex[0] = '4';
            break;
        case 5:
            hex[0] = '5';
            break;
        case 6:
            hex[0] = '6';
            break;
        case 7:
            hex[0] = '7';
            break;
        case 8:
            hex[0] = '8';
            break;
        case 9:
            hex[0] = '9';
            break;
        case 10:
            hex[0] = 'A';
            break;
        case 11:
            hex[0] = 'B';
            break;
        case 12:
            hex[0] = 'C';
            break;
        case 13:
            hex[0] = 'D';
            break;
        case 14:
            hex[0] = 'E';
            break;
        case 15:
            hex[0] = 'F';
            break;
    }

    hex[1] = '\0';
}

int main()
{
    int num = 23;
    char *hex = malloc(10);

    convertHex(num, hex);

    printf("Hexadecimal representation: %s", hex);

    free(hex);

    return 0;
}