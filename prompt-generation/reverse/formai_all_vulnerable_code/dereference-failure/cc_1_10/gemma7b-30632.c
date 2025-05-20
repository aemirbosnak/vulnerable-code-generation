//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_board(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Place some knights
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;

    // Play the game
    int generation = 0;
    while (!board[MAX_SIZE - 1][MAX_SIZE - 1])
    {
        draw_board(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int alive_neighbors = 0;
                if (board[r - 1][c] == 1) alive_neighbors++;
                if (board[r + 1][c] == 1) alive_neighbors++;
                if (board[r][c - 1] == 1) alive_neighbors++;
                if (board[r][c + 1] == 1) alive_neighbors++;

                if (board[r][c] == 1 && alive_neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && alive_neighbors == 3) board[r][c] = 1;
            }
        }

        generation++;
    }

    draw_board(board);
    printf("Game Over! Generation: %d\n", generation);

    // Free the memory
    for (int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}