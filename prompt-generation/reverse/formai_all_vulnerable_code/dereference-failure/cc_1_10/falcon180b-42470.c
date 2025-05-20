//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int main(void) {
    int rows, cols, max_iterations;
    char **matrix;
    int i, j, k, l, iterations;
    time_t start, end;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;
    max_iterations = rand() % 1000 + 1;

    matrix = (char **) malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (char *) malloc(cols * sizeof(char));
    }

    start = time(NULL);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            iterations = rand() % max_iterations;
            for (k = 0; k < iterations; k++) {
                if (k == 0) {
                    matrix[i][j] = '*';
                } else {
                    matrix[i][j] = '.';
                }
            }
        }
    }
    end = time(NULL);

    printf("Generated a %dx%d matrix with %d iterations in %ld seconds.\n", rows, cols, max_iterations, end - start);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}