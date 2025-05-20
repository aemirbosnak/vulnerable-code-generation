//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SENTENCE_LENGTH 256

int main()
{
    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    int sentiment = analyzeSentiment(sentence);

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
        default:
            printf("Error\n");
            break;
    }

    return 0;
}

int analyzeSentiment(char *sentence)
{
    int sentiment = 0;
    int wordCount = 0;
    char *word = NULL;

    // Tokenize the sentence
    word = strtok(sentence, " ");
    while (word)
    {
        wordCount++;

        // Check if the word is a sentiment word
        if (isSentimentWord(word))
        {
            // Assign a sentiment score to the word
            int wordScore = getWordSentimentScore(word);
            sentiment += wordScore;
        }

        word = strtok(NULL, " ");
    }

    // Normalize the sentiment score
    sentiment = normalizeSentimentScore(sentiment, wordCount);

    return sentiment;
}

int isSentimentWord(char *word)
{
    char *sentimentWords[] = {"happy", "sad", "angry", "joyful", "sad", "excited", "optimistic", "pessimistic"};

    for (int i = 0; i < 8; i++)
    {
        if (strcmp(word, sentimentWords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int getWordSentimentScore(char *word)
{
    char *sentimentScoreWords[] = {"very negative", "negative", "neutral", "positive", "very positive"};

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, sentimentScoreWords[i]) == 0)
        {
            return i - 2;
        }
    }

    return 0;
}

int normalizeSentimentScore(int sentiment, int wordCount)
{
    return sentiment / wordCount;
}