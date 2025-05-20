//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int value;
    struct cell *next;
} cell;

void print_board(cell *head) {
    cell *current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int is_valid(cell *head, int row, int col, int value) {
    cell *current = head;
    while (current) {
        if (current->value == value && current->next && current->next->value == value) {
            return 0;
        }
        current = current->next;
    }
    int row_index = row * 9;
    int col_index = col * 9;
    for (int i = 0; i < 9; i++) {
        if (current->next && current->next->value == value && (i == row_index || i == col_index || (i % 3 == col_index % 3 && i / 3 == col_index / 3))) {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

void solve(cell *head) {
    cell *current = head;
    while (current) {
        int row = current->value / 9;
        int col = current->value % 9;
        if (current->next && current->next->value == 0) {
            current->next->value = current->value;
            solve(current->next->next);
            current->next->value = 0;
        }
        current = current->next;
    }
}

int main() {
    cell *head = NULL;
    cell *current = NULL;
    int row, col, value;
    while (1) {
        printf("Enter the row and column of the cell to solve, or -1 to exit: ");
        scanf("%d%d", &row, &col);
        if (row == -1 && col == -1) {
            break;
        }
        printf("Enter the value: ");
        scanf("%d", &value);
        cell *new_cell = (cell*)malloc(sizeof(cell));
        new_cell->value = value;
        new_cell->next = head;
        head = new_cell;
        current = head;
        while (current->next && current->next->value!= 0) {
            current = current->next;
        }
        if (current->next) {
            current->next->value = 0;
        }
        if (is_valid(head, row, col, value)) {
            solve(head);
        }
    }
    print_board(head);
    return 0;
}