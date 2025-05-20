//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

void draw_board(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%c ", board[r][c] ? '*' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int size = MAX_SIZE;
    int **board = (int **)malloc(size * sizeof(int *) + size);
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int) + size);
    }

    // Initialize the board
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create some random live cells
    board[10][10] = 1;
    board[10][11] = 1;
    board[11][10] = 1;
    board[12][10] = 1;

    // Game loop
    int generation = 0;
    while (1)
    {
        draw_board(board, size);
        printf("Generation: %d\n", generation);

        // Calculate the next generation
        for (int r = 0; r < size; r++)
        {
            for (int c = 0; c < size; c++)
            {
                int num_alive = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != -1)
                        {
                            num_alive++;
                        }
                    }
                }

                if (board[r][c] == 1 && num_alive < 2)
                {
                    board[r][c] = -1;
                }
                else if (board[r][c] == 0 && num_alive == 3)
                {
                    board[r][c] = 1;
                }
            }
        }

        generation++;

        // Check if the player wants to continue
        char continue_yn;
        printf("Continue? (Y/N): ");
        scanf("%c", &continue_yn);

        if (continue_yn != 'Y')
        {
            break;
        }
    }

    draw_board(board, size);
    printf("Final Board:\n");

    free(board);

    return 0;
}