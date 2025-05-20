//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
    char word[MAX_WORD_LENGTH];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWordHead = NULL;

void alienWordAdd(char* word)
{
    AlienWord* newNode = malloc(sizeof(AlienWord));
    strcpy(newNode->word, word);
    newNode->next = alienWordHead;
    alienWordHead = newNode;
}

char* alienWordTranslate(char* alienWord)
{
    AlienWord* currentWord = alienWordHead;
    while (currentWord)
    {
        if (strcmp(currentWord->word, alienWord) == 0)
        {
            return currentWord->word;
        }
        currentWord = currentWord->next;
    }

    return "Unknown";
}

int main()
{
    alienWordAdd("Blorg");
    alienWordAdd("Zork");
    alienWordAdd("Gork");

    char* alienWord = "Zork";
    char* translatedWord = alienWordTranslate(alienWord);

    printf("Translated word: %s\n", translatedWord);

    return 0;
}