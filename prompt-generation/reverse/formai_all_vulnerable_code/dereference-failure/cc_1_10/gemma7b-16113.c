//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = NULL;
}

void insert(Cell** head, int state) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->state = state;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        (*head)->next = newCell;
    }
}

void printBoard(Cell* head) {
    while (head) {
        printf("%d ", head->state);
        head = head->next;
    }
    printf("\n");
}

void gameOfLife(Cell** head) {
    Cell* currentCell = *head;
    Cell* nextCell = NULL;

    while (currentCell) {
        int neighbors = 0;

        nextCell = currentCell->next;
        while (nextCell) {
            if (nextCell->state == 1) {
                neighbors++;
            }
            nextCell = nextCell->next;
        }

        if (currentCell->state == 0 && neighbors == 3) {
            insert(head, 1);
        } else if (currentCell->state == 1 && (neighbors < 2 || neighbors > 3)) {
            insert(head, 0);
        }
        currentCell = currentCell->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    insert(head, 1);
    insert(head, 0);
    insert(head, 1);
    insert(head, 0);

    gameOfLife(&head);

    printBoard(head);

    return 0;
}