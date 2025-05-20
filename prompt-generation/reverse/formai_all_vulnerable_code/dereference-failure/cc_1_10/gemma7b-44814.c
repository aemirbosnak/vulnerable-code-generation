//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a macro to compress a character
#define compressChar(c) (((c) - 'a' + 1) << 4)

// Define a macro to decompress a character
#define decompressChar(n) ('a' + (n) & 0xf)

// Function to compress a string
int compressString(char *str)
{
    int i = 0, j = 0, len = 0, count = 1;
    char prevChar = str[0];

    // Calculate the length of the string
    len = strlen(str);

    // Allocate memory for the compressed string
    char *compStr = malloc((len + 1) * sizeof(char));

    // Iterate over the string
    for (i = 1; i < len; i++)
    {
        if (str[i] == prevChar)
        {
            count++;
        }
        else
        {
            compStr[j++] = compressChar(prevChar) | count;
            prevChar = str[i];
            count = 1;
        }
    }

    // Add the end of the string
    compStr[j++] = compressChar(prevChar) | count;

    // Return the length of the compressed string
    return j;
}

// Function to decompress a string
int decompressString(char *str, int len)
{
    int i = 0, j = 0, count = 1, prevChar = str[0];

    // Iterate over the compressed string
    for (i = 1; i < len; i++)
    {
        int charVal = str[i] & 0xf;
        count = (str[i] >> 4) & 0xf;

        // Decompress the character
        str[j++] = decompressChar(charVal) + prevChar - 1;

        // Update the previous character
        prevChar = str[j - 1];

        // Increment the count
        count++;
    }

    // Return the length of the decompressed string
    return j;
}

int main()
{
    char str[] = "aabbbb";
    int len = compressString(str);
    char *compStr = malloc(len * sizeof(char));
    compStr = compressString(str);

    printf("Compressed string: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c ", compStr[i]);
    }

    printf("\n");

    printf("Decompressed string: ");
    int decompLen = decompressString(compStr, len);
    for (int i = 0; i < decompLen; i++)
    {
        printf("%c ", str[i]);
    }

    printf("\n");

    return 0;
}