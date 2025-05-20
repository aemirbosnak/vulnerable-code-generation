//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
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

void insert(Cell** head, int state) {
    Cell* newNode = malloc(sizeof(Cell));
    newNode->state = state;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void print_cells(Cell* head) {
    while (head) {
        printf("%d ", head->state);
        head = head->next;
    }
    printf("\n");
}

void game_of_life(Cell* head) {
    Cell* current = head;
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

        if (current->state == 0 && neighbors == 3) {
            insert(&head, 1);
        } else if (current->state == 1 && (neighbors < 2 || neighbors > 3)) {
            insert(&head, 0);
        }
        current = current->next;
    }
}

int main() {
    Cell* head = NULL;

    initialize(&head);
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 0);
    insert(&head, 0);
    insert(&head, 1);

    game_of_life(head);

    print_cells(head);

    return 0;
}