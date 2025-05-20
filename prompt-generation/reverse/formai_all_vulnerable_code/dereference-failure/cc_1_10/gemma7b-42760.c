//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryItem {
    char *item;
    struct MemoryItem *next;
} MemoryItem;

void initializeMemory(MemoryItem **head) {
    *head = NULL;
}

void addToMemory(MemoryItem **head, char *item) {
    MemoryItem *newNode = malloc(sizeof(MemoryItem));
    newNode->item = strdup(item);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void playMemoryGame(MemoryItem **head) {
    char **words = malloc(MAX_MEMORY_SIZE * sizeof(char *));
    int i = 0;

    for (MemoryItem *item = head; item; item = item->next) {
        words[i++] = item->item;
    }

    srand(time(NULL));
    int randomIndex = rand() % MAX_MEMORY_SIZE;
    char *guessWord = words[randomIndex];

    printf("Guess the word: ");
    char guessWordInput[20];
    scanf("%s", guessWordInput);

    if (strcmp(guessWordInput, guessWord) == 0) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, the word is not correct.\n");
    }
}

int main() {
    MemoryItem *head = NULL;

    // Add items to the memory
    addToMemory(&head, "Apple");
    addToMemory(&head, "Banana");
    addToMemory(&head, "Orange");
    addToMemory(&head, "Mango");
    addToMemory(&head, "Peach");

    // Play the memory game
    playMemoryGame(&head);

    return 0;
}