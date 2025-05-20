//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to convert character to binary string
char *CharToBinary(char c)
{
    char *binary = malloc(sizeof(char) * 8 + 1);
    int i;

    for (i = 7; i >= 0; i--)
    {
        binary[i] = ((c & (1 << i)) ? '1' : '0');
    }
    binary[8] = '\0';

    return binary;
}

// function to print ASCII art for a given character
void PrintCharArt(char c)
{
    char *binary = CharToBinary(c);
    int i;

    for (i = 0; i < 8; i++)
    {
        if (binary[i] == '0')
        {
            printf("     ");
        }
        else
        {
            printf(" _____\n");
            printf("|     |\n");
            printf("|  o  |\n");
            printf("|_____|\n");
        }
    }

    printf("\n");
    free(binary);
}

int main(int argc, char *argv[])
{
    int i, j, k;
    char *inputString;

    if (argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        exit(1);
    }

    inputString = argv[1];

    for (i = 0; i < strlen(inputString); i++)
    {
        if (!isalnum(inputString[i]))
        {
            continue;
        }

        for (j = 0; j < 5; j++)
        {
            for (k = i * 8; k < (i * 8) + 8; k++)
            {
                PrintCharArt(inputString[k]);
            }
        }

        printf("\n");
    }

    return 0;
}