//FormAI DATASET v1.0 Category: Data mining ; Style: portable
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m, i, j;
    printf("Enter the dimension of the matrix (n x m): ");
    scanf("%d%d", &n, &m);

    int **matrix = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){
        matrix[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the values:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int total_sum = 0, row_sum = 0, col_sum = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            total_sum += matrix[i][j];
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }
        printf("Sum of row %d: %d\n", i+1, row_sum);
        row_sum = 0;
    }

    for(i = 0; i < m; i++){
        printf("Sum of column %d: %d\n", i+1, col_sum);
        col_sum = 0;
    }

    printf("Total sum of all the elements: %d", total_sum);

    for(i = 0; i < n; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}