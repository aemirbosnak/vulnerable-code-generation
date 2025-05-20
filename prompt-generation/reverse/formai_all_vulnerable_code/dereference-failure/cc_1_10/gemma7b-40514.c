//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void displayBoard(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void calculateNextState(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            int neighbors = 0;
            // Check the number of neighbors
            if (board[r - 1][c] == 1) neighbors++;
            if (board[r + 1][c] == 1) neighbors++;
            if (board[r][c - 1] == 1) neighbors++;
            if (board[r][c + 1] == 1) neighbors++;

            // Apply the Game of Life rules
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3)) board[r][c] = 0;
        }
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some initial cells to 1
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;

    // Display the initial board
    displayBoard(board);

    // Calculate the next state of the board
    calculateNextState(board);

    // Display the next state of the board
    displayBoard(board);

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}