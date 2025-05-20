//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

int main()
{
    char **words = NULL;
    int word_count = 0;
    char text[1000] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    // Allocate memory for words
    words = malloc(MAX_WORDS * sizeof(char *));

    // Split the text into words
    char *word = strtok(text, " ");

    // Count the words
    while (word)
    {
        int i = 0;
        for (i = 0; words[i] != NULL; i++)
        {
            if (strcmp(word, words[i]) == 0)
            {
                break;
            }
        }

        if (i == MAX_WORDS - 1)
        {
            words[word_count++] = strdup(word);
        }
        word = strtok(NULL, " ");
    }

    // Print the word frequency
    for (int i = 0; words[i] != NULL; i++)
    {
        int frequency = 0;
        for (int j = 0; words[j] != NULL; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency++;
            }
        }
        printf("%s: %d\n", words[i], frequency);
    }

    // Free the memory
    free(words);

    return 0;
}