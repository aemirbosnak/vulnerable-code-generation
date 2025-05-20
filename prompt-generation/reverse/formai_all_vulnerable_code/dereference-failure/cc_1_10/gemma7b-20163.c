//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct CAT_WORD
{
    char word[MAX_WORD_LENGTH];
    struct CAT_WORD* next;
} CAT_WORD;

CAT_WORD* CAT_WORD_NEW(char* word)
{
    CAT_WORD* newWord = malloc(sizeof(CAT_WORD));
    strcpy(newWord->word, word);
    newWord->next = NULL;
    return newWord;
}

void CAT_WORD_ADD(CAT_WORD* head, char* word)
{
    CAT_WORD* newWord = CAT_WORD_NEW(word);
    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
    }
}

void CAT_WORD_PRINT(CAT_WORD* head)
{
    CAT_WORD* currentWord = head;
    while (currentWord)
    {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }
    printf("\n");
}

int main()
{
    CAT_WORD* head = NULL;
    CAT_WORD_ADD(head, "Meow");
    CAT_WORD_ADD(head, "Purr");
    CAT_WORD_ADD(head, "Meow");

    CAT_WORD_PRINT(head);

    return 0;
}