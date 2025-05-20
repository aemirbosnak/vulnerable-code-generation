//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

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
    int i, alive_cells = 0;
    for (i = 0; head; i++) {
        int neighbors = 0;
        Cell* current = head;
        while (current) {
            if (current->state == 1) {
                neighbors++;
            }
            current = current->next;
        }
        if (neighbors == 2) {
            alive_cells++;
            head->state = 1;
        } else if (neighbors == 3) {
            alive_cells++;
            head->state = 1;
        } else {
            head->state = 0;
        }
        head = head->next;
    }
    printf("Number of alive cells: %d\n", alive_cells);
}

int main() {
    Cell* head = NULL;
    initialize_game(&head);
    play_game(head);
    return 0;
}