//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = NULL;
}

void addCell(Cell** head, int state) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->state = state;
    newCell->next = NULL;

    if (*head == NULL) {
        *head = newCell;
    } else {
        ((*head)->next = newCell)->next = *head;
        *head = newCell;
    }
}

void printCells(Cell* head) {
    while (head) {
        printf("%d ", head->state);
        head = head->next;
    }
    printf("\n");
}

void gameOfLife(Cell** head) {
    int alive = 0;
    Cell* currentCell = *head;

    // Calculate the number of alive cells for each cell
    for (currentCell = *head; currentCell; currentCell = currentCell->next) {
        alive = 0;
        Cell* neighbor = currentCell->next;

        // Check the neighbors of the current cell
        while (neighbor) {
            if (neighbor->state == 1) {
                alive++;
            }
            neighbor = neighbor->next;
        }

        // Update the state of the current cell
        if (alive < 2) {
            currentCell->state = 0;
        } else if (alive == 2) {
            currentCell->state = 1;
        }
    }

    // Print the updated cells
    printCells(*head);
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    // Add some cells
    addCell(&head, 1);
    addCell(&head, 1);
    addCell(&head, 0);
    addCell(&head, 1);
    addCell(&head, 0);

    // Play the game
    gameOfLife(&head);

    return 0;
}