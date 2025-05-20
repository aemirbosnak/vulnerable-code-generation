//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

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

int countWords(Word *head)
{
    int count = 0;

    for (Word *word = head; word; word = word->next)
    {
        count++;
    }

    return count;
}

int main()
{
    Word *head = NULL;

    char *wordList[] = {"apple", "banana", "cherry", "orange", "peach", "apricot"};

    for (int i = 0; i < 6; i++)
    {
        insertWord(head, wordList[i]);
    }

    int wordCount = countWords(head);

    printf("Total number of words: %d\n", wordCount);

    return 0;
}