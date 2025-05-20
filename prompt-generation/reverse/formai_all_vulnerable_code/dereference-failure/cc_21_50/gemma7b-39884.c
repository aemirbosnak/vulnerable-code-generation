//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows = 0;
    int cols = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("Enter the initial state of the cell (0/1): ");
            scanf("%d", &board[r][c]);
        }
    }

    // Game of Life Logic

    for (int t = 0; t < 10; t++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int alive = board[r][c] & 1;
                int neighbors = 0;

                // Count the number of neighbors
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (dr == 0 && dc == 0)
                            continue;

                        if (r + dr < 0 || r + dr >= rows)
                            continue;

                        if (c + dc < 0 || c + dc >= cols)
                            continue;

                        if (board[r + dr][c + dc] & 1)
                            neighbors++;
                    }
                }

                // Apply the Game of Life rules
                if (alive && neighbors < 2)
                    board[r][c] &= ~1;
                else if (alive && neighbors > 3)
                    board[r][c] &= ~1;
                else if (!alive && neighbors == 3)
                    board[r][c] |= 1;
            }
        }

        // Print the board
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%d ", board[r][c] & 1);
            }
            printf("\n");
        }
    }

    return 0;
}