//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY_SIZE 10

typedef struct MemoryCell {
    int data;
    struct MemoryCell* next;
} MemoryCell;

void initializeMemory(MemoryCell** head) {
    *head = NULL;
}

void addToMemory(MemoryCell** head, int data) {
    MemoryCell* newCell = malloc(sizeof(MemoryCell));
    newCell->data = data;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
        *head = newCell;
    }
}

void playMemoryGame(MemoryCell* head) {
    int targetData = rand() % MAX_MEMORY_SIZE;
    int guessData;

    printf("Target data: %d\n", targetData);

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        printf("Guess data: ");
        scanf("%d", &guessData);

        if (guessData == targetData) {
            printf("Congratulations!\n");
            break;
        } else if (guessData < targetData) {
            printf("Too low.\n");
        } else {
            printf("Too high.\n");
        }
    }

    printf("Game over.\n");
}

int main() {
    MemoryCell* head = NULL;
    initializeMemory(&head);

    for (int i = 0; i < MAX_MEMORY_SIZE; i++) {
        addToMemory(&head, i);
    }

    playMemoryGame(head);

    return 0;
}