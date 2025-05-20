//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void draw_bingo_card(int **card, int rows, int cols);

int main()
{
    int **bingo_card = NULL;
    int rows = 5;
    int cols = 5;

    // Allocate memory for the bingo card
    bingo_card = (int **)malloc(rows * sizeof(int *));
    for (int r = 0; r < rows; r++)
    {
        bingo_card[r] = (int *)malloc(cols * sizeof(int));
    }

    // Generate the bingo card
    draw_bingo_card(bingo_card, rows, cols);

    // Print the bingo card
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%d ", bingo_card[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the bingo card
    for (int r = 0; r < rows; r++)
    {
        free(bingo_card[r]);
    }
    free(bingo_card);

    return 0;
}

void draw_bingo_card(int **card, int rows, int cols)
{
    // Populate the bingo card with random numbers
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            card[r][c] = rand() % 90 + 1;
        }
    }
}