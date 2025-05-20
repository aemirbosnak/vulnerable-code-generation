//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;

    // Allocate memory for the board
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Play the game
    int game_over = 0;
    while (!game_over)
    {
        // Get the player's move
        int row, col;
        printf("Enter the row: ");
        scanf("%d", &row);

        printf("Enter the column: ");
        scanf("%d", &col);

        // Check if the move is valid
        if (board[row][col] == 1)
        {
            printf("That move is not valid.\n");
        }
        else
        {
            // Mark the move
            board[row][col] = 1;

            // Check if the player has won
            game_over = check_win(board, rows, cols);
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

int check_win(int **board, int rows, int cols)
{
    // Check for a win in a row
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols - 1; c++)
        {
            if (board[r][c] == board[r][c + 1] && board[r][c] == 1)
            {
                return 1;
            }
        }
    }

    // Check for a win in a column
    for (int c = 0; c < cols; c++)
    {
        for (int r = 0; r < rows - 1; r++)
        {
            if (board[r][c] == board[r + 1][c] && board[r][c] == 1)
            {
                return 1;
            }
        }
    }

    // Check for a win in a diagonal
    for (int d = 0; d < rows - 1; d++)
    {
        for (int c = 0; c < cols - 1; c++)
        {
            if (board[d][c] == board[d + 1][c + 1] && board[d][c] == 1)
            {
                return 1;
            }
        }
    }

    // If there has not been a win, return 0
    return 0;
}