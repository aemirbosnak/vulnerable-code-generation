//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_GENERATIONS 10
#define GRID_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < GRID_SIZE; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void updateGame(Cell* head) {
    for (Cell* current = head; current; current = current->next) {
        int neighbors = 0;
        for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
            if (neighbor == current) continue;
            if (neighbor->state) neighbors++;
        }

        if (neighbors < 2) current->state = 0;
        else if (neighbors > 3) current->state = 0;
        else current->state = 1;
    }
}

int main() {
    Cell* head = NULL;
    initializeGame(&head);

    // Simulate game for MAX_GENERATIONS generations
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        updateGame(head);
    }

    // Print final grid
    for (Cell* current = head; current; current = current->next) {
        printf("%d ", current->state);
    }
    printf("\n");

    return 0;
}