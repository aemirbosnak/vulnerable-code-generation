//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int alive;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = NULL;
}

void addCell(Cell** head, int alive) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->alive = alive;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

void simulate(Cell* head) {
    Cell* currentCell = head;
    while (currentCell) {
        int neighbors = 0;
        Cell* neighbor = currentCell->next;
        while (neighbor) {
            if (neighbor->alive) {
                neighbors++;
            }
            neighbor = neighbor->next;
        }

        if (currentCell->alive && neighbors < 2) {
            currentCell->alive = 0;
        } else if (!currentCell->alive && neighbors == 3) {
            currentCell->alive = 1;
        }
        currentCell = currentCell->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    // Add some cells
    addCell(&head, 1);
    addCell(&head, 1);
    addCell(&head, 0);
    addCell(&head, 1);
    addCell(&head, 0);

    // Simulate
    simulate(head);

    // Print the results
    Cell* currentCell = head;
    while (currentCell) {
        printf("%d ", currentCell->alive);
        currentCell = currentCell->next;
    }

    return 0;
}