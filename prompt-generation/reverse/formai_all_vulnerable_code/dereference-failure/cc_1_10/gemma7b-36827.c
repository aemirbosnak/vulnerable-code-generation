//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void playGame(Cell* head) {
    int aliveCells = 0;
    for (Cell* cell = head; cell; cell = cell->next) {
        int neighbors = 0;
        for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
            if (cell != neighbor && cell->state == 1 && neighbor->state == 1) {
                neighbors++;
            }
        }
        if (neighbors < 2) {
            cell->state = 0;
        } else if (neighbors > 3) {
            cell->state = 0;
        } else if (cell->state == 0 && neighbors == 2) {
            cell->state = 1;
        }
        aliveCells++;
    }

    printf("Number of alive cells: %d\n", aliveCells);
}

int main() {
    Cell* head = NULL;
    initGame(&head);

    // Set some cells to alive
    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    playGame(head);

    return 0;
}