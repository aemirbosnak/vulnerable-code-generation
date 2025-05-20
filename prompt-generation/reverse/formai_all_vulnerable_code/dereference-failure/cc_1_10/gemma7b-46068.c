//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

int main()
{
    char text[MAX_WORDS];
    printf("Enter a text: ");
    fgets(text, MAX_WORDS, stdin);

    char *words[MAX_WORDS];
    int num_words = tokenize(text, words);

    int sentiment = analyze_sentiment(words);

    switch (sentiment)
    {
        case 0:
            printf("Neutral\n");
            break;
        case 1:
            printf("Positive\n");
            break;
        case 2:
            printf("Negative\n");
            break;
    }

    return 0;
}

int tokenize(char *text, char **words)
{
    int num_words = 0;
    words = malloc(MAX_WORDS * sizeof(char *));

    char *ptr = text;
    while (*ptr)
    {
        char *word = malloc(MAX_WORDS * sizeof(char));
        word = strtok(ptr, " \t\n");

        if (word)
        {
            words[num_words++] = word;
        }

        ptr = strchr(ptr, ' ') + 1;
    }

    return num_words;
}

int analyze_sentiment(char **words)
{
    int sentiment = 0;
    for (int i = 0; words[i] != NULL; i++)
    {
        char *word = words[i];

        if (isupper(word[0]))
        {
            word = word + 1;
        }

        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0)
        {
            sentiment++;
        }
        else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0)
        {
            sentiment--;
        }
    }

    return sentiment;
}