//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct Word
{
    char *word;
    int length;
    struct Word *next;
} Word;

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->length = strlen(word);
    newWord->next = NULL;

    return newWord;
}

void addWord(Word **head, char *word)
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

int countWords(Word *head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

int main()
{
    Word *head = NULL;

    addWord(&head, "Knight");
    addWord(&head, "Dragon");
    addWord(&head, "Sword");
    addWord(&head, "Princess");

    int numWords = countWords(head);

    printf("Number of words: %d\n", numWords);

    return 0;
}