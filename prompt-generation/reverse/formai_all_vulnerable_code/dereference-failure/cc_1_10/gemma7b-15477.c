//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct AlienWord
{
    char alienWord[MAX_WORDS];
    int alienWordLength;
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordHead = NULL;

void addAlienWord(char* alienWord, int alienWordLength)
{
    AlienWord* newWord = malloc(sizeof(AlienWord));
    newWord->alienWordLength = alienWordLength;
    strcpy(newWord->alienWord, alienWord);
    newWord->next = alienWordHead;
    alienWordHead = newWord;
}

void translateAlienWord(char* alienWord)
{
    AlienWord* currentWord = alienWordHead;
    while (currentWord)
    {
        if (strcmp(currentWord->alienWord, alienWord) == 0)
        {
            printf("Translation: %s\n", currentWord->alienWord);
            break;
        }
        currentWord = currentWord->next;
    }

    if (currentWord == NULL)
    {
        printf("Translation not found.\n");
    }
}

int main()
{
    addAlienWord("Tr'sk'bl'z", 12);
    addAlienWord("X'zt'l", 8);
    addAlienWord("Bl'z'k'h", 10);

    translateAlienWord("Tr'sk'bl'z");
    translateAlienWord("X'zt'l");
    translateAlienWord("Bl'z'k'h");

    return 0;
}