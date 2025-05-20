//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
    *head = malloc(sizeof(Cell) * MAX_CELLS);
    for (int i = 0; i < MAX_CELLS; i++) {
        (*head)[i].state = 0;
        (*head)[i].next = NULL;
    }
}

void update_game(Cell** head) {
    for (Cell* cell = *head; cell; cell = cell->next) {
        int alive_neighbors = 0;
        for (Cell* neighbor = cell->next; neighbor; neighbor = neighbor->next) {
            if (neighbor->state == 1) {
                alive_neighbors++;
            }
        }
        if (cell->state == 1 && alive_neighbors < 2) {
            cell->state = 0;
        } else if (cell->state == 0 && alive_neighbors == 3) {
            cell->state = 1;
        }
    }
}

void print_game(Cell* head) {
    for (Cell* cell = head; cell; cell = cell->next) {
        printf("%d ", cell->state);
    }
    printf("\n");
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);

    // Set up the initial game state
    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    // Update the game for 10 generations
    for (int i = 0; i < 10; i++) {
        update_game(&head);
        print_game(head);
    }

    return 0;
}