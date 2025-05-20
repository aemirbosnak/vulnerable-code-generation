//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5

// Function to initialize the matrix
void initializeMatrix(int **matrix, int rows, int cols)
{
    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// Function to play the game
void playGame(int **matrix, int rows, int cols)
{
    // Randomly choose a row and column
    srand(time(NULL));
    int row = rand() % rows;
    int col = rand() % cols;

    // Place the bomb
    matrix[row][col] = 1;

    // Print the matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int **matrix;
    initializeMatrix(matrix, MAX_ROWS, MAX_COLS);
    playGame(matrix, MAX_ROWS, MAX_COLS);

    return 0;
}