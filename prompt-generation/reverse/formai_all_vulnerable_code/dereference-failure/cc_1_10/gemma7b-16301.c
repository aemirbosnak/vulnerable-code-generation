//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct Word
{
    char *word;
    int frequency;
} Word;

Word **createWordList(char **text, int textLength)
{
    Word **wordList = malloc(sizeof(Word *) * textLength);
    for (int i = 0; i < textLength; i++)
    {
        wordList[i] = malloc(sizeof(Word));
        wordList[i]->word = strdup(text[i]);
        wordList[i]->frequency = 1;
    }

    return wordList;
}

void analyzeSentiment(Word **wordList, int wordListLength)
{
    for (int i = 0; i < wordListLength; i++)
    {
        // Sentiment analysis logic
        if (wordList[i]->word[0] == 'a' || wordList[i]->word[0] == 'e' || wordList[i]->word[0] == 'i' || wordList[i]->word[0] == 'o' || wordList[i]->word[0] == 'u')
        {
            wordList[i]->frequency *= 2;
        }
        else if (wordList[i]->word[0] == 'n' || wordList[i]->word[0] == 's' || wordList[i]->word[0] == 't')
        {
            wordList[i]->frequency *= 3;
        }
    }
}

int main()
{
    char **text = malloc(sizeof(char *) * 10);
    text[0] = "I am very happy today.";
    text[1] = "I am sad today.";
    text[2] = "I am angry today.";
    text[3] = "I am grateful today.";

    int textLength = 4;

    Word **wordList = createWordList(text, textLength);
    analyzeSentiment(wordList, textLength);

    for (int i = 0; i < textLength; i++)
    {
        printf("%s: %d\n", wordList[i]->word, wordList[i]->frequency);
    }

    return 0;
}