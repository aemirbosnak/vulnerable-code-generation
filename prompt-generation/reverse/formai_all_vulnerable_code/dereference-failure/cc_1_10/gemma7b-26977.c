//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 1024

typedef struct SentimentWord
{
    char word[MAX_WORDS];
    int sentiment;
    struct SentimentWord* next;
} SentimentWord;

SentimentWord* createWord(char* word, int sentiment)
{
    SentimentWord* newWord = malloc(sizeof(SentimentWord));
    strcpy(newWord->word, word);
    newWord->sentiment = sentiment;
    newWord->next = NULL;
    return newWord;
}

void analyzeSentiment(char* text)
{
    SentimentWord* head = NULL;
    char* word = strtok(text, " ");

    while (word)
    {
        int sentiment = getSentiment(word);
        head = createWord(word, sentiment);

        word = strtok(NULL, " ");
    }

    int totalSentiment = 0;
    for (SentimentWord* currentWord = head; currentWord; currentWord = currentWord->next)
    {
        totalSentiment += currentWord->sentiment;
    }

    printf("Total sentiment: %d\n", totalSentiment);
}

int getSentiment(char* word)
{
    // Sentiment dictionary
    int sentimentDict[] = {
        -2, // hate
        -1, // dislike
        0, // neutral
        1, // like
        2 // love
    };

    // Search for word in dictionary
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(word, sentimentDict[i]) == 0)
        {
            return sentimentDict[i];
        }
    }

    // Return neutral if word not found
    return 0;
}

int main()
{
    analyzeSentiment("I love this movie!");
    analyzeSentiment("This movie is terrible!");

    return 0;
}