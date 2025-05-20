//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPOT '-'

void initializeBoard(char **board);
void displayBoard(char **board);
char makeMove(char **board, char player);
int isWinner(char **board, char player);
int isBoardFull(char **board);

int main()
{
    char **board;
    char player;
    int gameWon = 0;
    int gameFull = 0;

    board = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_SPOT;
        }
    }

    initializeBoard(board);

    player = PLAYER_X;
    while (!gameWon && !gameFull)
    {
        makeMove(board, player);
        displayBoard(board);
        if (isWinner(board, player) || isBoardFull(board))
        {
            gameWon = 1;
            break;
        }

        player = PLAYER_O;
    }

    displayBoard(board);

    if (gameWon)
    {
        printf("Congratulations, %c won!", player);
    }
    else if (gameFull)
    {
        printf("It's a draw!");
    }

    free(board);

    return 0;
}

void initializeBoard(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_SPOT;
        }
    }
}

void displayBoard(char **board)
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

char makeMove(char **board, char player)
{
    int moveX;
    int moveY;

    printf("Enter your move (x, y): ");
    scanf("%d %d", &moveX, &moveY);

    if (board[moveX][moveY] != EMPTY_SPOT)
    {
        printf("Invalid move. Please try again.\n");
        return EMPTY_SPOT;
    }

    board[moveX][moveY] = player;

    return player;
}

int isWinner(char **board, char player)
{
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return 1;
    }

    return 0;
}

int isBoardFull(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY_SPOT)
            {
                return 0;
            }
        }
    }

    return 1;
}