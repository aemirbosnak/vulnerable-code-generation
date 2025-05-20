//FormAI DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int rows, columns, i, j;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", &columns);
    
    int matrix1[rows][columns], matrix2[rows][columns], sum[rows][columns], prod[rows][columns], transpose[columns][rows];
    
    printf("\nEnter the elements of matrix 1:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter the elements of matrix 2:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Matrix Addition
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    // Matrix Multiplication
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            prod[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    
    // Matrix Transpose
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            transpose[j][i] = matrix1[i][j];
        }
    }
    
    // Display Matrix 1
    printf("\nMatrix 1:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    
    // Display Matrix 2
    printf("\nMatrix 2:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    
    // Display Matrix Sum
    printf("\nMatrix Sum:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    
    // Display Matrix Product
    printf("\nMatrix Product:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<columns; j++) {
            printf("%d ", prod[i][j]);
        }
        printf("\n");
    }
    
    // Display Transpose of Matrix 1
    printf("\nMatrix 1 Transpose:\n");
    for(i=0; i<columns; i++) {
        for(j=0; j<rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}