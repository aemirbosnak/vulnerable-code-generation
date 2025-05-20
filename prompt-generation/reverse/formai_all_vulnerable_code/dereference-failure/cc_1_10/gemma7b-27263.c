//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *head = NULL;

void addWord(char *word)
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
    char **words = NULL;
    int i = 0;

    words = malloc(MAX_WORDS * sizeof(char *));

    for (i = 0; i < MAX_WORDS; i++)
    {
        words[i] = malloc(20 * sizeof(char));
    }

    addWord("Apple");
    addWord("Banana");
    addWord("Orange");
    addWord("Peach");
    addWord("Mango");

    printf("Words in the list:");

    for (i = 0; i < MAX_WORDS; i++)
    {
        if (words[i] != NULL)
        {
            printf("%s ", words[i]);
        }
    }

    printf("\n");

    return 0;
}