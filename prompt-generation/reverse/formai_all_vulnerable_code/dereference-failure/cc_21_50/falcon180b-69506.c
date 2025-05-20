//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    int **matrix1, **matrix2, **result;
    int i, j, k;
    int choice;
    int sum = 0;
    int count = 0;

    srand(time(NULL));
    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    matrix2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    result = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Choose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    for (k = 0; k < cols; k++) {
                        sum += matrix1[i][k] * matrix2[k][j];
                    }
                    result[i][j] = sum;
                    sum = 0;
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

    printf("Result:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (i = 0; i < rows; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    for (i = 0; i < rows; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}