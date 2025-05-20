//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void updateGame(Cell** head) {
    Cell* currentCell = *head;
    while (currentCell) {
        int neighbors = 0;
        Cell* neighbor = currentCell->next;
        while (neighbor) {
            if (neighbor->state == 1) {
                neighbors++;
            }
            neighbor = neighbor->next;
        }
        switch (currentCell->state) {
            case 0:
                if (neighbors == 3) {
                    currentCell->state = 1;
                }
                break;
            case 1:
                if (neighbors < 2 || neighbors > 3) {
                    currentCell->state = 0;
                }
                break;
        }
        currentCell = currentCell->next;
    }
}

int main() {
    Cell* head = NULL;
    initializeGame(&head);
    updateGame(&head);
    return 0;
}