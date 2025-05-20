//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

//Patterns
#define ROW(x)  (x / 9)
#define COL(y)  (y % 9)
#define BLOCK(x, y) (3 * ROW(x) + COL(x) / 3 + 27 * (ROW(y) / 3) + COL(y) / 3)

//Structures
typedef struct sudoku {int *cells;} sudoku;

//Functions
int possible(int n, int x, int *cells) {
    int i, j, row_start, col_start, block_start;
    row_start = ROW(x) * 9;
    col_start = COL(x);
    block_start = BLOCK(row_start, col_start);
    for (i = 0; i < 9; ++i)
        if (*(cells+row_start+i) == n)
            return 0;
    for (i = 0; i < 9; ++i)
        if (*(cells+9*i+col_start) == n)
            return 0;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            if (*(cells+(block_start + (i*9)+j)) == n)
                return 0;
    return 1;
}

sudoku *init_sudoku(int *cells) {
    sudoku *s = (sudoku *)malloc(sizeof(sudoku));
    s->cells = cells;
    return s;
}

void print_sudoku(sudoku *s) {
    int i, j;
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            printf("%d ", *(s->cells+i*9+j));
            if (j % 3 == 2)
                printf("| ");
        }
        putchar('\n');
        if (i % 3 == 2)
            printf("----------------------\n");
    }
}

int solve_sudoku(sudoku *s, int x) {
    int i;
    if (x == 81)
        return 1;

    if (*(s->cells+x) != 0) {
        if (solve_sudoku(s, x+1))
            return 1;
        else
            return 0;
    }

    for (i = 1; i <= 9; ++i) {
        if (possible(i, x, s->cells)) {
            *(s->cells+x) = i;
            if (solve_sudoku(s, x+1))
                return 1;
        }
    }
    *(s->cells+x) = 0;
    return 0;
}

int main() {
    int cells[] = {
        6,5,0,8,7,3,0,9,0,
        0,0,3,2,5,0,0,0,8,
        9,8,0,1,0,4,3,5,7,
        1,0,5,0,0,0,0,0,0,
        4,0,0,0,0,0,0,0,2,
        0,0,0,0,0,0,5,0,3,
        5,7,8,3,0,1,0,2,6,
        2,0,0,0,4,8,9,0,0,
        0,9,0,6,2,5,0,8,1
    };

    sudoku *s = init_sudoku(cells);

    puts("Sudoku before solving:\n");
    print_sudoku(s);

    solve_sudoku(s, 0);

    puts("\nSudoku after solving:\n");
    print_sudoku(s);

    free(s->cells);
    free(s);

    return 0;
}