//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    return newWord;
}

void insertWord(Word **head, char *word)
{
    Word *newWord = createWord(word);

    if (*head == NULL)
    {
        *head = newWord;
    }
    else
    {
        (*head)->next = newWord;
    }
}

int main()
{
    Word *head = NULL;

    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "orange");
    insertWord(&head, "mango");

    Word *currentWord = head;

    while (currentWord)
    {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }

    return 0;
}