//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    struct Cell* next;
} Cell;

void initialize_game(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;
}

void create_cell(Cell** head, int x, int y) {
    Cell* new_cell = malloc(sizeof(Cell));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = NULL;

    if (*head) {
        (*head)->next = new_cell;
        *head = new_cell;
    } else {
        *head = new_cell;
    }
}

void simulate_game(Cell* head) {
    int i, j, alive_cells = 0;
    Cell* current_cell = head;

    for (i = 0; i < MAX_CELLS; i++) {
        for (j = 0; j < MAX_CELLS; j++) {
            int neighbors = 0;
            Cell* neighbor_cell = current_cell;

            while (neighbor_cell) {
                if (neighbor_cell->x == current_cell->x - 1 && neighbor_cell->y == current_cell->y) {
                    neighbors++;
                } else if (neighbor_cell->x == current_cell->x + 1 && neighbor_cell->y == current_cell->y) {
                    neighbors++;
                } else if (neighbor_cell->x == current_cell->x && neighbor_cell->y == current_cell->y - 1) {
                    neighbors++;
                } else if (neighbor_cell->x == current_cell->x && neighbor_cell->y == current_cell->y + 1) {
                    neighbors++;
                }
                neighbor_cell = neighbor_cell->next;
            }

            if (neighbors == 2) {
                alive_cells++;
            }
        }
    }

    printf("Number of alive cells: %d\n", alive_cells);
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);
    create_cell(&head, 10, 10);
    create_cell(&head, 10, 11);
    create_cell(&head, 11, 10);
    simulate_game(head);

    return 0;
}