//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 100

typedef struct Cell {
    int x, y;
    struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_CELLS; i++) {
        Cell* newCell = malloc(sizeof(Cell));
        newCell->x = i;
        newCell->y = -1;
        newCell->next = *head;
        *head = newCell;
    }
}

void printBoard(Cell* head) {
    for (int i = 0; head; i++) {
        printf("%c ", head->x + 1);
        head = head->next;
    }
    printf("\n");
}

void updateBoard(Cell* head) {
    for (int i = 0; head; i++) {
        int neighbors = 0;
        Cell* current = head;
        while (current) {
            if (current->x - 1 == head->x && current->y == head->y) {
                neighbors++;
            }
            current = current->next;
        }
        if (neighbors < 2 || neighbors > 3) {
            head->y = 1;
        } else {
            head->y = 0;
        }
        head = head->next;
    }
}

int main() {
    Cell* head = NULL;
    initializeGame(&head);
    printBoard(head);
    updateBoard(head);
    printBoard(head);
    return 0;
}