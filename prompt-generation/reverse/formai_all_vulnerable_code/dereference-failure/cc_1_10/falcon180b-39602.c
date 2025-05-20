//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 100

int main(void) {
    int rows, cols;
    char **matrix;
    int *fibonacci;
    int i, j, k;
    int num_fibonacci = 0;
    time_t start_time, end_time;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix = malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(char));
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 2? '.' : '#';
        }
    }

    printf("Random Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    fibonacci = malloc(2 * sizeof(int));
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    start_time = time(NULL);
    for (i = 2; i < rows * cols; i++) {
        fibonacci = realloc(fibonacci, (num_fibonacci + 1) * sizeof(int));
        fibonacci[num_fibonacci] = fibonacci[num_fibonacci - 1] + fibonacci[num_fibonacci - 2];
        num_fibonacci++;
    }
    end_time = time(NULL);

    printf("\nFibonacci Sequence:\n");
    for (k = 0; k < num_fibonacci; k++) {
        printf("%d ", fibonacci[k]);
    }
    printf("\n");

    printf("Time taken to generate Fibonacci sequence: %.6fs\n", difftime(end_time, start_time));

    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(fibonacci);

    return 0;
}