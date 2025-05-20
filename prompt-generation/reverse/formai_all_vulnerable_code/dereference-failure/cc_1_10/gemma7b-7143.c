//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initGame(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
}

void playGame(Cell* head) {
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

        int stateChange = 0;
        if (current->state == 0 && neighbors == 3) {
            stateChange = 1;
        } else if (current->state == 1 && (neighbors < 2 || neighbors > 3)) {
            stateChange = -1;
        }

        if (stateChange) {
            current->state = -stateChange;
        }
        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initGame(&head);

    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    playGame(head);

    head = head->next;
    while (head) {
        printf("%d ", head->state);
        head = head->next;
    }

    return 0;
}