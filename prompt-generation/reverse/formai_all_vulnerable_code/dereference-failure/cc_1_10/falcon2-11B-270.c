//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define N 10

int matrix[N][N];

void print_matrix(int **matrix) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int calculate_next_generation(int **matrix) {
    int i, j, k;
    int count = 0;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            int neighbors = 0;

            if (i > 0) {
                neighbors += matrix[i-1][j];
            }
            if (i < N-1) {
                neighbors += matrix[i+1][j];
            }
            if (j > 0) {
                neighbors += matrix[i][j-1];
            }
            if (j < N-1) {
                neighbors += matrix[i][j+1];
            }

            if (matrix[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                count++;
                matrix[i][j] = 1;
            } else if (matrix[i][j] == 0 && neighbors == 3) {
                count++;
                matrix[i][j] = 1;
            }
        }
    }

    return count;
}

int create_matrix(int **matrix) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

int main() {
    int **matrix;

    matrix = create_matrix(&matrix);

    print_matrix(matrix);

    int next_generation = calculate_next_generation(&matrix);

    printf("Next generation: %d\n", next_generation);

    print_matrix(matrix);

    return 0;
}