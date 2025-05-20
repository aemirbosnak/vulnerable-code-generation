//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char word[MAX_WORD_LENGTH];
    struct Word* next;
} Word;

Word* InsertWord(Word* head, char* word)
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
        head->next = InsertWord(head->next, word);
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

    char* wordToSearch = "apple";

    if (SpellCheck(head, wordToSearch) == 1)
    {
        printf("Word found: %s\n", wordToSearch);
    }
    else
    {
        printf("Word not found: %s\n", wordToSearch);
    }

    return 0;
}