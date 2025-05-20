//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char word[256];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word)
{
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

int main()
{
    Word* head = NULL;

    insertWord(head, "Altos");
    insertWord(head, "Botox");
    insertWord(head, "Clot");
    insertWord(head, "Dog");
    insertWord(head, "Fluff");
    insertWord(head, "Galant");
    insertWord(head, "Haze");
    insertWord(head, "Ido") ;
    insertWord(head, "Jabber");

    char query[256];

    printf("Enter a word: ");
    scanf("%s", query);

    Word* currentWord = head;

    while (currentWord)
    {
        if (strcmp(currentWord->word, query) == 0)
        {
            printf("Word found: %s\n", currentWord->word);
            break;
        }
        currentWord = currentWord->next;
    }

    if (currentWord == NULL)
    {
        printf("Word not found.\n");
    }

    return 0;
}