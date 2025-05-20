//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

void insertWord(Word **head, char *word)
{
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

int spellCheck(Word *head, char *word)
{
    for (Word *curr = head; curr; curr = curr->next)
    {
        if (strcmp(curr->word, word) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    Word *head = NULL;
    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "cherry");
    insertWord(&head, "orange");

    char *word = "apple";

    if (spellCheck(head, word) == 1)
    {
        printf("Word found: %s\n", word);
    }
    else
    {
        printf("Word not found: %s\n", word);
    }

    return 0;
}