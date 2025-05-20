//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

void generateMaze(int rows, int cols, char maze[][cols])
{
    int startRow = rand() % rows;
    int startCol = rand() % cols;
    
    // Initialize maze with walls
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            maze[i][j] = '#';
        }
    }
    
    // Create path starting from random location
    maze[startRow][startCol] = ' ';
    int currentRow = startRow;
    int currentCol = startCol;
    do
    {
        int direction = rand() % 4;
        if (direction == 0) // Go up
        {
            if (currentRow > 0 && maze[currentRow-1][currentCol] == '#')
            {
                currentRow--;
                maze[currentRow][currentCol] = ' ';
            }
        }
        else if (direction == 1) // Go right
        {
            if (currentCol < cols-1 && maze[currentRow][currentCol+1] == '#')
            {
                currentCol++;
                maze[currentRow][currentCol] = ' ';
            }
        }
        else if (direction == 2) // Go down
        {
            if (currentRow < rows-1 && maze[currentRow+1][currentCol] == '#')
            {
                currentRow++;
                maze[currentRow][currentCol] = ' ';
            }
        }
        else // Go left
        {
            if (currentCol > 0 && maze[currentRow][currentCol-1] == '#')
            {
                currentCol--;
                maze[currentRow][currentCol] = ' ';
            }
        }
    } while (currentRow != startRow || currentCol != startCol);
}

int main()
{
    srand(time(NULL));
    int rows = rand() % MAX_ROWS + 1; // Random number of rows between 1 and MAX_ROWS
    int cols = rand() % MAX_COLS + 1; // Random number of columns between 1 and MAX_COLS
    
    char maze[rows][cols];
    generateMaze(rows, cols, maze);
    
    // Print maze
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}