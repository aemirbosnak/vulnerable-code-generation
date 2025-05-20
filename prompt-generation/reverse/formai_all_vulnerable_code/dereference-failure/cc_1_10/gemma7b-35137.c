//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char *word;
    struct AlienWord *next;
} AlienWord;

AlienWord *alienWordHead = NULL;

void insertAlienWord(char *word)
{
    AlienWord *newWord = malloc(sizeof(AlienWord));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (alienWordHead == NULL)
    {
        alienWordHead = newWord;
    }
    else
    {
        AlienWord *tempWord = alienWordHead;
        while (tempWord->next != NULL)
        {
            tempWord = tempWord->next;
        }
        tempWord->next = newWord;
    }
}

char *translateAlienWord(char *alienWord)
{
    char *translatedWord = malloc(MAX_WORD_LENGTH);

    for (int i = 0; alienWord[i] != '\0'; i++)
    {
        switch (alienWord[i])
        {
            case 'a':
                translatedWord[i] = 'a';
                break;
            case 'e':
                translatedWord[i] = 'e';
                break;
            case 'i':
                translatedWord[i] = 'i';
                break;
            case 'o':
                translatedWord[i] = 'o';
                break;
            case 'u':
                translatedWord[i] = 'u';
                break;
            default:
                translatedWord[i] = alienWord[i];
                break;
        }
    }

    translatedWord[MAX_WORD_LENGTH - 1] = '\0';

    return translatedWord;
}

int main()
{
    insertAlienWord("Xylophone");
    insertAlienWord("Zome");

    char *alienWord = "Barz";
    char *translatedWord = translateAlienWord(alienWord);

    printf("%s", translatedWord);

    return 0;
}