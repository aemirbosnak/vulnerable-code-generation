//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to check if an index is within bounds
bool isIndexOutOfBounds(int index, int size)
{
    return index < 0 || index >= size;
}

// Function to check if a site is open
bool isOpen(bool* grid, int row, int col, int size)
{
    return grid[row*size + col];
}

// Function to open a site
void openSite(bool* grid, int row, int col, int size)
{
    grid[row*size + col] = true;
}

// Recursive function to percolate through the grid
void percolate(bool* grid, int row, int col, int size)
{
    // Check if current site is open or out of bounds
    if(isIndexOutOfBounds(row, size) || isIndexOutOfBounds(col, size) || isOpen(grid, row, col, size))
    {
        return;
    }
    
    // Open current site
    openSite(grid, row, col, size);
    
    // Percolate to neighboring sites
    percolate(grid, row-1, col, size);
    percolate(grid, row+1, col, size);
    percolate(grid, row, col-1, size);
    percolate(grid, row, col+1, size);
}

int main()
{
    int size = 10;
    bool* grid = (bool*)malloc(size*size*sizeof(bool));
    srand(time(NULL));
    
    // Initialize grid with random sites opened
    for(int i = 0; i < size*size; i++)
    {
        grid[i] = rand() < RAND_MAX/2;
    }
    
    // Print initial grid
    printf("Initial Grid:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%c ", isOpen(grid, i, j, size) ? 'O' : 'X');
        }
        printf("\n");
    }
    printf("\n");

    // Percolate through the grid starting from top row
    for(int col = 0; col < size; col++)
    {
        percolate(grid, 0, col, size);
    }
    
    // Print final grid
    printf("Final Grid:\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%c ", isOpen(grid, i, j, size) ? 'O' : 'X');
        }
        printf("\n");
    }
    
    return 0;
}