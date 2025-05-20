//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void draw_board(int **board);
void play_game(int **board);

int main()
{
    int **board = NULL;
    int i, j;

    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    play_game(board);

    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}

void draw_board(int **board)
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void play_game(int **board)
{
    int i, j, x, y, next_state[MAX_SIZE][MAX_SIZE];

    draw_board(board);

    // Game loop
    while (!board[MAX_SIZE - 1][MAX_SIZE - 1])
    {
        printf("Enter the coordinates of the cell you want to toggle: ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE)
        {
            printf("Invalid coordinates.\n");
            continue;
        }

        board[x][y] ^= 1;

        // Calculate the next state of the board
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                next_state[i][j] = 0;
                if (board[i][j] == 1)
                {
                    next_state[i][j] = 1;
                }
                else
                {
                    int neighbors = 0;
                    for (int r = -1; r <= 1; r++)
                    {
                        for (int c = -1; c <= 1; c++)
                        {
                            if (board[i + r][j + c] == 1)
                            {
                                neighbors++;
                            }
                        }
                    }
                    if (neighbors == 3)
                    {
                        next_state[i][j] = 1;
                    }
                }
            }
        }

        // Copy the next state of the board to the current state
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                board[i][j] = next_state[i][j];
            }
        }

        draw_board(board);
    }

    printf("Game over.\n");
}