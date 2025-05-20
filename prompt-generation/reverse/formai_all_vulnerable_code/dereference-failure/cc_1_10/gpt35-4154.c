//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random initial state of cells
void init_cells(int **grid, int height, int width)
{
    srand(time(NULL));
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

//Function to count live neighbors of a cell
int count_neighbors(int **grid, int row, int col, int height, int width)
{
    int count = 0;
    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            int r = (row+i+height) % height;
            int c = (col+j+width) % width;
            count += grid[r][c];
        }
    }
    count -= grid[row][col];
    return count;
}

//Function to update the state of cells
void update_cells(int **grid, int height, int width)
{
    int new_grid[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int neighbors = count_neighbors(grid, i, j, height, width);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3))
            {
                new_grid[i][j] = 0;
            }
            else if(grid[i][j] == 0 && neighbors == 3)
            {
                new_grid[i][j] = 1;
            }
            else
            {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

//Function to display the grid
void display(int **grid, int height, int width)
{
    system("clear");
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(grid[i][j] == 1)
            {
                printf(" *");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int height = 20;
    int width = 40;
    int **grid = (int **)malloc(height * sizeof(int *));
    for(int i=0; i<height; i++)
    {
        grid[i] = (int *)malloc(width * sizeof(int));
    }
    init_cells(grid, height, width);
    while(1)
    {
        display(grid, height, width);
        update_cells(grid, height, width);
    }
    return 0;
}