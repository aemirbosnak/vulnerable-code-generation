//FormAI DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 4

int matrix[ROWS][COLS] = {{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}};

void print_matrix(int matrix[][COLS], int rows, int cols);
void multiply_row(int matrix[][COLS], int row, int factor);
void add_rows(int matrix[][COLS], int row1, int row2);

int main(){
    printf("Original Matrix:\n");
    print_matrix(matrix, ROWS, COLS);
    
    printf("\nMultiplying row 1 by 5:\n");
    multiply_row(matrix, 1, 5);
    print_matrix(matrix, ROWS, COLS);
    
    printf("\nAdding row 2 to row 4:\n");
    add_rows(matrix, 2, 4);
    print_matrix(matrix, ROWS, COLS);
    
    return 0;
}

void print_matrix(int matrix[][COLS], int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply_row(int matrix[][COLS], int row, int factor){
    for(int i=0; i<COLS; i++){
        matrix[row][i] *= factor;
    }
}

void add_rows(int matrix[][COLS], int row1, int row2){
    for(int i=0; i<COLS; i++){
        matrix[row1][i] += matrix[row2][i];
    }
}