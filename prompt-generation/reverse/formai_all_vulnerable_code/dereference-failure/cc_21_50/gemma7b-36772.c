//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **board = NULL;
    int rows, cols;

    // Allocate memory for the board
    board = (char **)malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * 5);
    }

    // Initialize the board
    rows = 5;
    cols = 5;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 'o';
        }
    }

    // Print the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    // Play the game
    int generation = 0;
    while (1)
    {
        // Calculate the next generation
        char **next_board = (char **)malloc(sizeof(char *) * rows);
        for (int i = 0; i < rows; i++)
        {
            next_board[i] = (char *)malloc(sizeof(char) * cols);
        }

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int num_alive = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 'o')
                        {
                            num_alive++;
                        }
                    }
                }

                if (num_alive < 2)
                {
                    next_board[r][c] = 'x';
                }
                else if (num_alive == 2)
                {
                    next_board[r][c] = 'o';
                }
                else if (num_alive > 2)
                {
                    next_board[r][c] = 'x';
                }
            }
        }

        // Free the old board
        for (int r = 0; r < rows; r++)
        {
            free(board[r]);
        }
        free(board);

        // Copy the next generation to the old board
        board = next_board;

        // Print the new generation
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation > 10)
        {
            break;
        }
    }

    // Free the memory
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}