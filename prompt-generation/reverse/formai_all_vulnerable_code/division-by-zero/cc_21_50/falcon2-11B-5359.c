//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ROWS 3
#define COLS 4

int main() {
    srand(time(NULL));  // seed random number generator
    int matrix[ROWS][COLS];  // declare matrix variable

    // generate random matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 10;  // generate random number between 0 and 9
        }
    }

    // print matrix
    printf("Random Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // add matrix
    int sum[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum[i][j] = matrix[i][j] + matrix[i][j];  // add matrix elements
        }
    }

    // print sum matrix
    printf("Sum Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // subtract matrix
    int diff[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            diff[i][j] = matrix[i][j] - matrix[i][j];  // subtract matrix elements
        }
    }

    // print difference matrix
    printf("Difference Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", diff[i][j]);
        }
        printf("\n");
    }

    // multiply matrix
    int product[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            product[i][j] = matrix[i][j] * matrix[i][j];  // multiply matrix elements
        }
    }

    // print product matrix
    printf("Product Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // divide matrix
    int quotient[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            quotient[i][j] = matrix[i][j] / matrix[i][j];  // divide matrix elements
        }
    }

    // print quotient matrix
    printf("Quotient Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", quotient[i][j]);
        }
        printf("\n");
    }

    return 0;
}