//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = rand() % 2;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void playGame(Cell* head) {
    while (head) {
        int neighbors = 0;
        Cell* current = head;
        while (current) {
            if (current->state == 1) {
                neighbors++;
            }
            current = current->next;
        }

        if (neighbors < 2) {
            head->state = 0;
        } else if (neighbors == 2) {
            head->state = 1;
        } else if (neighbors > 2) {
            head->state = 0;
        }

        head = head->next;
    }
}

int main() {
    Cell* head = NULL;
    initializeGame(&head);
    playGame(head);

    return 0;
}