//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize(Cell* head) {
    head = (Cell*)malloc(MAX_SIZE * sizeof(Cell));
    head->state = 0;
    head->next = NULL;
}

void simulate(Cell* head) {
    Cell* current = head;
    while (current) {
        int neighbors = 0;
        Cell* neighbor = current->next;
        while (neighbor) {
            if (neighbor->state == 1) {
                neighbors++;
            }
            neighbor = neighbor->next;
        }

        switch (current->state) {
            case 0:
                if (neighbors == 3) {
                    current->state = 1;
                }
                break;
            case 1:
                if (neighbors < 2 || neighbors > 3) {
                    current->state = 0;
                }
                break;
        }

        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(head);

    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    simulate(head);

    Cell* current = head;
    while (current) {
        printf("%d ", current->state);
        current = current->next;
    }

    return 0;
}