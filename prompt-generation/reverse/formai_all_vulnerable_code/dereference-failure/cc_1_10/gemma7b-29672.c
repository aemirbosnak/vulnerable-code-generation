//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

void initializeBoard(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char **board, int row, int col)
{
    if (board[row][col] != ' ')
    {
        return 0;
    }

    return 1;
}

int isWon(char **board, char player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }

    // If all moves are made and there is no winner, it's a draw
    return 0;
}

int main()
{
    char **board = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
    }

    initializeBoard(board);

    char player = PLAYER_X;
    int move = 0;

    // Game loop
    while (!isWon(board, player) && move < 9)
    {
        int row, col;

        // Get the player's move
        printf("Enter row (1-3): ");
        scanf("%d", &row);

        printf("Enter column (1-3): ");
        scanf("%d", &col);

        // Validate the move
        if (!isValidMove(board, row, col))
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[row][col] = player;

        // Print the board
        printBoard(board);

        // Switch to the next player
        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;

        // Increment the move counter
        move++;
    }

    // Check if there is a winner or a draw
    if (isWon(board, player))
    {
        printf("Winner: %c!\n", player);
    }
    else
    {
        printf("It's a draw.\n");
    }

    // Free the memory
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}