//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word **createWordList(char **text, int textLength);
int analyzeSentiment(Word **words, int numWords);

int main()
{
    char **text = malloc(1024);
    text[0] = "I am very happy today. The sun is shining and the flowers are blooming.";

    Word **words = createWordList(text, 1024);
    int sentiment = analyzeSentiment(words, 10);

    if (sentiment == 0)
    {
        printf("Neutral\n");
    }
    else if (sentiment == 1)
    {
        printf("Positive\n");
    }
    else
    {
        printf("Negative\n");
    }

    free(text);
    free(words);

    return 0;
}

Word **createWordList(char **text, int textLength)
{
    int numWords = 0;
    Word **words = NULL;

    for (int i = 0; i < textLength; i++)
    {
        char *word = strdup(text[i]);
        Word *newWord = malloc(sizeof(Word));
        newWord->word = word;
        newWord->frequency = 1;

        words = realloc(words, (numWords + 1) * sizeof(Word));
        words[numWords++] = newWord;
    }

    return words;
}

int analyzeSentiment(Word **words, int numWords)
{
    int positiveWords = 0;
    int negativeWords = 0;

    for (int i = 0; i < numWords; i++)
    {
        if (strcmp(words[i]->word, "happy") == 0 || strcmp(words[i]->word, "joy") == 0)
        {
            positiveWords++;
        }
        else if (strcmp(words[i]->word, "sad") == 0 || strcmp(words[i]->word, "anger") == 0)
        {
            negativeWords++;
        }
    }

    if (positiveWords > negativeWords)
    {
        return 1;
    }
    else if (negativeWords > positiveWords)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}