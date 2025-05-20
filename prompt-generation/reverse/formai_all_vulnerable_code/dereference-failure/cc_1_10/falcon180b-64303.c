//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int rows, cols;
    int **matrix;
    int i, j, sum = 0;
    float avg;
    char input[10];

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix = (int **) malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }

    printf("Enter the number of elements to sum: ");
    scanf("%s", input);
    sum = atoi(input);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] > MIN_VALUE && matrix[i][j] < MAX_VALUE) {
                sum += matrix[i][j];
            }
        }
    }

    avg = (float) sum / (rows * cols);
    printf("The average value is: %.2f\n", avg);

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}