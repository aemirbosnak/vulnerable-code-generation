//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

int main()
{
    char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
    int word_count = 0;

    // Get the text from the user
    printf("Enter text: ");
    char text[1000];
    fgets(text, 1000, stdin);

    // Split the text into words
    char *word = strtok(text, " ");
    while (word)
    {
        words[word_count++] = strdup(word);
        word = strtok(NULL, " ");
    }

    // Count the frequency of each word
    int word_frequency[MAX_WORDS] = {0};
    for (int i = 0; i < word_count; i++)
    {
        for (int j = 0; j < MAX_WORDS; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                word_frequency[j]++;
            }
        }
    }

    // Print the word frequency
    printf("Word frequency:\n");
    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (word_frequency[i] > 0)
        {
            printf("%s: %d\n", words[i], word_frequency[i]);
        }
    }

    // Free the memory
    free(words);

    return 0;
}