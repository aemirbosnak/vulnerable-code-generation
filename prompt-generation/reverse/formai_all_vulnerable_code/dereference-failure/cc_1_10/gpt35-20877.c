//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define PLAYER1 1
#define PLAYER2 2

void displayBoard(char board[][3]);
void initializeBoard(char board[][3]);
int boardFull(char board[][3]);
int checkWin(char board[][3], int player);
void makeMove(char board[][3], int player);
int getRandMove(char board[][3]);

int main()
{
    char board[3][3];
    int currentPlayer = PLAYER1;

    initializeBoard(board);
    displayBoard(board);

    while (1)
    {
        makeMove(board, currentPlayer);
        displayBoard(board);

        if (checkWin(board, currentPlayer))
        {
            printf("Player %d wins!", currentPlayer);
            break;
        }
        else if (boardFull(board))
        {
            printf("It is a tie!");
            break;
        }

        currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
    }

    return 0;
}

void displayBoard(char board[][3])
{
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n");
    printf("---+---+---");
    printf("\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n");
    printf("---+---+---");
    printf("\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

void initializeBoard(char board[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int boardFull(char board[][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return 1;
}

int checkWin(char board[][3], int player)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == (player == PLAYER1 ? 'X' : 'O'))
        {
            return 1;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == (player == PLAYER1 ? 'X' : 'O'))
        {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == (player == PLAYER1 ? 'X' : 'O'))
    {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == (player == PLAYER1 ? 'X' : 'O'))
    {
        return 1;
    }

    return 0;
}

void makeMove(char board[][3], int player)
{
    int row, col;

    if (player == PLAYER1)
    {
        printf("Player 1's turn (X): ");
        scanf("%d %d", &row, &col);

        if (board[row][col] != ' ')
        {
            printf("Invalid move. Please try again.");
            makeMove(board, player);
            return;
        }

        board[row][col] = 'X';
    }
    else if (player == PLAYER2)
    {
        printf("Player 2's turn (O): ");
        srand(time(NULL));
        row = getRandMove(board);
        col = getRandMove(board);

        if (board[row][col] != ' ')
        {
            makeMove(board, player);
            return;
        }

        board[row][col] = 'O';
    }
}

int getRandMove(char board[][3])
{
    return rand() % 3;
}