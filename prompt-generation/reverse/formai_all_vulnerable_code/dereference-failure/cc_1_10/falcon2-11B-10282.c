//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int (*matrix)[9], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void init_matrix(int (*matrix)[9], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }
}

int is_valid(int (*matrix)[9], int i, int j, int n, int m, int value) {
    int k;

    for (k = 0; k < n; k++) {
        if (matrix[i][k] == value)
            return 0;

        if (matrix[k][j] == value)
            return 0;

        if (matrix[i / 3 * 3 + k / 3][j / 3 * 3 + k / 3] == value)
            return 0;
    }

    return 1;
}

int solve_sudoku(int (*matrix)[9], int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                for (int value = 1; value <= 9; value++) {
                    if (is_valid(matrix, i, j, n, m, value)) {
                        matrix[i][j] = value;

                        if (solve_sudoku(matrix, n, m))
                            return 1;

                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int n, m, i, j, value;
    int (*matrix)[9] = (int (*)[9])malloc(sizeof(int[9]) * n);

    if (argc!= 2) {
        printf("Usage: %s n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    m = n * 9 / 3;

    init_matrix(matrix, n, m);

    printf("Sudoku puzzle:\n");
    print_matrix(matrix, n, m);

    solve_sudoku(matrix, n, m);

    printf("\nSolution:\n");
    print_matrix(matrix, n, m);

    free(matrix);
    return 0;
}