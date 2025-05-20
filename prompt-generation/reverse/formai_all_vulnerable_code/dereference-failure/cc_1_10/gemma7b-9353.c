//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 512

char *sentence_parser(char *sentence)
{
    int i = 0;
    char *parsed_sentence = malloc(MAX_SENTENCE_LENGTH);
    parsed_sentence[0] = '\0';

    for (i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            parsed_sentence[i] = sentence[i] - 32;
        }
        else
        {
            parsed_sentence[i] = sentence[i];
        }
    }

    return parsed_sentence;
}

int sentiment_analyzer(char *sentence)
{
    int sentiment = 0;
    char *parsed_sentence = sentence_parser(sentence);

    for (int i = 0; parsed_sentence[i] != '\0'; i++)
    {
        if (parsed_sentence[i] >= 'a' && parsed_sentence[i] <= 'z')
        {
            sentiment += parsed_sentence[i] - 90;
        }
    }

    return sentiment;
}

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment = sentiment_analyzer(sentence);

    if (sentiment > 0)
    {
        printf("The sentence is positive.\n");
    }
    else if (sentiment < 0)
    {
        printf("The sentence is negative.\n");
    }
    else
    {
        printf("The sentence is neutral.\n");
    }

    return 0;
}