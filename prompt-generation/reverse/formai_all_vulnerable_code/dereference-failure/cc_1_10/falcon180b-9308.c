//Falcon-180B DATASET v1.0 Category: Educational ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUMBERS 100

int main() {
    int rows, cols, numbers;
    int **matrix;
    int *sorted_matrix;
    int i, j, k;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the number of numbers: ");
    scanf("%d", &numbers);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter %d numbers:\n", numbers);
    for (i = 0; i < numbers; i++) {
        scanf("%d", &matrix[i][0]);
    }

    sorted_matrix = (int *)malloc(numbers * sizeof(int));

    start = clock();
    for (i = 0; i < numbers; i++) {
        for (j = i + 1; j < numbers; j++) {
            if (matrix[i][0] > matrix[j][0]) {
                k = matrix[i][0];
                matrix[i][0] = matrix[j][0];
                matrix[j][0] = k;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted matrix:\n");
    for (i = 0; i < numbers; i++) {
        printf("%d ", matrix[i][0]);
    }
    printf("\n");

    printf("Time taken: %.2f seconds\n", cpu_time_used);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(sorted_matrix);

    return 0;
}