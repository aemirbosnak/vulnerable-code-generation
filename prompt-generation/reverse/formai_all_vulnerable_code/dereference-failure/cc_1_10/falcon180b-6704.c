//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l;
    int **matrix;
    int rows, cols;
    int sum = 0;
    int max = 0;
    int min = 1000000;
    int avg;
    double start_time, end_time;
    char input[10];

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    srand(time(0));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    printf("\nMatrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &k);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] == k) {
                printf("\nElement found at position (%d, %d)\n", i, j);
                break;
            }
        }
    }

    free(matrix[0]);
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}