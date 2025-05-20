//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x;
    int y;
    int state;
    struct Cell* next;
} Cell;

void InitializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        Cell* newCell = malloc(sizeof(Cell));
        newCell->x = i;
        newCell->y = 0;
        newCell->state = rand() % 2;
        newCell->next = *head;
        *head = newCell;
    }
}

void SimulateRound(Cell** head) {
    Cell* currentCell = *head;
    while (currentCell) {
        int neighborsAlive = 0;
        Cell* neighbor = currentCell->next;
        while (neighbor) {
            if (neighbor->x == currentCell->x - 1 && neighbor->y == currentCell->y) {
                neighborsAlive++;
            }
            neighbor = neighbor->next;
        }

        int stateChange = 0;
        if (currentCell->state == 0 && neighborsAlive == 3) {
            stateChange = 1;
        } else if (currentCell->state == 1 && neighborsAlive < 2) {
            stateChange = -1;
        }

        if (stateChange) {
            currentCell->state = (currentCell->state + stateChange) % 2;
        }

        currentCell = currentCell->next;
    }
}

int main() {
    Cell* head = NULL;
    InitializeGame(&head);
    SimulateRound(&head);

    return 0;
}