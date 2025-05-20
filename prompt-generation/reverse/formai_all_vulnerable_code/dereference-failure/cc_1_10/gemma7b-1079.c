//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORDS 100

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *head = NULL;

void insertWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        head->next = newWord;
        head = newWord;
    }
}

int main()
{
    insertWord("hello");
    insertWord("world");
    insertWord("paranoid");
    insertWord("program");

    char *wordToSearch = "Hello";

    Word *currentWord = head;

    while (currentWord)
    {
        if (strcmp(currentWord->word, wordToSearch) == 0)
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