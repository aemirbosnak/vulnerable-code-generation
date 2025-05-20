//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void word_frequency(char *str)
{
    int i, j, count = 0, words = 0;
    char **word_list = NULL;

    // Allocate memory for the word list
    word_list = (char **)malloc(MAX * sizeof(char *));

    // Split the text into words
    str = strtok(str, " ");

    // Iterate over the words and count their occurrences
    while (str)
    {
        for (i = 0; i < words; i++)
        {
            if (strcmp(str, word_list[i]) == 0)
            {
                count++;
            }
        }

        word_list[words++] = str;
        str = strtok(NULL, " ");
    }

    // Print the word frequencies
    for (i = 0; i < words; i++)
    {
        printf("%s: %d\n", word_list[i], count);
    }

    // Free the memory allocated for the word list
    free(word_list);
}

int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    word_frequency(str);

    return 0;
}