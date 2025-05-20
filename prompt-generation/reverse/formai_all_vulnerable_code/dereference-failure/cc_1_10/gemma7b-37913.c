//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void initialize_board(int **board, int size)
{
    board = (int *)malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }
}

void print_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

void calculate_next_state(int **board, int size)
{
    int **next_board = (int *)malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int num_neighbors = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    if (r + dr >= 0 && r + dr < size && c + dc >= 0 && c + dc < size)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }
            }
            next_board[r][c] = (num_neighbors == 2) || (num_neighbors == 3);
        }
    }

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = next_board[r][c];
        }
    }

    free(next_board);
}

int main()
{
    int size = 20;
    int **board = NULL;

    initialize_board(board, size);

    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    print_board(board, size);

    calculate_next_state(board, size);

    print_board(board, size);

    return 0;
}