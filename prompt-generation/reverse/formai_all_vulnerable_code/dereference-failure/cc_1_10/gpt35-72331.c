//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void display_board(int** mat, int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** create_board(int n) {
    int** mat = (int**) malloc(n*sizeof(int*));
    int i, j;
    for(i = 0; i < n; i++) {
        mat[i] = (int*) malloc(n*sizeof(int));
        for(j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

int is_valid(int** mat, int n, int row, int col) {
    // check row
    int i;
    for(i = 0; i < n; i++) {
        if(mat[row][i] == 1) {
            return 0;
        }
    }
    // check col
    for(i = 0; i < n; i++) {
        if(mat[i][col] == 1) {
            return 0;
        }
    }
    // check diagonal
    int j, k;
    for(j = row, k = col; j >= 0 && k >= 0; j--, k--) {
        if(mat[j][k] == 1) {
            return 0;
        }
    }
    for(j = row, k = col; j >= 0 && k < n; j--, k++) {
        if(mat[j][k] == 1) {
            return 0;
        }
    }
    return 1;
}

int solve_helper(int** mat, int n, int row) {
    // base case
    if(row == n) {
        return 1;
    }
    // recursive case
    int col;
    for(col = 0; col < n; col++) {
        // check for valid placement
        if(is_valid(mat, n, row, col) == 1) {
            // place queen
            mat[row][col] = 1;
            // try to place next queen
            if(solve_helper(mat, n, row+1) == 1) {
                return 1;
            }
            // remove queen if next placement fails
            mat[row][col] = 0;
        }
    }
    return 0;
}

int solve(int** mat, int n) {
    return solve_helper(mat, n, 0);
}

int main() {
    int n = 8;
    int** mat = create_board(n);
    if(solve(mat, n) == 1) {
        display_board(mat, n);
    }
    else {
        printf("Solution does not exist\n");
    }
    return 0;
}