//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct board{
    int board[3][3];
    int player;
};

struct board* createBoard()
{
    struct board* board = (struct board*)malloc(sizeof(struct board));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board->board[i][j] = 0;
        }
    }
    board->player = 0;
    return board;
}

void printBoard(struct board* board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board->board[i][j] == 0)
            {
                printf("-");
            }
            else if(board->board[i][j] == 1)
            {
                printf("X");
            }
            else if(board->board[i][j] == 2)
            {
                printf("O");
            }
        }
        printf("\n");
    }
}

int checkWinner(struct board* board)
{
    int i,j;
    int horizontal[] = {0,0,0,0,0,0,0,0,0,0};
    int vertical[] = {0,0,0,0,0,0,0,0,0,0};
    int diagonal[] = {0,0,0,0,0,0,0,0,0,0};
    for(i=0;i<3;i++)
    {
        horizontal[i] = board->board[i][0] + board->board[i][1] + board->board[i][2];
        vertical[i] = board->board[0][i] + board->board[1][i] + board->board[2][i];
        diagonal[i] = board->board[0][0] + board->board[1][1] + board->board[2][2];
    }
    if(horizontal[0] == 3 || horizontal[1] == 3 || horizontal[2] == 3)
    {
        return 1;
    }
    if(vertical[0] == 3 || vertical[1] == 3 || vertical[2] == 3)
    {
        return 1;
    }
    if(diagonal[0] == 3 || diagonal[1] == 3)
    {
        return 1;
    }
    return 0;
}

int main()
{
    struct board* board = createBoard();
    int player = 0;
    char choice;
    printf("Welcome to Tic Tac Toe!\n");
    while(1)
    {
        printBoard(board);
        printf("Player %d's turn\n", board->player);
        scanf("%c",&choice);
        if(choice == 'X')
        {
            board->board[0][0] = 1;
            board->player = 1;
        }
        else if(choice == 'O')
        {
            board->board[0][0] = 2;
            board->player = 2;
        }
        else
        {
            printf("Invalid Input!\n");
            continue;
        }
        if(checkWinner(board) == 1)
        {
            printf("Player %d wins!\n", board->player);
            break;
        }
        else if(board->player == 2)
        {
            board = createBoard();
            board->player = 0;
            printf("Player %d wins!\n", board->player);
            break;
        }
    }
    return 0;
}