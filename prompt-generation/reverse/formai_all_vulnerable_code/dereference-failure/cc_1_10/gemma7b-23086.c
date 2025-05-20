//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct AlienWord
{
    char word[MAX_WORD_LENGTH];
    struct AlienWord* next;
} AlienWord;

AlienWord* alienWord_create(char* word)
{
    AlienWord* newWord = (AlienWord*)malloc(sizeof(AlienWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void alienWord_add(AlienWord* head, char* word)
{
    AlienWord* newWord = alienWord_create(word);
    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
    }
}

int alienWord_search(AlienWord* head, char* word)
{
    for (AlienWord* currentWord = head; currentWord != NULL; currentWord = currentWord->next)
    {
        if (strcmp(currentWord->word, word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    AlienWord* alienWordHead = NULL;
    alienWord_add(alienWordHead, "Zork");
    alienWord_add(alienWordHead, "Blork");
    alienWord_add(alienWordHead, "Flork");

    if (alienWord_search(alienWordHead, "Zork") == 1)
    {
        printf("Zork has been found.\n");
    }

    return 0;
}