//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
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
    if (fp)
    {
        char line[1024];
        int i = 0;
        while (fgets(line, 1024, fp) != NULL)
        {
            char *word = strdup(line);
            int sentiment = atoi(word + strlen(word) - 1);
            sentimentWords[i++] = (SentimentWord){word, sentiment};
        }
        fclose(fp);
    }
}

int analyzeSentiment(char *text)
{
    loadSentimentWords();
    int score = 0;
    for (int i = 0; sentimentWords[i].word != NULL; i++)
    {
        if (strstr(text, sentimentWords[i].word) != NULL)
        {
            score += sentimentWords[i].sentiment;
        }
    }
    return score;
}

int main()
{
    char text[] = "I am very happy today.";
    int sentimentScore = analyzeSentiment(text);
    printf("Sentiment score: %d\n", sentimentScore);

    return 0;
}