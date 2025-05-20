//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 1;
    newWord->next = NULL;

    return newWord;
}

void addWord(Word *wordList, char *word)
{
    Word *newWord = createWord(word);

    if (wordList == NULL)
    {
        wordList = newWord;
    }
    else
    {
        Word *currentWord = wordList;

        while (currentWord->next)
        {
            currentWord = currentWord->next;
        }

        currentWord->next = newWord;
    }
}

int main()
{
    char text[] = "I am a happy person. The world is a beautiful place.";

    Word *wordList = NULL;

    addWord(wordList, "happy");
    addWord(wordList, "beautiful");
    addWord(wordList, "person");
    addWord(wordList, "world");

    for (Word *currentWord = wordList; currentWord; currentWord = currentWord->next)
    {
        printf("%s: %d\n", currentWord->word, currentWord->frequency);
    }

    return 0;
}