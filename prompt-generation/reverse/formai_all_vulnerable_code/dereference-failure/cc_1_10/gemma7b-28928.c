//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void word_frequency_counter(char *str)
{
    int i, j, count = 0, flag = 0, words = 0;
    char **arr = NULL;

    // Allocate memory for the array
    arr = (char **)malloc(MAX * sizeof(char *));

    // Tokenize the string into words
    strtok_r(str, " ", arr);

    // Count the number of words
    for (i = 0; arr[i] != NULL; i++)
    {
        words++;
    }

    // Calculate the frequency of each word
    for (i = 0; arr[i] != NULL; i++)
    {
        flag = 0;
        for (j = 0; arr[j] != NULL; j++)
        {
            if (strcmp(arr[i], arr[j]) == 0)
            {
                count++;
                flag = 1;
            }
        }

        // Print the word and its frequency
        if (flag == 0)
        {
            printf("%s: %d\n", arr[i], count);
            count = 0;
        }
    }

    // Free the memory allocated for the array
    free(arr);
}

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    word_frequency_counter(str);

    return 0;
}