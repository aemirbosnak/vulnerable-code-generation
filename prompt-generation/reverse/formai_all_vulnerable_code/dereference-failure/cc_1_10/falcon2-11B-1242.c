//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct {
    int row;
    int col;
    int val;
} Cell;

typedef struct {
    Cell cells[MAX_SIZE * MAX_SIZE];
} Sudoku;

void print_sudoku(Sudoku* s) {
    int rows = MAX_SIZE;
    int cols = MAX_SIZE;
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d", s->cells[i * rows + j].val);
        }
        printf("\n");
    }
}

int check_validity(Sudoku* s, int row, int col) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        if (s->cells[row * MAX_SIZE + i].val == 0 && (row == i || s->cells[i * MAX_SIZE + col].val == 0))
            return 0;
    }

    for (j = 0; j < MAX_SIZE; j++) {
        if (s->cells[i * MAX_SIZE + j].val == 0 && (col == j || s->cells[row * MAX_SIZE + j].val == 0))
            return 0;
    }

    return 1;
}

int solve_sudoku(Sudoku* s) {
    int i, j;
    int row, col;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (s->cells[i * MAX_SIZE + j].val == 0) {
                row = i;
                col = j;
            }
        }
    }

    while (1) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (s->cells[row * MAX_SIZE + j].val == 0 && check_validity(s, row, j)) {
                s->cells[row * MAX_SIZE + j].val = j + 1;

                if (solve_sudoku(s))
                    return 1;

                s->cells[row * MAX_SIZE + j].val = 0;
            }
        }

        for (i = 0; i < MAX_SIZE; i++) {
            if (s->cells[i * MAX_SIZE + col].val == 0 && check_validity(s, i, col)) {
                s->cells[i * MAX_SIZE + col].val = i + 1;

                if (solve_sudoku(s))
                    return 1;

                s->cells[i * MAX_SIZE + col].val = 0;
            }
        }

        if (row == col) {
            row++;
            col = (row + 1) % MAX_SIZE;
        } else {
            col++;
            row = (col + 1) % MAX_SIZE;
        }
    }
}

int main() {
    Sudoku* s = (Sudoku*)malloc(sizeof(Sudoku));

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            s->cells[i * MAX_SIZE + j].row = i;
            s->cells[i * MAX_SIZE + j].col = j;
            s->cells[i * MAX_SIZE + j].val = 0;
        }
    }

    s->cells[0 * MAX_SIZE + 0].val = 5;
    s->cells[0 * MAX_SIZE + 1].val = 3;
    s->cells[0 * MAX_SIZE + 2].val = 4;
    s->cells[1 * MAX_SIZE + 0].val = 6;
    s->cells[1 * MAX_SIZE + 1].val = 7;
    s->cells[1 * MAX_SIZE + 2].val = 8;
    s->cells[2 * MAX_SIZE + 0].val = 9;
    s->cells[2 * MAX_SIZE + 1].val = 2;
    s->cells[2 * MAX_SIZE + 2].val = 1;
    s->cells[3 * MAX_SIZE + 0].val = 0;
    s->cells[3 * MAX_SIZE + 1].val = 0;
    s->cells[3 * MAX_SIZE + 2].val = 0;
    s->cells[4 * MAX_SIZE + 0].val = 0;
    s->cells[4 * MAX_SIZE + 1].val = 0;
    s->cells[4 * MAX_SIZE + 2].val = 0;
    s->cells[5 * MAX_SIZE + 0].val = 0;
    s->cells[5 * MAX_SIZE + 1].val = 0;
    s->cells[5 * MAX_SIZE + 2].val = 0;
    s->cells[6 * MAX_SIZE + 0].val = 0;
    s->cells[6 * MAX_SIZE + 1].val = 0;
    s->cells[6 * MAX_SIZE + 2].val = 0;
    s->cells[7 * MAX_SIZE + 0].val = 0;
    s->cells[7 * MAX_SIZE + 1].val = 0;
    s->cells[7 * MAX_SIZE + 2].val = 0;
    s->cells[8 * MAX_SIZE + 0].val = 0;
    s->cells[8 * MAX_SIZE + 1].val = 0;
    s->cells[8 * MAX_SIZE + 2].val = 0;

    print_sudoku(s);

    solve_sudoku(s);

    print_sudoku(s);

    return 0;
}