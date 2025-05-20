//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
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

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->length = strlen(word);
    newWord->next = NULL;

    return newWord;
}

void addWord(Word *head, char *word)
{
    Word *newWord = createWord(word);

    if (head == NULL)
    {
        head = newWord;
    }
    else
    {
        Word *traversal = head;

        while (traversal->next)
        {
            traversal = traversal->next;
        }

        traversal->next = newWord;
    }
}

int countWords(Word *head)
{
    int count = 0;

    Word *traversal = head;

    while (traversal)
    {
        count++;
        traversal = traversal->next;
    }

    return count;
}

int main()
{
    Word *head = NULL;

    addWord(head, "Hello");
    addWord(head, "World");
    addWord(head, "!");

    int wordCount = countWords(head);

    printf("The number of words in the list is: %d\n", wordCount);

    return 0;
}