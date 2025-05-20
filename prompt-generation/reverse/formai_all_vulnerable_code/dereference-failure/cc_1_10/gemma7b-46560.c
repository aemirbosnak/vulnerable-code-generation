//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 10

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = rand() % 2;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void playGame(Cell* head) {
    Cell* current = head;
    while (current) {
        int neighbors = 0;
        for (Cell* neighbor = current->next; neighbor; neighbor = neighbor->next) {
            if (neighbor->state == 1) {
                neighbors++;
            }
        }
        int nextState = current->state;
        if (neighbors < 2) {
            nextState = 0;
        } else if (neighbors > 3) {
            nextState = 0;
        } else if (neighbors == 2) {
            nextState = current->state;
        } else if (neighbors == 3) {
            nextState = 1;
        }
        current->state = nextState;
        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initGame(&head);
    playGame(head);
    return 0;
}