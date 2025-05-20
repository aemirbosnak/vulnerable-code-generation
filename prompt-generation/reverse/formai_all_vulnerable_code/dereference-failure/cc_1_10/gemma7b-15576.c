//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
}

void update(Cell** head) {
    Cell* current = *head;
    Cell* next = NULL;

    while (current) {
        int neighbors = 0;
        next = current->next;

        while (next) {
            if (next->state == 1) {
                neighbors++;
            }
            next = next->next;
        }

        if (current->state == 1 && neighbors < 2) {
            current->state = 0;
        } else if (current->state == 0 && neighbors == 3) {
            current->state = 1;
        }
        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    head->state = 1;
    head->next->state = 1;
    head->next->next->state = 1;

    update(&head);

    if (head->state == 1) {
        printf("The game of life is ongoing.\n");
    } else {
        printf("The game of life is over.\n");
    }

    return 0;
}