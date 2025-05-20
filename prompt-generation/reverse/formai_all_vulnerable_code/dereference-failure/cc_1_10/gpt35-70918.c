//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ephemeral
#include <stdio.h>

int main() {
    /* This program demonstrates the unique syntax of C */
    int x = 10; 
    int y = 5;

    /* Swapping values using bitwise XOR operator */
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("x after swapping: %d\n", x);
    printf("y after swapping: %d\n", y);

    /* Looping through an array using pointers */
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = &arr[0];

    for(int i = 0; i < 5; i++) {
        printf("%d ", *ptr++);
    }

    /* Printing ASCII values using the %c format specifier */
    printf("\nASCII Values: ");
    for(int i = 65; i <= 90; i++) {
        printf("%c ", i);
    }

    /* Creating a 2D array using pointers */
    int rows = 3;
    int cols = 3;
    int **arr2d = (int **)malloc(rows * sizeof(int *));
    for(int i = 0; i < rows; i++){
        arr2d[i] = (int *)malloc(cols * sizeof(int));
    }

    /* Assigning values to the 2D array */
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            arr2d[i][j] = i + j;
        }
    }

    /* Printing the 2D array */
    printf("\n2D Array:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    return 0;
}