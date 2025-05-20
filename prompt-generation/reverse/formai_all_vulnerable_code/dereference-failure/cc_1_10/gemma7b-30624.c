//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE ' '

void initializeBoard(char **board);
void displayBoard(char **board);
int makeMove(char **board, char player);
int checkWin(char **board, char player);

int main()
{
    char **board;
    char player;
    int move;
    int gameWon = 0;

    board = (char **)malloc(BOARD_SIZE * sizeof(char *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (char *)malloc(BOARD_SIZE * sizeof(char));
    }

    initializeBoard(board);

    player = PLAYER_X;
    move = 0;

    while (!gameWon && move < BOARD_SIZE * BOARD_SIZE)
    {
        displayBoard(board);

        move = makeMove(board, player);

        if (checkWin(board, player) == 1)
        {
            gameWon = 1;
        }

        player = (player == PLAYER_X) ? PLAYER_O : PLAYER_X;
        move++;
    }

    displayBoard(board);

    if (gameWon)
    {
        printf("Congratulations, %c, you won!\n", player);
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

void initializeBoard(char **board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = EMPTY_SPACE;
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

int makeMove(char **board, char player)
{
    int move = rand() % (BOARD_SIZE * BOARD_SIZE);

    while (board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY_SPACE)
    {
        move = rand() % (BOARD_SIZE * BOARD_SIZE);
    }

    board[move / BOARD_SIZE][move % BOARD_SIZE] = player;

    return move;
}

int checkWin(char **board, char player)
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