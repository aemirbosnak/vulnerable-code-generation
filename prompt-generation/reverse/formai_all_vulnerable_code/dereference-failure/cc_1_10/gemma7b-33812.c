//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

char *get_word(char **words, int *word_count)
{
    char *word = NULL;
    int i = 0;

    for (i = 0; words[i] != NULL; i++)
    {
        if (strcmp(word, words[i]) == 0)
        {
            return words[i];
        }
    }

    words = realloc(words, (*word_count) * sizeof(char *));
    words[*word_count] = malloc(MAX_WORDS);
    word = words[*word_count];
    (*word_count)++;

    return word;
}

int sentiment_analysis(char *text)
{
    char **words = NULL;
    int word_count = 0;
    char *word = get_word(words, &word_count);

    int sentiment = 0;
    for (int i = 0; word[i] != NULL; i++)
    {
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
            word[i] == 'o' || word[i] == 'u')
        {
            sentiment++;
        }
    }

    free(words);
    return sentiment;
}

int main()
{
    char text[] = "I am happy today.";
    int sentiment = sentiment_analysis(text);

    printf("Sentiment score: %d", sentiment);

    return 0;
}