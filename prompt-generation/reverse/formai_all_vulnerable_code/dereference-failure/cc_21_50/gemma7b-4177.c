//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(columns * sizeof(int));
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            printf("Enter the initial state of the cell at (%d, %d) (0 for dead, 1 for alive): ", r, c);
            scanf("%d", &board[r][c]);
        }
    }

    int generations = 0;

    while (1)
    {
        int alive_cells = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                int num_alive_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (r + dr >= 0 && r + dr < rows && c + dc >= 0 && c + dc < columns)
                        {
                            if (board[r + dr][c + dc] == 1)
                            {
                                num_alive_neighbors++;
                            }
                        }
                    }
                }

                if (board[r][c] == 1 && num_alive_neighbors < 2)
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && num_alive_neighbors == 2)
                {
                    board[r][c] = 1;
                }
                alive_cells++;
            }
        }

        if (alive_cells == 0)
        {
            break;
        }

        printf("Generation %d:\n", generations);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        generations++;
    }

    return 0;
}