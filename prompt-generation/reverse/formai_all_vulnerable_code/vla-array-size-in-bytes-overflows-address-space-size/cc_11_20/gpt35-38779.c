//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int a[rows][cols], b[rows][cols], c[rows][cols];
    printf("\nEnter elements of matrix A:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of matrix B:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMatrix A:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", b[i][j]);      
        }
        printf("\n");
    }

    printf("\nAdding matrix A and B...\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResultant matrix C:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", c[i][j]);       
        }
        printf("\n");
    }

    printf("\nMultiplying matrix A and B...\n");
    int k, sum;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            sum=0;
            for(k=0; k<cols; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j]=sum;
        }
    }

    printf("\nResultant matrix C:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", c[i][j]);       
        }
        printf("\n");
    }

    printf("Wow, we just did simple matrix addition and multiplication!\n");

    return 0;
}