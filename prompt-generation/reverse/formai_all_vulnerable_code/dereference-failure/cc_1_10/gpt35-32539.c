//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Creating a maze with dimensions n*n
void createMaze(int maze[][30], int n)
{
    int i, j;

    //Assigning 0 to every cell of the maze
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            maze[i][j] = 0;
        }
    }

    //Randomly selecting the starting and ending point of the maze
    int startRow = rand() % n;
    int startCol = 0;
    int endRow = rand() % n;
    int endCol = n - 1;

    //Setting the starting and ending point value as 1
    maze[startRow][startCol] = 1;
    maze[endRow][endCol] = 1;
}

//Printing the maze
void printMaze(int maze[][30], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(maze[i][j] == 1)
            {
                printf(" .");
            }
            else
            {
                printf(" -");
            }
        }
        printf("\n");
    }
    printf("\n");
}

//Finding a path from the maze
int findPath(int maze[][30], int n, int row, int col)
{
    //Checking if we have reached the end of the maze
    if(row < 0 || row >= n || col < 0 || col >= n)
    {
        return 0;
    }
    if(maze[row][col] == -1 || maze[row][col] == 1)
    {
        return 0;
    }
    
    //Marking the current cell as visited
    maze[row][col] = -1;

    //Checking for a path to the right
    if(findPath(maze, n, row, col + 1) == 1)
    {
        return 1;
    }

    //Checking for a path to the bottom
    if(findPath(maze, n, row + 1, col) == 1)
    {
        return 1;
    }

    //Checking for a path to the left
    if(findPath(maze, n, row, col - 1) == 1)
    {
        return 1;
    }

    //Checking for a path to the top
    if(findPath(maze, n, row - 1, col) == 1)
    {
        return 1;
    }

    //Unmarking the current cell if there is no path to the end
    maze[row][col] = 0;

    return 0;
}

//Finding a route from the maze and marking it with 2
int solveMaze(int maze[][30], int n)
{
    //Checking if we have reached the end point
    if(maze[0][0] == 1)
    {
        return 0;
    }

    //Finding the path from the maze and marking it with 2
    if(findPath(maze, n, rand() % n, rand() % n) == 0)
    {
        return 0;
    }

    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(maze[i][j] == -1)
            {
                maze[i][j] = 0;
            }
            else if(maze[i][j] == 1)
            {
                maze[i][j] = 2;
            }
        }
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter the dimension of the maze: ");
    scanf("%d", &n);

    int maze[30][30];

    //Creating the maze
    createMaze(maze, n);

    //Printing the maze
    printMaze(maze, n);

    //Solving the maze
    if(solveMaze(maze, n) == 0)
    {
        printf("There is no path from the maze.\n");
    }
    else
    {
        //Printing the maze with the route marked by 2
        printMaze(maze, n);
    }

    return 0;
}