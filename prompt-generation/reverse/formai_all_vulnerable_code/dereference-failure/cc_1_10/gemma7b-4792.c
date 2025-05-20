//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct AlienWord
{
    char alienWord[MAX_WORDS];
    char englishWord[MAX_WORDS];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordHead = NULL;

void insertAlienWord(char* alienWord, char* englishWord)
{
    AlienWord* newNode = (AlienWord*)malloc(sizeof(AlienWord));
    strcpy(newNode->alienWord, alienWord);
    strcpy(newNode->englishWord, englishWord);
    newNode->next = alienWordHead;
    alienWordHead = newNode;
}

char* translateAlienWord(char* alienWord)
{
    AlienWord* currentWord = alienWordHead;
    while (currentWord)
    {
        if (strcmp(currentWord->alienWord, alienWord) == 0)
        {
            return currentWord->englishWord;
        }
        currentWord = currentWord->next;
    }

    return "Unknown";
}

int main()
{
    insertAlienWord("Zork", "Rocket");
    insertAlienWord("Blork", "Car");
    insertAlienWord("Flork", "Ship");

    printf("%s", translateAlienWord("Zork"));
    printf("%s", translateAlienWord("Blork"));
    printf("%s", translateAlienWord("Flork"));

    return 0;
}