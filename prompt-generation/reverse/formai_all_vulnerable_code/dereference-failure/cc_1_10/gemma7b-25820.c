//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

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
        head->next = newWord;
    }

    return head;
}

void playMemoryGame(Word *head)
{
    Word *currentWord = head;
    char guessWord[MAX_WORDS];

    printf("Enter guess word: ");
    scanf("%s", guessWord);

    for (int i = 0; currentWord && guessWord[i] != '\0'; i++)
    {
        if (strcmp(guessWord[i], currentWord->word) == 0)
        {
            printf("Word found: %s\n", currentWord->word);
            currentWord = currentWord->next;
        }
    }

    if (currentWord == NULL)
    {
        printf("No match found\n");
    }
}

int main()
{
    Word *head = insertWord(NULL, "apple");
    insertWord(head, "banana");
    insertWord(head, "orange");
    insertWord(head, "grape");

    playMemoryGame(head);

    return 0;
}