//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct Word
{
    char *word;
    int length;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->length = strlen(word);
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

int main()
{
    Word *head = NULL;

    char *word = "Hello, world!";
    insertWord(head, word);

    word = "This is a sentence.";
    insertWord(head, word);

    word = "The quick brown fox jumps over the lazy dog.";
    insertWord(head, word);

    Word *currentWord = head;

    while (currentWord)
    {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }

    printf("\n");

    return 0;
}