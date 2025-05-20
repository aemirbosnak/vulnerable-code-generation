//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
// A Turing Machine Simulator in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_MEMORY 100

typedef struct Cell {
    int state;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = malloc(sizeof(Cell));
    (*head)->state = 0;
    (*head)->next = NULL;
}

void write_tape(Cell* head, int value) {
    Cell* current = head;
    while (current->next) {
        current = current->next;
    }
    current->state = value;
}

int read_tape(Cell* head) {
    return head->state;
}

void transition(Cell* head, int input) {
    switch (head->state) {
        case 0:
            if (input == 0) {
                write_tape(head, 1);
                head->state = 1;
            } else if (input == 1) {
                write_tape(head, 0);
                head->state = 2;
            }
            break;
        case 1:
            if (input == 0) {
                write_tape(head, 0);
                head->state = 0;
            } else if (input == 1) {
                write_tape(head, 1);
                head->state = 2;
            }
            break;
        case 2:
            if (input == 0) {
                write_tape(head, 1);
                head->state = 1;
            } else if (input == 1) {
                write_tape(head, 0);
                head->state = 0;
            }
            break;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    write_tape(head, 0);
    write_tape(head, 1);
    write_tape(head, 0);

    transition(head, 0);
    transition(head, 1);
    transition(head, 0);

    printf("The final tape is:");
    Cell* current = head;
    while (current) {
        printf("%d ", read_tape(current));
        current = current->next;
    }

    return 0;
}