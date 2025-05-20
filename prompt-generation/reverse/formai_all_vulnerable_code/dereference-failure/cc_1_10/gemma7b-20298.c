//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* InsertWord(Word* head, char* word)
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

int SpellCheck(Word* head, char* word)
{
    Word* currentWord = head;

    while (currentWord)
    {
        if (strcmp(currentWord->word, word) == 0)
        {
            return 1;
        }

        currentWord = currentWord->next;
    }

    return 0;
}

int main()
{
    Word* head = NULL;

    InsertWord(head, "apple");
    InsertWord(head, "banana");
    InsertWord(head, "orange");
    InsertWord(head, "grape");

    if (SpellCheck(head, "apple") == 1)
    {
        printf("Apple is in the list.\n");
    }

    if (SpellCheck(head, "banana") == 1)
    {
        printf("Banana is in the list.\n");
    }

    if (SpellCheck(head, "mango") == 0)
    {
        printf("Mango is not in the list.\n");
    }

    return 0;
}