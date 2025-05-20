//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
    char **words = NULL;
    int word_count = 0;
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    words = malloc(MAX_WORDS * sizeof(char *));

    // Tokenize the text
    char *token = strtok(text, " ");

    // Count the words
    while (token)
    {
        int found = 0;
        for (int i = 0; i < word_count; i++)
        {
            if (strcmp(token, words[i]) == 0)
            {
                found = 1;
            }
        }

        if (!found)
        {
            words[word_count++] = strdup(token);
        }
    }

    // Print the word frequencies
    for (int i = 0; i < word_count; i++)
    {
        int frequency = 0;
        for (int j = 0; j < word_count; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                frequency++;
            }
        }

        printf("%s: %d\n", words[i], frequency);
    }

    free(words);

    return 0;
}