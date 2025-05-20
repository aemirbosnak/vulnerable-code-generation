//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void drawBoard(int **board)
{
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int**)malloc(MAX * sizeof(int *));
    for(int r = 0; r < MAX; r++)
    {
        board[r] = (int *)malloc(MAX * sizeof(int));
    }

    srand(time(NULL));

    // Initialize the board
    for(int r = 0; r < MAX; r++)
    {
        for(int c = 0; c < MAX; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while(!board[0][0] || board[MAX - 1][MAX - 1])
    {
        drawBoard(board);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        for(int r = 0; r < MAX; r++)
        {
            for(int c = 0; c < MAX; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != board[r][c])
                        {
                            neighbors++;
                        }
                    }
                }

                if(board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if(board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        generation++;
    }

    drawBoard(board);
    printf("Generation: %d\n", generation);

    free(board);

    return 0;
}