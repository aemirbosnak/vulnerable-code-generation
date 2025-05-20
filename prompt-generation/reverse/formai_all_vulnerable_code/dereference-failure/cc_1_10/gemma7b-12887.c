//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 20

typedef struct Cell
{
    int x;
    int y;
    char state;
} Cell;

Cell** createGrid(int w, int h)
{
    Cell** grid = (Cell**)malloc(h * sizeof(Cell*));
    for (int i = 0; i < h; i++)
    {
        grid[i] = (Cell*)malloc(w * sizeof(Cell));
        for (int j = 0; j < w; j++)
        {
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].state = 'o';
        }
    }

    return grid;
}

void drawGrid(Cell** grid)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            switch (grid[i][j].state)
            {
                case 'o':
                    printf("O ");
                    break;
                case 'x':
                    printf("X ");
                    break;
                case '.':
                    printf(". ");
                    break;
            }
        }

        printf("\n");
    }
}

int main()
{
    Cell** grid = createGrid(WIDTH, HEIGHT);

    drawGrid(grid);

    // Game logic and player input goes here

    drawGrid(grid);

    free(grid);

    return 0;
}