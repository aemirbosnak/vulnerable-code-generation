//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void drawBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int*));
    for(int r = 0; r < MAX; r++)
    {
        board[r] = (int*)malloc(MAX * sizeof(int));
    }

    // Initial board setup
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Game loop
    int generation = 0;
    while(1)
    {
        drawBoard(board);
        printf("Generation: %d\n", generation++);

        // Calculate next generation
        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int aliveNeighbors = 0;
                if(board[r-1][c] == 1) aliveNeighbors++;
                if(board[r+1][c] == 1) aliveNeighbors++;
                if(board[r][c-1] == 1) aliveNeighbors++;
                if(board[r][c+1] == 1) aliveNeighbors++;

                if(board[r][c] == 1 && aliveNeighbors < 2) board[r][c] = 0;
                if(board[r][c] == 0 && aliveNeighbors == 3) board[r][c] = 1;
            }
        }

        // Check if game is over
        if(board[0][0] == 0) break;

        // Pause
        system("pause");
    }

    drawBoard(board);
    printf("Final Board:\n");

    free(board);

    return 0;
}