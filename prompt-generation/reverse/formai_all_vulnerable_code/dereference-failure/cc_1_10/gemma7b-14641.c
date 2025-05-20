//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board
{
    int **cells;
    int currentPlayer;
} Board;

Board *createBoard()
{
    Board *board = malloc(sizeof(Board));
    board->cells = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->cells[i] = malloc(BOARD_SIZE * sizeof(int));
    }
    board->currentPlayer = 1;
    return board;
}

void printBoard(Board *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board->cells[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(Board *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board->cells[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(Board *board)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->cells[0][i] == board->cells[1][i] && board->cells[0][i] == board->cells[2][i] && board->cells[0][i] != 0)
        {
            return board->cells[0][i];
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->cells[j][0] == board->cells[j][1] && board->cells[j][0] == board->cells[j][2] && board->cells[j][0] != 0)
        {
            return board->cells[j][0];
        }
    }

    // Check diagonals
    if (board->cells[0][0] == board->cells[1][1] && board->cells[0][0] == board->cells[2][2] && board->cells[0][0] != 0)
    {
        return board->cells[0][0];
    }

    // No winner
    return 0;
}

int main()
{
    Board *board = createBoard();

    // Play the game
    while (!isBoardFull(board) && checkWin(board) == 0)
    {
        // Get the player's move
        int moveX, moveY;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Place the mark
        board->cells[moveX][moveY] = board->currentPlayer;

        // Print the board
        printBoard(board);
    }

    // Print the winner or draw
    if (checkWin(board) != 0)
    {
        printf("Winner: Player %d\n", checkWin(board));
    }
    else
    {
        printf("Draw!\n");
    }

    return 0;
}