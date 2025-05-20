//FormAI DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int board[ROWS][COLS])
{
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] >= 0)
                printf("| %d \t", board[i][j]);
            else
                printf("| %c \t", board[i][j]);
        }
        printf("|\n");
    }
}

void initializeBoard(int board[ROWS][COLS])
{
    int num = 1;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = num++;
        }
    }
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int x = rand()%4;
            int y = rand()%4;
            int temp = board[i][j];
            board[i][j] = board[x][y];
            board[x][y] = temp;
        }
    }
}

void playGame(int board[ROWS][COLS])
{
    printf("\nWelcome to the Memory game. The objective of the game is to correctly guess the values of the hidden squares.\n");
    printf("You will enter two coordinates each turn and if the values at those coordinates match, they will be opened and remain open.\n");
    printf("Your game is over once all pairs have been matched and the board is completely open.\n");

    int openBoard[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            openBoard[i][j] = -1;
        }
    }

    int numRevealed = 0;
    while(numRevealed <= 16) {
        printBoard(openBoard);
        int x1, y1, x2, y2;
        printf("Enter your guess (row, col) for square 1: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter your guess (row, col) for square 2: ");
        scanf("%d %d", &x2, &y2);

        if(board[x1][y1] != board[x2][y2]) {
            printf("No match...try again!\n");
        } else {
            openBoard[x1][y1] = board[x1][y1];
            openBoard[x2][y2] = board[x2][y2];
            numRevealed += 2;
        }
    }

    printf("Congratulations!! You have successfully opened all squares!!\n");
}

int main()
{
    int board[ROWS][COLS];
    initializeBoard(board);
    playGame(board);

    return 0;
}