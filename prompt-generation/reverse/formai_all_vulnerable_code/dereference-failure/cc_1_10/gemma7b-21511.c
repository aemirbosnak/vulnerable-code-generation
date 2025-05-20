//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct Word
{
    char word[20];
    struct Word* next;
} Word;

Word* insertWord(Word* head, char* word)
{
    Word* newWord = malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
    }

    return head;
}

int main()
{
    Word* head = NULL;

    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);

    insertWord(head, word);

    char query[20];
    printf("Enter a query word: ");
    scanf("%s", query);

    Word* currentWord = head;
    while (currentWord)
    {
        if (strcmp(currentWord->word, query) == 0)
        {
            printf("Word found!\n");
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