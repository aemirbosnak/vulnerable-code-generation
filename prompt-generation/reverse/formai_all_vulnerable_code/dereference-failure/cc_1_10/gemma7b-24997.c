//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);

    int sentiment = analyzeSentiment(words);

    switch (sentiment)
    {
        case 0:
            printf("Neutral\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        case -1:
            printf("Negative\n");
            break;
    }

    return 0;
}

int tokenize(char *text, char **words)
{
    char *ptr = text;
    int num_words = 0;

    while (ptr)
    {
        char *word = strchr(ptr, ' ');
        if (word)
        {
            *words[num_words++] = malloc(word - ptr + 1);
            memcpy(*words[num_words - 1], ptr, word - ptr);
            *words[num_words - 1] += '\0';
            ptr = word + 1;
        }
        else
        {
            *words[num_words++] = malloc(strlen(ptr) + 1);
            memcpy(*words[num_words - 1], ptr, strlen(ptr) + 1);
            *words[num_words - 1] += '\0';
            ptr = NULL;
        }
    }

    return num_words;
}

int analyzeSentiment(char **words)
{
    int sentiment = 0;
    for (int i = 0; words[i]; i++)
    {
        if (containsPositiveWords(words[i]))
        {
            sentiment++;
        }
        else if (containsNegativeWords(words[i]))
        {
            sentiment--;
        }
    }

    return sentiment;
}

int containsPositiveWords(char *word)
{
    char *positive_words[] = {"happy", "joy", "love", "good", "excellent"};

    for (int i = 0; positive_words[i]; i++)
    {
        if (strcmp(word, positive_words[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int containsNegativeWords(char *word)
{
    char *negative_words[] = {"sad", "hate", "anger", "bad", "terrible"};

    for (int i = 0; negative_words[i]; i++)
    {
        if (strcmp(word, negative_words[i]) == 0)
        {
            return -1;
        }
    }

    return 0;
}