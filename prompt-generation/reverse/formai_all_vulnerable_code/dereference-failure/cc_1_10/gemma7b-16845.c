//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void draw_board(int **board, int size)
{
    for(int r = 0; r < size; r++)
    {
        for(int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for(int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    board[2][2] = board[3][2] = 1;
    board[3][3] = board[2][3] = 1;

    int generations = 0;
    while(board[size - 1][size - 1] != 1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generations);

        // Invade the board
        for(int r = 0; r < size; r++)
        {
            for(int c = 0; c < size; c++)
            {
                if(board[r][c] == 0)
                {
                    int neighbors = 0;
                    for(int dr = -1; dr <= 1; dr++)
                    {
                        for(int dc = -1; dc <= 1; dc++)
                        {
                            if(board[r + dr][c + dc] == 1)
                            {
                                neighbors++;
                            }
                        }
                    }

                    if(neighbors >= 3)
                    {
                        board[r][c] = 1;
                    }
                }
            }
        }

        generations++;
    }

    draw_board(board, size);
    printf("Generation: %d\n", generations);

    free(board);

    return 0;
}