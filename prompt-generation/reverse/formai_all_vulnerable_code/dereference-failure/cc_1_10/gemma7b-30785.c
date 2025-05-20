//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
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
        head->next = insertWord(head->next, word);
    }

    return head;
}

int translateWord(Word *head, char *sourceWord)
{
    Word *currentWord = head;

    while (currentWord)
    {
        if (strcmp(currentWord->word, sourceWord) == 0)
        {
            return currentWord->next->word;
        }

        currentWord = currentWord->next;
    }

    return NULL;
}

int main()
{
    Word *head = NULL;
    insertWord(head, "Hello");
    insertWord(head, "World");
    insertWord(head, "Cat");
    insertWord(head, "C");

    char *sourceWord = "C";
    char *translatedWord = translateWord(head, sourceWord);

    if (translatedWord)
    {
        printf("%s", translatedWord);
    }
    else
    {
        printf("Word not found");
    }

    return 0;
}