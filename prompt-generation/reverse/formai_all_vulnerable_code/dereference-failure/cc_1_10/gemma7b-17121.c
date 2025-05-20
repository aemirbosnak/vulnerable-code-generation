//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void draw_board(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? 'O' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int**)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial random organisms
    for(int i = 0; i < 10; i++)
    {
        board[rand() % size][rand() % size] = 1;
    }

    // Simulate the game of life
    for(int t = 0; t < 100; t++)
    {
        draw_board(board, size);

        // Calculate the next generation
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                int neighbors = 0;
                for(int dr = -1; dr <= 1; dr++)
                {
                    for(int dc = -1; dc <= 1; dc++)
                    {
                        if(board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                if(board[r][c] == 0 && neighbors >= 3)
                {
                    board[r][c] = 1;
                }
                else if(board[r][c] == 1 && neighbors < 2)
                {
                    board[r][c] = 0;
                }
            }
        }
    }

    draw_board(board, size);

    free(board);

    return 0;
}