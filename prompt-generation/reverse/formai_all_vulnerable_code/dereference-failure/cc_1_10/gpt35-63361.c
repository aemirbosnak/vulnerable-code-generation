//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMaze(int maze[][10],int rows,int cols)
{
    // Print the maze
    printf("\n\nMaze:");
    for(int i=0; i<rows; i++)
    {
        printf("\n");
        for(int j=0; j<cols; j++)
        {
            if(maze[i][j] == 0) printf("# ");
            else if(maze[i][j] == 1) printf("@ ");
            else if(maze[i][j] == 2) printf("O ");
        }
    }
}

void generateMaze(int maze[][10],int rows,int cols,int start_row,int start_col)
{
    // Generate random maze
    srand(time(NULL));
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            maze[i][j] = rand()%2;
        }
    }
    maze[start_row][start_col] = 2;
}

void findRoute(int maze[][10],int rows,int cols,int start_row,int start_col)
{
    // Find route to the end of the maze
    printf("\n\nFinding route...\n");

    int current_row = start_row;
    int current_col = start_col;

    while(1)
    {
        if(current_row == rows-1 && current_col == cols-1)
        {
            printf("\nReached end of maze!");
            break;
        }

        // Move right
        if(maze[current_row][current_col+1] == 1 || maze[current_row][current_col+1] == 2)
        {
            current_col++;
            maze[current_row][current_col] = 2;
            printf("\nMoved right. Current position: (%d,%d)",current_row,current_col);
        }

        // Move down
        else if(maze[current_row+1][current_col] == 1 || maze[current_row+1][current_col] == 2)
        {
            current_row++;
            maze[current_row][current_col] = 2;
            printf("\nMoved down. Current position: (%d,%d)",current_row,current_col);
        }

        // Move left
        else if(maze[current_row][current_col-1] == 1 || maze[current_row][current_col-1] == 2)
        {
            current_col--;
            maze[current_row][current_col] = 2;
            printf("\nMoved left. Current position: (%d,%d)",current_row,current_col);
        }

        // Move up
        else if(maze[current_row-1][current_col] == 1 || maze[current_row-1][current_col] == 2)
        {
            current_row--;
            maze[current_row][current_col] = 2;
            printf("\nMoved up. Current position: (%d,%d)",current_row,current_col);
        }

        // Stuck
        else
        {
            printf("\nCannot move anymore. Stuck at position: (%d,%d)",current_row,current_col);
            break;
        }
    }
}

int main()
{
    int maze[10][10];
    int rows = 10;
    int cols = 10;
    int start_row = 0;
    int start_col = 0;

    printf("Welcome to the Maze Route Finder!");

    generateMaze(maze,rows,cols,start_row,start_col);
    printMaze(maze,rows,cols);
    findRoute(maze,rows,cols,start_row,start_col);

    return 0;
}