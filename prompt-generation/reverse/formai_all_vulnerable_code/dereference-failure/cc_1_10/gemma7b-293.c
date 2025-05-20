//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdlib.h>
#include <stdio.h>

#define MAX_CELLS 256

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void simulate_game_of_life(Cell* head) {
    Cell* current = head;
    Cell* next_generation = malloc(sizeof(Cell) * MAX_CELLS);

    // Calculate the next generation
    for (int i = 0; current; i++) {
        int num_alive_neighbors = 0;
        Cell* neighbor = current->next;
        while (neighbor) {
            if (neighbor->state == 1) {
                num_alive_neighbors++;
            }
            neighbor = neighbor->next;
        }

        next_generation[i].state = (num_alive_neighbors == 2) || (num_alive_neighbors == 3);
    }

    // Free the old generation and update the head
    free(head);
    head = next_generation;
}

int main() {
    Cell* head = malloc(sizeof(Cell) * MAX_CELLS);

    // Initialize the game of life
    head->state = 1;
    head->next = malloc(sizeof(Cell) * MAX_CELLS);
    head->next->state = 1;
    head->next->next = malloc(sizeof(Cell) * MAX_CELLS);
    head->next->next->state = 1;

    // Simulate the game of life
    simulate_game_of_life(head);

    // Print the next generation
    Cell* current = head;
    while (current) {
        printf("%d ", current->state);
        current = current->next;
    }

    return 0;
}