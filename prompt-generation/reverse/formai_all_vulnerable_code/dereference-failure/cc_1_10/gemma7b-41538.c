//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void drawBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }
}

void calculateNextState(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            int neighbours = 0;
            if(board[r-1][c] == 'o') neighbours++;
            if(board[r+1][c] == 'o') neighbours++;
            if(board[r][c-1] == 'o') neighbours++;
            if(board[r][c+1] == 'o') neighbours++;

            if(board[r][c] == 'o' && neighbours < 2) board[r][c] = 'x';
            else if(board[r][c] == 'x' && neighbours >= 2) board[r][c] = 'o';
        }
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int*));
    for(int i = 0; i < MAX; i++) board[i] = (int*)malloc(MAX * sizeof(int));

    // Initialize the board
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = 'x';
        }
    }

    board[1][1] = 'o';
    board[2][2] = 'o';
    board[2][3] = 'o';

    // Game loop
    int generation = 0;
    while(1)
    {
        drawBoard(board);
        calculateNextState(board);
        generation++;
        if(generation == 10) break;
    }

    drawBoard(board);
    printf("Generation: %d", generation);

    free(board);

    return 0;
}