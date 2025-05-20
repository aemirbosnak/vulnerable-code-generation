//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

int main()
{
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int numWords = word_tokenize(text, words);

    int sentiment = sentiment_analysis(words, numWords);

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

int word_tokenize(char *text, char **words)
{
    int numWords = 0;
    words = malloc(MAX_WORDS * sizeof(char *));

    char *token = strtok(text, " ");
    while (token)
    {
        words[numWords++] = strdup(token);
        token = strtok(NULL, " ");
    }

    return numWords;
}

int sentiment_analysis(char **words, int numWords)
{
    int sentiment = 0;
    for (int i = 0; i < numWords; i++)
    {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0)
        {
            sentiment++;
        }
        else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0)
        {
            sentiment--;
        }
    }

    return sentiment;
}