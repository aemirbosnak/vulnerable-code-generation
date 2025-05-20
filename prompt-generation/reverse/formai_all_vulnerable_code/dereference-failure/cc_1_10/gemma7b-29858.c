//Gemma-7B DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_OF_PLAYER 4
#define BOARD_SIZE 7

typedef struct GameBoard
{
    int **board;
    int currentPlayer;
    int gameState;
} GameBoard;

void initializeGameBoard(GameBoard *board);
void placePiece(GameBoard *board, int x, int y);
int checkIfWon(GameBoard *board, int player);
int checkIfBoardFull(GameBoard *board);

int main()
{
    GameBoard *board = malloc(sizeof(GameBoard));
    initializeGameBoard(board);

    // Game loop
    while (!board->gameState)
    {
        // Get the player's move
        int moveX, moveY;
        printf("Enter move (x, y): ");
        scanf("%d %d", &moveX, &moveY);

        // Place the piece
        placePiece(board, moveX, moveY);

        // Check if the player won or if the board is full
        if (checkIfWon(board, board->currentPlayer) || checkIfBoardFull(board))
        {
            board->gameState = 1;
        }
    }

    // Game over
    printf("Game over! The winner is: %d\n", board->currentPlayer);

    free(board);
    return 0;
}

void initializeGameBoard(GameBoard *board)
{
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board->board[i][j] = 0;
        }
    }

    board->currentPlayer = 1;
    board->gameState = 0;
}

void placePiece(GameBoard *board, int x, int y)
{
    if (board->board[x][y] != 0)
    {
        return;
    }

    board->board[x][y] = board->currentPlayer;
}

int checkIfWon(GameBoard *board, int player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player)
    {
        return 1;
    }
    if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int checkIfBoardFull(GameBoard *board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board->board[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}