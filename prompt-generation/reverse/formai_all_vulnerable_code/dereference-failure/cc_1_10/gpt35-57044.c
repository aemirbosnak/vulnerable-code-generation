//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Paranoid C Compression Algorithm */
void paranoidCompress(char* inputStr)
{
    int i, j, count;

    // Determine original string length
    int inputLen = strlen(inputStr);

    // Allocate memory for compressed string
    char* compressedStr = (char*)malloc(sizeof(char) * inputLen);

    // Initialize compressed string
    memset(compressedStr, 0, inputLen);

    // Compress the string
    for (i = 0, j = 0; i < inputLen; i++)
    {
        // Reset count
        count = 1;

        // Check for consecutive characters
        while (inputStr[i] == inputStr[i+1])
        {
            count++;
            i++;
        }

        // Add character and count to compressed string
        compressedStr[j] = inputStr[i];
        compressedStr[j+1] = count + '0';
        j += 2;
    }

    // Print both the original and compressed strings
    printf("Original string: %s\n", inputStr);
    printf("Compressed string: %s\n", compressedStr);

    // Free memory
    free(compressedStr);
}

int main()
{
    // Test input string
    char str[] = "Paranoid compression algorithmtt";

    // Compress the string
    paranoidCompress(str);

    return 0;
}