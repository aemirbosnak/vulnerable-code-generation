//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for pixel size and grid size
#define PIXEL_SIZE 10
#define GRID_SIZE 20

// Define color constants
#define RED 0x0000FF
#define GREEN 0x00FF00
#define BLUE 0xFF0000
#define YELLOW 0xFFFF00

// Define function to generate random color
int randomColor()
{
    return rand() % (RED + GREEN + BLUE + YELLOW);
}

// Define function to generate pixel art
void generatePixelArt(int grid[GRID_SIZE][GRID_SIZE], int color)
{
    int row, col;

    // Fill grid with random colors
    for (row = 0; row < GRID_SIZE; row++)
    {
        for (col = 0; col < GRID_SIZE; col++)
        {
            grid[row][col] = randomColor();
        }
    }

    // Print grid
    for (row = 0; row < GRID_SIZE; row++)
    {
        for (col = 0; col < GRID_SIZE; col++)
        {
            printf("%c", (grid[row][col] == RED)? 'R' : (grid[row][col] == GREEN)? 'G' : (grid[row][col] == BLUE)? 'B' : 'Y');
        }
        printf("\n");
    }
}

int main()
{
    // Generate random grid
    int grid[GRID_SIZE][GRID_SIZE];

    // Generate pixel art
    generatePixelArt(grid, randomColor());

    // Free memory
    for (int i = 0; i < GRID_SIZE; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}