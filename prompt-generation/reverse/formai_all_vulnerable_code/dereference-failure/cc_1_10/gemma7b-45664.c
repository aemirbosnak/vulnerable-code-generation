//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryItem {
    char *word;
    struct MemoryItem *next;
} MemoryItem;

MemoryItem *createMemoryItem(char *word) {
    MemoryItem *newItem = malloc(sizeof(MemoryItem));
    newItem->word = strdup(word);
    newItem->next = NULL;
    return newItem;
}

void addToMemory(MemoryItem **head, char *word) {
    MemoryItem *newItem = createMemoryItem(word);
    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
        *head = (*head)->next;
    }
}

int main() {
    srand(time(NULL));

    MemoryItem *head = NULL;
    char **words = malloc(MAX_MEMORY_SIZE * sizeof(char *));
    words[0] = "Apple";
    words[1] = "Banana";
    words[2] = "Orange";
    words[3] = "Pear";
    words[4] = "Grapes";

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        addToMemory(&head, words[i]);
    }

    int guessCount = 0;
    char guessWord[20];

    printf("Welcome to the Memory Game!\n");
    printf("Guess the fruit: ");

    scanf("%s", guessWord);

    MemoryItem *currentItem = head;

    while (currentItem) {
        if (strcmp(guessWord, currentItem->word) == 0) {
            guessCount++;
            printf("You guessed the fruit: %s\n", currentItem->word);
        }
        currentItem = currentItem->next;
    }

    printf("Your guess count: %d\n", guessCount);

    return 0;
}