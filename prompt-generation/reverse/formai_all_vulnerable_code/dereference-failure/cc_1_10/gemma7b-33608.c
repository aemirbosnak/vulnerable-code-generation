//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 50

typedef struct SentimentWord
{
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord *loadSentimentWords(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    SentimentWord *words = malloc(MAX_SENTIMENT_WORDS * sizeof(SentimentWord));
    int i = 0;
    char word[255];
    while (fscanf(fp, "%s", word) != EOF)
    {
        words[i].word = strdup(word);
        fscanf(fp, "%d", &words[i].sentiment);
        i++;
    }

    fclose(fp);
    return words;
}

int sentimentAnalysis(char *text)
{
    SentimentWord *words = loadSentimentWords("sentiment_words.txt");
    int sentiment = 0;
    for (int i = 0; words[i].word != NULL; i++)
    {
        if (strstr(text, words[i].word) != NULL)
        {
            sentiment += words[i].sentiment;
        }
    }

    free(words);
    return sentiment;
}

int main()
{
    char *text = "I am very happy today.";
    int sentiment = sentimentAnalysis(text);
    printf("Sentiment score: %d\n", sentiment);

    return 0;
}