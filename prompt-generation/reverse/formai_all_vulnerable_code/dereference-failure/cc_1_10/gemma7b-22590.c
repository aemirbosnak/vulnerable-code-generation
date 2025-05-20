//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

void insertWord(Word **head, char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (*head == NULL)
    {
        *head = newWord;
    }
    else
    {
        (*head)->next = newWord;
    }
}

void playGame(Word **head)
{
    int i, score = 0, guessWord;
    Word *currentWord = *head;

    for (i = 0; i < MAX_WORDS && currentWord; i++)
    {
        printf("Guess the word: ");
        scanf("%d", &guessWord);

        if (guessWord == currentWord->word)
        {
            printf("Correct! You gain a point.\n");
            score++;
        }
        else
        {
            printf("Incorrect. The word is %s.\n", currentWord->word);
        }

        currentWord = currentWord->next;
    }

    printf("Your score: %d\n", score);
}

int main()
{
    Word *head = NULL;

    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "orange");
    insertWord(&head, "grape");
    insertWord(&head, "apricot");
    insertWord(&head, "peach");

    playGame(&head);

    return 0;
}