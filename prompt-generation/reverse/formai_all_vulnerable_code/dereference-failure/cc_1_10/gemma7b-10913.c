//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20

typedef struct Word
{
    char *word;
    struct Word *next;
} Word;

Word *createWord(char *word)
{
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
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

int main()
{
    Word *head = NULL;
    addWord(&head, "apple");
    addWord(&head, "banana");
    addWord(&head, "orange");
    addWord(&head, "grape");
    addWord(&head, "mango");

    char guessWord[MAX_WORDS];
    printf("Guess a word: ");
    scanf("%s", guessWord);

    Word *currentWord = head;
    while (currentWord)
    {
        if (strcmp(guessWord, currentWord->word) == 0)
        {
            printf("You guessed the word: %s\n", currentWord->word);
            break;
        }
        currentWord = currentWord->next;
    }

    if (currentWord == NULL)
    {
        printf("Sorry, the word was not found.\n");
    }

    return 0;
}