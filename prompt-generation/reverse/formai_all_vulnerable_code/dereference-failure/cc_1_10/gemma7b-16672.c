//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = insertWord(head->next, word);
    }

    return head;
}

int translateWord(Word *head, char *source)
{
    Word *current = head;

    while (current)
    {
        if (strcmp(source, current->word) == 0)
        {
            printf("%s ", current->next->word);
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int main()
{
    Word *head = NULL;

    insertWord(head, "Love");
    insertWord(head, "Passion");
    insertWord(head, "Desire");
    insertWord(head, "Inflame");

    char *source = "Desire";

    translateWord(head, source);

    return 0;
}