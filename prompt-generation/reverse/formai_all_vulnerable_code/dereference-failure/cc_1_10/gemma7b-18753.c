//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int alive;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->alive = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void simulate_game(Cell* head) {
    for (Cell* cell = head; cell; cell = cell->next) {
        int num_alive = 0;
        for (Cell* neighbor = head; neighbor; neighbor = neighbor->next) {
            if (neighbor != cell && neighbor->alive) {
                num_alive++;
            }
        }
        if (cell->alive && (num_alive < 2 || num_alive > 3)) {
            cell->alive = 0;
        } else if (!cell->alive && num_alive == 3) {
            cell->alive = 1;
        }
    }
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);

    // Simulate game for a number of generations
    for (int i = 0; i < 10; i++) {
        simulate_game(head);
    }

    // Print the final state of the game
    for (Cell* cell = head; cell; cell = cell->next) {
        printf("%d ", cell->alive);
    }
    printf("\n");

    return 0;
}