//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 100

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
}

void update_cell(Cell* cell) {
    int alive_neighbors = 0;
    Cell* current = cell;
    while (current) {
        if (current->state == 1) {
            alive_neighbors++;
        }
        current = current->next;
    }

    if (cell->state == 1 && alive_neighbors < 2) {
        cell->state = 0;
    } else if (cell->state == 0 && alive_neighbors == 3) {
        cell->state = 1;
    }
}

void play_game(Cell** head) {
    for (int i = 0; i < MAX_CELLS; i++) {
        update_cell(*head);
        head = &((*head)->next);
    }
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);

    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    play_game(&head);

    return 0;
}