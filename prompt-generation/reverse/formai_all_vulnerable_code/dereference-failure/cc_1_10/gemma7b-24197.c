//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

typedef struct Cell {
    int alive;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = NULL;
}

void insert(Cell** head, int value) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->alive = value;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

void printCells(Cell* head) {
    while (head) {
        printf("%d ", head->alive);
        head = head->next;
    }
    printf("\n");
}

void iterate(Cell* head) {
    Cell* current = head;
    Cell* next = NULL;

    while (current) {
        next = current->next;
        int aliveNeighbors = 0;

        if (next) {
            while (next) {
                if (next->alive) {
                    aliveNeighbors++;
                }
                next = next->next;
            }
        }

        if (aliveNeighbors < 2) {
            current->alive = 0;
        } else if (aliveNeighbors > 3) {
            current->alive = 0;
        }

        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    insert(head, 1);
    insert(head, 0);
    insert(head, 1);
    insert(head, 0);
    insert(head, 1);

    printCells(head);

    iterate(head);

    printCells(head);

    return 0;
}