//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20

typedef struct Word
{
    char word[MAX_WORD_LEN];
    struct Word* next;
} Word;

Word* InsertWord(Word* head, char* word)
{
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    head->next = InsertWord(head->next, word);
    return head;
}

int SpellCheck(Word* head, char* word)
{
    Word* currentWord = head;

    while (currentWord)
    {
        if (strcmp(word, currentWord->word) == 0)
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
    InsertWord(head, "cherry");
    InsertWord(head, "orange");

    if (SpellCheck(head, "apple") == 1)
    {
        printf("apple is in the dictionary.\n");
    }

    if (SpellCheck(head, "banana") == 1)
    {
        printf("banana is in the dictionary.\n");
    }

    if (SpellCheck(head, "mango") == 0)
    {
        printf("mango is not in the dictionary.\n");
    }

    return 0;
}