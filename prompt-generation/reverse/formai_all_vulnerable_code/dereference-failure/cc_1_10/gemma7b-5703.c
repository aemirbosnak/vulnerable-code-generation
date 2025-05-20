//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

int main()
{
    char text[MAX_WORDS];
    printf("Enter text: ");
    fgets(text, MAX_WORDS, stdin);

    char words[MAX_WORDS][MAX_WORDS];
    int numWords = tokenize(text, words);

    int sentimentScore = calculateSentimentScore(words);

    printf("Sentiment score: %d\n", sentimentScore);

    return 0;
}

int tokenize(char *text, char ***words)
{
    int numWords = 0;
    char *token = strtok(text, " ");
    while (token)
    {
        strcpy((*words)[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }
    return numWords;
}

int calculateSentimentScore(char **words)
{
    int score = 0;
    for (int i = 0; words[i]; i++)
    {
        if (isPositiveWord(words[i]))
        {
            score++;
        }
        else if (isNegativeWord(words[i]))
        {
            score--;
        }
    }
    return score;
}

int isPositiveWord(char *word)
{
    char *positiveWords[] = {"happy", "joy", "love", "good", "excellent"};
    for (int i = 0; positiveWords[i]; i++)
    {
        if (strcmp(word, positiveWords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isNegativeWord(char *word)
{
    char *negativeWords[] = {"sad", "hate", "bad", "terrible", "awful"};
    for (int i = 0; negativeWords[i]; i++)
    {
        if (strcmp(word, negativeWords[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}