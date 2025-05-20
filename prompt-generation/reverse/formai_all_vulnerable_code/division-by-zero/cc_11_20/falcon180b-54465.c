//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j, n;
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], result[SIZE][SIZE];
    char operation;

    // Fill matrices with random numbers
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Ask user for operation
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform matrix operation
    switch (operation) {
        case '+':
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case '-':
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case '*':
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    result[i][j] = matrix1[i][j] * matrix2[i][j];
                }
            }
            break;
        case '/':
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    result[i][j] = matrix1[i][j] / matrix2[i][j];
                }
            }
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    // Print results
    printf("\nResult:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}