//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 0, cols = 0;
    char command;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        board[r] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the game board
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    while (1)
    {
        // Get the user's command
        printf("Enter a command (s/c/r/q): ");
        scanf("%c", &command);

        // Check if the user wants to surrender
        if (command == 'q')
        {
            printf("Thank you for playing! Goodbye.\n");
            break;
        }

        // Check if the user wants to create a cell
        else if (command == 'c')
        {
            int row, col;

            printf("Enter the row number: ");
            scanf("%d", &row);

            printf("Enter the column number: ");
            scanf("%d", &col);

            board[row][col] = 1;
        }

        // Check if the user wants to reproduce a cell
        else if (command == 'r')
        {
            int row, col;

            printf("Enter the row number: ");
            scanf("%d", &row);

            printf("Enter the column number: ");
            scanf("%d", &col);

            if (board[row][col] == 1)
            {
                board[row][col] = 2;
            }
        }
    }

    // Free the memory allocated for the game board
    for (int r = 0; r < rows; r++)
    {
        free(board[r]);
    }

    free(board);

    return 0;
}