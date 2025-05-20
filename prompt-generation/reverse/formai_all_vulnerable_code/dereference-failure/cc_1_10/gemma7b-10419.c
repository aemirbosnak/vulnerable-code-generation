//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_WORDS 1024

typedef struct Word
{
    char *word;
    int frequency;
    struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->frequency = 1;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Word *prev = head;
    Word *curr = head;

    while (curr)
    {
        if (strcmp(newNode->word, curr->word) == 0)
        {
            curr->frequency++;
            return head;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    return head;
}

int main()
{
    setlocale(LC_ALL, "");

    Word *head = NULL;

    char *wordList[] = {"apple", "banana", "cherry", "orange", "grape", "mango", "peach", "apricot", "watermelon", "apricot"};

    for (int i = 0; i < 10; i++)
    {
        insertWord(head, wordList[i]);
    }

    Word *curr = head;

    while (curr)
    {
        printf("%s - %d\n", curr->word, curr->frequency);
        curr = curr->next;
    }

    return 0;
}