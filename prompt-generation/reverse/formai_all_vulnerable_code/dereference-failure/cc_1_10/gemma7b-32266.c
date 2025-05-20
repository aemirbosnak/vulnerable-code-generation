//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 20

// Macro to generate a random number between 0 and 9
#define RAND() rand() % 10

// Function to simulate a percolating cluster
void percolate(int **board, int x, int y)
{
    // If the cell is not occupied or it has already been percolated, return
    if (board[x][y] != 0 || board[x][y] == 2)
        return;

    // Mark the cell as percolated
    board[x][y] = 2;

    // Simulate percolating the neighboring cells
    if (x > 0)
        percolate(board, x - 1, y);
    if (x < BOARD_SIZE - 1)
        percolate(board, x + 1, y);
    if (y > 0)
        percolate(board, x, y - 1);
    if (y < BOARD_SIZE - 1)
        percolate(board, x, y + 1);
}

int main()
{
    // Allocate memory for the board
    int **board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = 0;
    }

    // Simulate the percolating cluster
    percolate(board, 5, 5);

    // Print the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++)
        free(board[i]);
    free(board);

    return 0;
}