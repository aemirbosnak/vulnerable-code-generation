//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
void compress_string(char* str)
{
    int len = strlen(str), i, j, count = 1;
    char* temp = (char*) malloc(sizeof(char) * (len + 1));
    temp[0] = str[0];

    // Traverse through the string and keep a count of consecutive characters
    for (i = 1, j = 1; i < len; i++)
    {
        if (str[i] == str[i - 1])
            count++;
        else
        {
            temp[j++] = count + '0';
            temp[j++] = str[i - 1];
            count = 1;
        }
    }
    temp[j++] = count + '0';
    temp[j++] = str[len - 1];
    temp[j] = '\0';

    // Copy the compressed string back to the original string
    strncpy(str, temp, len + 1);
    free(temp);
}

// Function to decompress a string compressed with run-length encoding
void decompress_string(char* str)
{
    int len = strlen(str), i, j, count;
    char* temp = (char*) malloc(sizeof(char) * (len + 1));

    // Traverse through the compressed string and decompress it
    for (i = 0, j = 0; i < len; i += 2)
    {
        count = str[i] - '0';
        while (count--)
            temp[j++] = str[i + 1];
    }
    temp[j] = '\0';

    // Copy the decompressed string back to the original string
    strncpy(str, temp, len + 1);
    free(temp);
}

int main()
{
    char str[100];

    printf("Enter a string to compress: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Original string: %s\n", str);

    compress_string(str);
    printf("Compressed string: %s\n", str);

    decompress_string(str);
    printf("Decompressed string: %s\n", str);

    return 0;
}