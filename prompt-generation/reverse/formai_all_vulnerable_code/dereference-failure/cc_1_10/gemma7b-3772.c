//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void play_bingo(int **board, int rows, int cols)
{
    int i, j, num, win = 0;
    char mark;

    // Generate random number between 1-9
    num = rand() % 9 + 1;

    // Mark the number on the board
    mark = 'X';
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = mark;
            }
        }
    }

    // Check if the player won
    for (i = 0; i < rows; i++)
    {
        // Check rows
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
        {
            win = 1;
        }

        // Check columns
        if (board[0][j] == mark && board[1][j] == mark && board[2][j] == mark)
        {
            win = 1;
        }
    }

    // If the player won, print the winning message
    if (win)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("Sorry, you lost.\n");
    }
}

int main()
{
    int rows, cols;
    int **board;

    // Get the number of rows and columns for the bingo board
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create the bingo board
    board = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int*)malloc(cols * sizeof(int));
    }

    // Play bingo
    play_bingo(board, rows, cols);

    return 0;
}