//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compress a string using run-length encoding
char* compress(char* str)
{
    int n = strlen(str);

    // allocate memory for the result string
    char* compressed_str = (char*) malloc(sizeof(char) * (n + 1));

    // initialize variables
    int count = 1;
    char prev = str[0];
    int index = 0;

    // iterate over the characters in the input string
    for (int i = 1; i <= n; i++)
    {
        // if the current character is the same as the previous character,
        // increment the count
        if (str[i] == prev)
        {
            count++;
        }
        // if the current character is different from the previous character,
        // write the previous character and its count to the result string,
        // and reset the count to 1
        else
        {
            compressed_str[index++] = prev;
            compressed_str[index++] = count + '0';
            count = 1;
            prev = str[i];
        }
    }

    // null-terminate the result string
    compressed_str[index] = '\0';

    return compressed_str;
}

// function to decompress a string that has been compressed using run-length encoding
char* decompress(char* str)
{
    int n = strlen(str);

    // allocate memory for the result string
    char* decompressed_str = (char*) malloc(sizeof(char) * (n + 1));

    // initialize variables
    int count = 0;
    char ch;

    // iterate over the characters in the input string
    for (int i = 0; i < n; i++)
    {
        // if the current character is a digit, update the count
        if (isdigit(str[i]))
        {
            count = count * 10 + (str[i] - '0');
        }
        // if the current character is a letter, write the letter to the result
        // string count number of times
        else
        {
            ch = str[i];
            for (int j = 0; j < count; j++)
            {
                decompressed_str[j] = ch;
            }
            count = 0;
        }
    }

    // null-terminate the result string
    decompressed_str[strlen(decompressed_str)] = '\0';

    return decompressed_str;
}

// main function
int main()
{
    char str[] = "aaabbccccdeffff";

    // compress the input string using run-length encoding
    char* compressed_str = compress(str);
    printf("%s\n", compressed_str); // a3b2c4d1e1f4

    // decompress the compressed string
    char* decompressed_str = decompress(compressed_str);
    printf("%s\n", decompressed_str); // aaabbccccdeffff

    // free heap memory
    free(compressed_str);
    free(decompressed_str);

    return 0;
}