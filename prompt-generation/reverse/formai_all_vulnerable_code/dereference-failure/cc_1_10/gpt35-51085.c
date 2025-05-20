//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to print the game board
void printBoard(char board[][3])
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if the game is over
int checkWin(char board[][3], char p)
{
    int i, j;
    // Check rows
    for(i = 0; i < 3; i++)
        if(board[i][0] == p && board[i][1] == p && board[i][2] == p)
            return 1;
    // Check columns
    for(i = 0; i < 3; i++)
        if(board[0][i] == p && board[1][i] == p && board[2][i] == p)
            return 1;
    // Check diagonals
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p)
        return 1;
    if(board[2][0] == p && board[1][1] == p && board[0][2] == p)
        return 1;
    return 0; // No winner yet
}

// Function to make a move
void makeMove(char board[][3], char p)
{
    int row, col;
    printf("Player %c, enter your move (row column): ", p);
    scanf("%d %d", &row, &col);
    while(board[row-1][col-1] != ' ')
    {
        printf("Invalid move! Try again.\n");
        printf("Player %c, enter your move (row column): ", p);
        scanf("%d %d", &row, &col);
    }
    board[row-1][col-1] = p;
}

int main()
{
    char board[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    int i;
    for(i = 0; i < 9; i++)
    {
        printBoard(board);
        makeMove(board, player);
        if(checkWin(board, player))
        {
            printf("Player %c wins!\n", player);
            return 0;
        }
        if(player == 'X')
            player = 'O';
        else
            player = 'X';
    }
    printf("The game is a tie!\n");
    return 0;
}