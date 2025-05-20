//FormAI DATASET v1.0 Category: Memory Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int board[ROWS][COLS]);
void swap(int *x, int *y);
void shuffle(int board[ROWS][COLS]);
void playGame(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS];
    srand(time(NULL));
    shuffle(board);
    playGame(board);
    return 0;
}

void printBoard(int board[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shuffle(int board[ROWS][COLS])
{
    int count = 1;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            board[i][j] = count;
            count++;
        }
    }
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            swap(&board[i][j], &board[randRow][randCol]);
        }
    }
}

void playGame(int board[ROWS][COLS])
{
    int moves = 0;
    int row1, row2, col1, col2;
    while(1)
    {
        printf("\nMoves: %d\n",moves);
        printBoard(board);
        printf("Enter position of first card (row column): ");
        scanf("%d %d",&row1, &col1);

        printf("Enter position of second card (row column): ");
        scanf("%d %d",&row2, &col2);

        if(board[row1][col1] == board[row2][col2])
        {
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            printf("Cards matched!\n");
        }
        else
        {
            printf("Cards did not match!\n");
        }

        moves++;

        int gameOver = 1;
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(board[i][j] != 0)
                {
                    gameOver = 0;
                    break;
                }
            }
            if(gameOver == 0) break;
        }

        if(gameOver)
        {
            printf("\nCongratulations! You have completed the game in %d moves.\n",moves);
            break;
        }
    }
}