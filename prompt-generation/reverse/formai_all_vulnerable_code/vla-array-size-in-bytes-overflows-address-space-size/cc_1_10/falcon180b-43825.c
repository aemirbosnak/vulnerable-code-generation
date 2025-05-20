//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

void generate_matrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    srand(time(NULL));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void print_matrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int new_mat[cols][rows];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            new_mat[j][i] = mat[i][j];
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            mat[i][j] = new_mat[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int mat[MAX_ROWS][MAX_COLS];
    generate_matrix(mat, rows, cols);

    printf("Original Matrix:\n");
    print_matrix(mat, rows, cols);

    transpose_matrix(mat, rows, cols);

    printf("\nTransposed Matrix:\n");
    print_matrix(mat, cols, rows);

    return 0;
}