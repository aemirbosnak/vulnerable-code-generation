//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include <stdio.h>

int main() {
    int rows, cols, i, j;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols], transpose[cols][rows];
    
    printf("Enter the matrix elements:\n");
    
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nThe original matrix is:\n");
    
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Transpose of the matrix
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    printf("\nThe transpose of the matrix is:\n");
    
    for (i=0; i<cols; i++) {
        for (j=0; j<rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    // Sum of the diagonal elements
    int sum = 0;
    
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }
    
    printf("\nThe sum of diagonal elements is: %d\n", sum);
    
    // Product of the non-diagonal elements
    int product = 1;
    
    for (i=0; i<rows; i++) {
        for (j=0; j<cols; j++) {
            if (i != j) {
                product *= matrix[i][j];
            }
        }
    }
    
    printf("\nThe product of non-diagonal elements is: %d\n", product);
    
    return 0;
}