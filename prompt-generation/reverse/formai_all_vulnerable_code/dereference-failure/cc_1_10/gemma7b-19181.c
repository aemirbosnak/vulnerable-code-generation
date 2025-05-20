//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word
{
    char word[20];
    struct Word* next;
} Word;

Word* head = NULL;

void insertWord(char* word)
{
    Word* newNode = malloc(sizeof(Word));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Word* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    insertWord("apple");
    insertWord("banana");
    insertWord("cherry");
    insertWord("orange");
    insertWord("peach");

    Word* currentWord = head;
    while (currentWord)
    {
        printf("%s ", currentWord->word);
        currentWord = currentWord->next;
    }

    printf("\n");

    return 0;
}