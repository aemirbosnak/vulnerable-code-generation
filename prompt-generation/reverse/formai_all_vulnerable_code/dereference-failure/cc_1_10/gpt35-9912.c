//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the string using run-length encoding
char* compress(char* str)
{
    int len = strlen(str);
    int i, j, count;

    // Allocate memory for new compressed string
    char* compressed = (char*)malloc(sizeof(char) * len);

    for(i = 0, j = 0; i < len; i++, j++)
    {
        compressed[j] = str[i];
        count = 1;

        while(i + 1 < len && str[i] == str[i+1])
        {
            count++;
            i++;
        }

        // Convert count to string and append to compressed string
        char num[10];
        sprintf(num, "%d", count);

        for(int k = 0; num[k] != '\0'; k++, j++)
            compressed[j+1] = num[k];
    }

    // Add null terminator
    compressed[j] = '\0';

    return compressed;
}

int main()
{
    char str[] = "AAAABBBCCDAA";
    char* compressed = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);

    free(compressed);

    return 0;
}