//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANG_MAX_WORDS 10

typedef struct AlienWord
{
    char *word;
    struct AlienWord *next;
} AlienWord;

AlienWord *alienWordHead = NULL;

void alienWordAdd(char *word)
{
    AlienWord *newWord = (AlienWord *)malloc(sizeof(AlienWord));
    newWord->word = strdup(word);
    newWord->next = alienWordHead;
    alienWordHead = newWord;
}

char *alienWordTranslate(char *alienWord)
{
    AlienWord *currentWord = alienWordHead;
    while (currentWord)
    {
        if (strcmp(alienWord, currentWord->word) == 0)
        {
            return currentWord->word;
        }
        currentWord = currentWord->next;
    }

    return NULL;
}

int main()
{
    alienWordAdd("Thra'nak");
    alienWordAdd("Zork'nak");
    alienWordAdd("Bo'rk");

    char *translatedWord = alienWordTranslate("Bo'rk");

    if (translatedWord)
    {
        printf("Translated word: %s\n", translatedWord);
    }
    else
    {
        printf("Word not found.\n");
    }

    return 0;
}