//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns;
    printf("Welcome to the Matrix Operations Program!\n");
    printf("Enter the number of rows for your matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for your matrix: ");
    scanf("%d", &columns);
    int matrix[rows][columns];

    // Let's start by generating some random numbers for our matrix
    printf("Creating a matrix with surreal values...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 100; // some random numbers from 0 to 99
        }
    }

    // Displaying the matrix in style
    printf("Your surreal matrix is ready! Here it is:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(i % 2 == 0 && j % 2 == 0) { // even row and even column
                printf("❤️ %d ❤️\t", matrix[i][j]);
            } else if(i % 2 != 0 && j % 2 != 0) { // odd row and odd column
                printf("💙 %d 💙\t", matrix[i][j]);
            } else {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // Let's multiply each element in the matrix by its index
    printf("Now it's time for some magic! Multiplying matrix elements by their index...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] *= i*j;
        }
    }

    // Displaying the new matrix in a surreal way
    printf("Behold! Your matrix has been transformed...\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if(i % 2 == 0 && j % 2 == 0) { // even row and even column
                printf("🌈 %d 🌈\t", matrix[i][j]);
            } else if(i % 2 != 0 && j % 2 != 0) { // odd row and odd column
                printf("🦄 %d 🦄\t", matrix[i][j]);
            } else {
                printf("🔥 %d 🔥\t", matrix[i][j]);
            }
        }
        printf("\n");
    }

    // Time to find the sum of all elements in the matrix
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            sum += matrix[i][j];
        }
    }

    // Displaying the sum and saying goodbye
    printf("The sum of all the surreal values in your matrix is %d.\n", sum);
    printf("Thank you for using the surreal Matrix Operations Program! Have a surreal day!🌈\n");

    return 0;
}