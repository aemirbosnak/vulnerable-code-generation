//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define LEN 50
#define LEN_DIM 100

int main() {
    int i, j, k, l, m;
    int **matrix;
    int visited[LEN_DIM][LEN_DIM];

    matrix = (int **)malloc(LEN_DIM * sizeof(int *));
    for (i = 0; i < LEN_DIM; i++) {
        matrix[i] = (int *)malloc(LEN_DIM * sizeof(int));
        for (j = 0; j < LEN_DIM; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            visited[i][j] = 0;
        }
    }

    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            if (matrix[i][j] == 0) {
                visited[i][j] = 1;
            }
        }
    }

    printf("Initial state:\n");
    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            if (visited[i][j] == 1 && matrix[i][j] == 1) {
                printf("Percolation found!\n");
                break;
            }
        }
        if (visited[i][j] == 1 && matrix[i][j] == 1) {
            break;
        }
    }

    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            if (visited[i][j] == 1) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    printf("Final state:\n");
    for (i = 0; i < LEN_DIM; i++) {
        for (j = 0; j < LEN_DIM; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}