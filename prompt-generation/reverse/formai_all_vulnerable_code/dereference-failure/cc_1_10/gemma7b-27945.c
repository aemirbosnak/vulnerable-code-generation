//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void create_cell(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
}

void add_cell(Cell** head) {
    Cell* new_cell = malloc(sizeof(Cell));
    new_cell->state = 0;
    new_cell->next = NULL;

    if (*head) {
        (*head)->next = new_cell;
        *head = new_cell;
    } else {
        *head = new_cell;
    }
}

void print_cells(Cell* head) {
    while (head) {
        printf("%d ", head->state);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Cell* head = NULL;
    create_cell(&head);
    add_cell(&head);
    add_cell(&head);
    add_cell(&head);

    print_cells(head);

    head->state = 1;
    print_cells(head);

    return 0;
}