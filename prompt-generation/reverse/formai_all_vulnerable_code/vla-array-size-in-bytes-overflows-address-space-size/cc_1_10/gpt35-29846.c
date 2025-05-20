//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>

int main() {

    // Declare variables
    int rows, cols, i, j;

    // Get input from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare the 2D array
    int array[rows][cols];

    // Get input for the array elements
    printf("Enter the elements of the array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // Display the array elements
    printf("The elements of the array are:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Find the sum of each row and each column
    int rowSum, colSum;
    for (i = 0; i < rows; i++) {
        rowSum = 0;
        for (j = 0; j < cols; j++) {
            rowSum += array[i][j];
        }
        printf("The sum of row %d is %d.\n", i + 1, rowSum);
    }

    for (j = 0; j < cols; j++) {
        colSum = 0;
        for (i = 0; i < rows; i++) {
            colSum += array[i][j];
        }
        printf("The sum of column %d is %d.\n", j + 1, colSum);
    }

    return 0;
}