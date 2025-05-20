//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void play_bingo(int **board, int size)
{
    int i, j, num, won = 0;
    printf("Press any key to begin...");
    getchar();

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Enter number for cell (%d, %d): ", i, j);
            scanf("%d", &num);

            if (num == board[i][j])
            {
                board[i][j] = -1;
                won = 1;
            }
        }
    }

    if (won)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("Sorry, you lost.\n");
    }
}

int main()
{
    int size, i;
    printf("Enter the number of rows: ");
    scanf("%d", &size);

    int **board = (int**)malloc(size * sizeof(int*));
    for (i = 0; i < size; i++)
    {
        board[i] = (int*)malloc(size * sizeof(int));
    }

    play_bingo(board, size);

    return 0;
}