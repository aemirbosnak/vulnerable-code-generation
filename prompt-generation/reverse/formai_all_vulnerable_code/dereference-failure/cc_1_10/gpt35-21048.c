//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN   1000
#define HEX_BASE  16

int getInput(char* inputStr)
{
    int len = 0;

    printf("Enter a hexadecimal number: ");
    fflush(stdout);
    if (fgets(inputStr, MAX_LEN, stdin))
    {
        len = strlen(inputStr) - 1;
        inputStr[len] = '\0';
    }

    return len;
}

int convertHexToDec(const char* hexString, const int len)
{
    int i;
    int place = 1;
    int decValue = 0;

    for (i = len - 1; i >= 0; i--)
    {
        if (hexString[i] >= '0' && hexString[i] <= '9')
        {
            decValue += (hexString[i] - 48) * place;
        }
        else if (hexString[i] >= 'a' && hexString[i] <= 'f')
        {
            decValue += (hexString[i] - 87) * place;
        }
        else if (hexString[i] >= 'A' && hexString[i] <= 'F')
        {
            decValue += (hexString[i] - 55) * place;
        }
        place *= HEX_BASE;
    }
    return decValue;
}

int main()
{
    char hexString[MAX_LEN];
    int len;
    int decValue;

    len = getInput(hexString);
    if (!len)
    {
        printf("Invalid input\n");
        return 0;
    }

    decValue = convertHexToDec(hexString, len);
    printf("Decimal value of %s is %d\n", hexString, decValue);

    return 0;
}