//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void display_board(int **board)
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
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
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set some random cells to 1
    board[5][5] = 1;
    board[10][10] = 1;
    board[15][15] = 1;

    // Simulate Game of Life
    for (int t = 0; t < 20; t++)
    {
        display_board(board);

        // Calculate the number of neighbors for each cell
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                int num_neighbors = 0;
                if (i > 0) num_neighbors++;
                if (i < MAX_SIZE - 1) num_neighbors++;
                if (j > 0) num_neighbors++;
                if (j < MAX_SIZE - 1) num_neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 1 && num_neighbors < 2) board[i][j] = 0;
                else if (board[i][j] == 0 && num_neighbors == 3) board[i][j] = 1;
            }
        }
    }

    display_board(board);

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}