//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTIMENT_WORDS 100

typedef struct SentimentWord
{
    char *word;
    int sentiment;
} SentimentWord;

SentimentWord sentimentWords[MAX_SENTIMENT_WORDS];

void loadSentimentWords()
{
    FILE *fp = fopen("sentiment_words.txt", "r");
    if (fp == NULL)
    {
        return;
    }

    int i = 0;
    char line[1024];
    while (fgets(line, 1024, fp) != NULL)
    {
        char *word = strdup(line);
        int sentiment = atoi(word + strlen(word) - 1);
        sentimentWords[i++] = (SentimentWord){.word = word, .sentiment = sentiment};
    }

    fclose(fp);
}

int analyzeSentiment(char *text)
{
    loadSentimentWords();

    int sentiment = 0;
    for (int i = 0; sentimentWords[i].word != NULL; i++)
    {
        if (strstr(text, sentimentWords[i].word) != NULL)
        {
            sentiment += sentimentWords[i].sentiment;
        }
    }

    return sentiment;
}

int main()
{
    char text[] = "I am happy and excited about this project.";

    int sentiment = analyzeSentiment(text);

    if (sentiment > 0)
    {
        printf("The text is positive.\n");
    }
    else
    {
        printf("The text is negative.\n");
    }

    return 0;
}