//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
    char **words = NULL;
    char **word_list = NULL;
    int word_count = 0;
    int i = 0;

    // The post-apocalyptic world is a harsh one. We need to gather as much information as we can.
    words = malloc(MAX_WORDS * sizeof(char *));
    word_list = malloc(MAX_WORDS * sizeof(char *));

    // Let's see what we can find in the rubble...
    printf("Enter a sentence: ");
    getline(stdin, words[word_count], MAX_WORDS);

    // Now, we need to split the sentence into words.
    word_count++;
    words[word_count] = strtok(words[word_count - 1], " ");

    // We're going to store all the words we find in a list.
    word_list = realloc(word_list, word_count * sizeof(char *));
    word_list[word_count - 1] = words[word_count - 1];

    // Time to count the frequency of each word.
    for (i = 0; i < word_count - 1; i++)
    {
        int j = 0;
        for (j = i + 1; j < word_count - 1; j++)
        {
            if (strcmp(word_list[i], word_list[j]) == 0)
            {
                word_list[i] = NULL;
            }
        }
    }

    // Now, we're going to print the word frequencies.
    printf("Word frequencies:\n");
    for (i = 0; word_list[i] != NULL; i++)
    {
        printf("%s: %d\n", word_list[i], word_count - 1 - count_occurrences(word_list[i], word_list));
    }

    free(words);
    free(word_list);

    return 0;
}

int count_occurrences(char *word, char **word_list)
{
    int i = 0;
    int occurrences = 0;

    for (i = 0; word_list[i] != NULL; i++)
    {
        if (strcmp(word, word_list[i]) == 0)
        {
            occurrences++;
        }
    }

    return occurrences;
}