//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void play_game(Cell* head) {
    for (Cell* cell = head; cell; cell = cell->next) {
        int neighbors = 0;
        for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
            if (neighbor == cell) continue;
            if (neighbor->state == 1) neighbors++;
        }
        switch (cell->state) {
            case 0:
                if (neighbors == 3) cell->state = 1;
                break;
            case 1:
                if (neighbors < 2 || neighbors > 3) cell->state = 0;
                break;
        }
    }
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);

    // Set up the initial state of the cells
    head->state = 1;
    head->next->state = 0;
    head->next->next->state = 1;

    play_game(head);

    // Print the final state of the cells
    for (Cell* cell = head; cell; cell = cell->next) {
        printf("%d ", cell->state);
    }

    return 0;
}