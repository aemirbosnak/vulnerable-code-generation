//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define SUDO_SIZE 9

typedef struct Sudoku_cell {
    int number;
    struct Sudoku_cell** children;
} Sudoku_cell;

Sudoku_cell* sudoku_create(int number) {
    Sudoku_cell* cell = malloc(sizeof(Sudoku_cell));
    cell->number = number;
    cell->children = NULL;
    return cell;
}

void sudoku_solve(Sudoku_cell* cell) {
    if (cell->children == NULL) {
        if (cell->number == 0) {
            for (int i = 1; i <= SUDO_SIZE; i++) {
                cell->number = i;
                sudoku_solve(cell);
                cell->number = 0;
            }
        } else {
            printf("Solution:\n");
            for (int i = 0; i < SUDO_SIZE; i++) {
                printf("%d ", cell->children[i]->number);
            }
            printf("\n");
        }
    } else {
        for (int i = 0; i < SUDO_SIZE; i++) {
            sudoku_solve(cell->children[i]);
        }
    }
}

int main() {
    Sudoku_cell* root = sudoku_create(0);
    root->children = malloc(SUDO_SIZE * sizeof(Sudoku_cell*));
    for (int i = 0; i < SUDO_SIZE; i++) {
        root->children[i] = sudoku_create(0);
    }

    sudoku_solve(root);

    return 0;
}