//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 20

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

void insertWord(Word **head, char *word)
{
    Word *newNode = malloc(sizeof(Word));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void playGame(Word **head)
{
    char guessWord[MAX_WORDS];
    int guesses = 0;
    Word *currentWord = *head;

    printf("Welcome to the Word Guessing Game!\n");

    // Loop until the player guesses the word or runs out of guesses
    while (!strcmp(guessWord, currentWord->word) && guesses < 5)
    {
        printf("Guess a word: ");
        scanf("%s", guessWord);

        guesses++;

        // Check if the guess is correct
        if (!strcmp(guessWord, currentWord->word))
        {
            printf("Congratulations! You guessed the word: %s\n", currentWord->word);
        }
        else
        {
            printf("Sorry, that is not the word. Try again.\n");
        }

        currentWord = currentWord->next;
    }

    // If the player runs out of guesses
    if (guesses == 5)
    {
        printf("Sorry, you ran out of guesses. The answer was: %s\n", currentWord->word);
    }
}

int main()
{
    Word *head = NULL;
    insertWord(&head, "apple");
    insertWord(&head, "banana");
    insertWord(&head, "orange");
    insertWord(&head, "grapefruit");

    playGame(&head);

    return 0;
}