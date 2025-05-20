//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdlib.h>
#include <stdio.h>

#define ROWS 10
#define COLS 10

void draw_board(int **board)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        board[r] = malloc(COLS * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            board[r][c] = 0;
        }
    }

    // Set some initial cells to 'O'
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        int **next_board = malloc(ROWS * sizeof(int *));
        for (int r = 0; r < ROWS; r++)
        {
            next_board[r] = malloc(COLS * sizeof(int));
        }

        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[r][c] = (neighbors == 3) ? 1 : 0;
            }
        }

        // Free the previous board
        for (int r = 0; r < ROWS; r++)
        {
            free(board[r]);
        }
        free(board);

        // Update the board
        board = next_board;
        generation++;

        // Check if the game is over
        if (board[0][0] == 0)
        {
            draw_board(board);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}