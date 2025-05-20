//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int grid[9][9];
    int solved;
} Sudoku;

Sudoku* create_sudoku(char* filename) {
    Sudoku* sudoku = malloc(sizeof(Sudoku));
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = fgetc(file);
            if (c == '.') {
                sudoku->grid[i][j] = 0;
            } else {
                sudoku->grid[i][j] = c - '0';
            }
        }
        fgetc(file); // newline
    }
    fclose(file);
    sudoku->solved = 0;
    return sudoku;
}

void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku->grid[i][j] == 0) {
                printf(".");
            } else {
                printf("%d", sudoku->grid[i][j]);
            }
            if (j % 3 == 2) {
                printf(" ");
            }
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("\n");
        }
    }
}

int is_valid_move(Sudoku* sudoku, int row, int col, int value) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (sudoku->grid[row][i] == value) {
            return 0;
        }
    }
    // Check column
    for (int j = 0; j < 9; j++) {
        if (sudoku->grid[j][col] == value) {
            return 0;
        }
    }
    // Check box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku->grid[box_row + i][box_col + j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(Sudoku* sudoku) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudoku->grid[row][col] == 0) {
                for (int value = 1; value <= 9; value++) {
                    if (is_valid_move(sudoku, row, col, value)) {
                        sudoku->grid[row][col] = value;
                        if (solve_sudoku(sudoku)) {
                            return 1;
                        } else {
                            sudoku->grid[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    sudoku->solved = 1;
    return 1;
}

int main() {
    Sudoku* sudoku = create_sudoku("sudoku.txt");
    if (sudoku == NULL) {
        return 1;
    }
    print_sudoku(sudoku);
    if (solve_sudoku(sudoku)) {
        printf("Solved sudoku:\n");
        print_sudoku(sudoku);
    } else {
        printf("Could not solve sudoku.\n");
    }
    free(sudoku);
    return 0;
}