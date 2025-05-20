//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include <stdio.h>
#define ROWS 10
#define COLS 10

void print_spiral(int matrix[ROWS][COLS], int row_start, int col_start, int rows_left, int cols_left);

int main() {
    int matrix[ROWS][COLS];
    int row, col;

    // Initialize the 2D array with some values for better visualization
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            matrix[row][col] = row * COLS + col + 1;
        }
    }

    printf("Original Matrix:\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%2d ", matrix[row][col]);
        }
        printf("\n");
    }

    printf("\nPrinting Spiral Pattern:\n");
    print_spiral(matrix, 0, 0, ROWS - 1, COLS - 1);

    return 0;
}

void print_spiral(int matrix[ROWS][COLS], int row_start, int col_start, int rows_left, int cols_left) {
    if (rows_left <= 0 || cols_left <= 0) {
        return;
    }

    // Print the first row
    int i;
    for (i = col_start; i <= col_start + cols_left - 1; i++) {
        printf("%d ", matrix[row_start][i]);
    }
    printf("\n");

    // Print the last columns of the remaining rows
    for (row_start++; row_start <= ROWS - 1; row_start++) {
        for (i = col_start + cols_left; i < COLS; i++) {
            printf("%d ", matrix[row_start][i]);
        }
        printf("\n");
    }

    // Print the remaining columns of the last row, except the first one
    if (cols_left > 1) {
        for (i = col_start + cols_left - 1; i >= col_start + 1; i--) {
            printf("%d ", matrix[ROWS - 1][i]);
        }
        printf("\n");
    }

    // Print the remaining rows, except the last one
    if (rows_left > 1) {
        col_start++;
        print_spiral(matrix, row_start, col_start, rows_left - 1, cols_left);
    }
}