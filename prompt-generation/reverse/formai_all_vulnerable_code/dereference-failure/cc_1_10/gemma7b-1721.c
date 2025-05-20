//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initializeGame(Cell** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        *head = malloc(sizeof(Cell));
        (*head)->state = 0;
        (*head)->next = NULL;
        head = &((*head)->next);
    }
}

void playGame(Cell** head) {
    int generation = 0;
    while (head && (*head)->state) {
        Cell* iter = *head;
        for (int i = 0; iter; i++) {
            int neighbors = 0;
            Cell* neighbor = iter->next;
            for (int j = 0; neighbor; j++) {
                if (neighbor->state) {
                    neighbors++;
                }
                neighbor = neighbor->next;
            }
            switch (iter->state) {
                case 0:
                    if (neighbors == 3) {
                        iter->state = 1;
                    }
                    break;
                case 1:
                    if (neighbors < 2 || neighbors > 3) {
                        iter->state = 0;
                    }
                    break;
            }
        }
        generation++;
    }
    printf("Number of generations: %d\n", generation);
}

int main() {
    Cell* head = NULL;
    initializeGame(&head);
    playGame(&head);
    return 0;
}