//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY 10
#define MAX_ROUNDS 5

typedef struct MemoryItem {
    char *word;
    struct MemoryItem *next;
} MemoryItem;

void initializeMemory(MemoryItem **head) {
    *head = NULL;
}

void addToMemory(MemoryItem **head, char *word) {
    MemoryItem *newItem = malloc(sizeof(MemoryItem));
    newItem->word = strdup(word);
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

int main() {
    MemoryItem *head = NULL;
    initializeMemory(&head);

    // Populate the memory with words
    addToMemory(&head, "apple");
    addToMemory(&head, "banana");
    addToMemory(&head, "orange");
    addToMemory(&head, "grapefruit");
    addToMemory(&head, "pineapple");

    // Start the game
    int round = 0;
    char guessWord[MAX_MEMORY];

    while (round < MAX_ROUNDS) {
        // Generate a random word
        int index = rand() % MAX_MEMORY;
        guessWord[0] = head->word[index];

        // Ask the player to guess the word
        printf("Guess the word: ");
        scanf("%s", guessWord);

        // Check if the guess word is correct
        if (strcmp(guessWord, head->word[index]) == 0) {
            printf("Congratulations! You guessed the word: %s\n", head->word[index]);
        } else {
            printf("Sorry, the word is: %s\n", head->word[index]);
        }

        round++;
    }

    return 0;
}