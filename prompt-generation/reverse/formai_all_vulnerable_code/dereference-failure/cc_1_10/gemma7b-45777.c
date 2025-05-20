//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 10

void draw_invaders(int **invaders);
void move_invaders(int **invaders);

int main()
{
    int **invaders = (int **)malloc(ROWS * sizeof(int *));
    for(int r = 0; r < ROWS; r++)
    {
        invaders[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize invaders
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            invaders[r][c] = 0;
        }
    }

    invaders[2][2] = 1;
    invaders[2][3] = 1;
    invaders[2][4] = 1;

    // Game loop
    while(!invaders[0][0] && !invaders[ROWS - 1][COLS - 1])
    {
        draw_invaders(invaders);
        move_invaders(invaders);
    }

    // Game over
    draw_invaders(invaders);
    printf("Game Over!\n");

    // Free memory
    for(int r = 0; r < ROWS; r++)
    {
        free(invaders[r]);
    }
    free(invaders);

    return 0;
}

void draw_invaders(int **invaders)
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLS; c++)
        {
            if(invaders[r][c] == 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void move_invaders(int **invaders)
{
    // Move right
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = COLS - 1; c >= 0; c--)
        {
            if(invaders[r][c] == 1 && invaders[r][c + 1] == 0)
            {
                invaders[r][c + 1] = 1;
                invaders[r][c] = 0;
            }
        }
    }

    // Move down
    for(int r = ROWS - 1; r >= 0; r--)
    {
        for(int c = 0; c < COLS; c++)
        {
            if(invaders[r][c] == 1 && invaders[r + 1][c] == 0)
            {
                invaders[r + 1][c] = 1;
                invaders[r][c] = 0;
            }
        }
    }
}