//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: excited
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

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for(int r = 0; r < MAX; r++)
    {
        board[r] = (int *)malloc(MAX * sizeof(int));
    }

    // Initial board setup
    board[1][1] = 1;
    board[2][2] = 1;
    board[3][3] = 1;
    board[4][4] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate next generation
        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int neighbors = 0;
                if(board[r-1][c] == 1) neighbors++;
                if(board[r+1][c] == 1) neighbors++;
                if(board[r][c-1] == 1) neighbors++;
                if(board[r][c+1] == 1) neighbors++;

                if(board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if(board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        generation++;

        // Check if game is over
        if(board[MAX-1][MAX-1] == 1)
        {
            drawBoard(board);
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}