//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct CatWord
{
    char word[MAX_WORD_LENGTH];
    struct CatWord* next;
} CatWord;

CatWord* insertWord(CatWord* head, char* word)
{
    CatWord* newWord = malloc(sizeof(CatWord));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        CatWord* currentWord = head;
        while (currentWord->next)
        {
            currentWord = currentWord->next;
        }
        currentWord->next = newWord;
    }

    return head;
}

int translateCat(CatWord* head, char* source, char* target)
{
    char* sourceWord = strtok(source, " ");
    char* targetWord = strtok(target, " ");

    while (sourceWord && targetWord)
    {
        CatWord* currentWord = head;

        while (currentWord)
        {
            if (strcmp(sourceWord, currentWord->word) == 0)
            {
                strcpy(targetWord, currentWord->word);
                break;
            }
            currentWord = currentWord->next;
        }

        sourceWord = strtok(NULL, " ");
        targetWord = strtok(NULL, " ");
    }

    return 0;
}

int main()
{
    CatWord* head = NULL;

    insertWord(head, "Meow");
    insertWord(head, "Woof");
    insertWord(head, "Chirp");

    char* source = "Meow Woof";
    char* target = "Chirp Meow";

    translateCat(head, source, target);

    printf("%s", target);

    return 0;
}