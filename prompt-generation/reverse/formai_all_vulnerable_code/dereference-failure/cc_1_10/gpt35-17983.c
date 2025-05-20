//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 5

// This function is used to print the grid
void printGrid(int **grid)
{
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(grid[i][j] == 0) printf(". ");
            else if(grid[i][j] == 1) printf("X ");
            else if(grid[i][j] == 2) printf("S ");
            else if(grid[i][j] == 3) printf("E ");
        }
        printf("\n");
    }
}

// This function is used to check if a cell is valid or not
int isValid(int row, int col)
{
    if(row < 0 || row >= ROWS) return 0;
    if(col < 0 || col >= COLS) return 0;
    return 1;
}

// This function is used to find the path
void findPath(int **grid, int startRow, int startCol, int endRow, int endCol)
{
    int **visited = (int **)malloc(sizeof(int *) * ROWS);
    int i;
    for(i = 0; i < ROWS; i++)
    {
        visited[i] = (int *)calloc(COLS, sizeof(int));
    }

    int **queue = (int **)malloc(sizeof(int *) * ROWS * COLS);
    for(i = 0; i < ROWS * COLS; i++)
    {
        queue[i] = (int *)malloc(sizeof(int) * 2);
    }

    int front = 0, end = 0;

    queue[end][0] = startRow;
    queue[end][1] = startCol;
    end++;

    visited[startRow][startCol] = 1;

    while(front != end)
    {
        int *current = queue[front];
        front++;

        int row = current[0];
        int col = current[1];

        if(row == endRow && col == endCol)
        {
            // Path found, mark the path using 1
            int x = endRow, y = endCol;
            while(1)
            {
                grid[x][y] = 1;
                if(x == startRow && y == startCol) break;
                if(visited[x-1][y] == visited[x][y] - 1) x--;
                else if(visited[x][y-1] == visited[x][y] - 1) y--;
                else if(visited[x+1][y] == visited[x][y] - 1) x++;
                else if(visited[x][y+1] == visited[x][y] - 1) y++;
            }

            printGrid(grid);
            return;
        }

        // Check adjacent cells
        if(isValid(row-1, col) && grid[row-1][col] != 1 && visited[row-1][col] == 0)
        {
            visited[row-1][col] = visited[row][col] + 1;
            queue[end][0] = row-1;
            queue[end][1] = col;
            end++;
        }

        if(isValid(row, col-1) && grid[row][col-1] != 1 && visited[row][col-1] == 0)
        {
            visited[row][col-1] = visited[row][col] + 1;
            queue[end][0] = row;
            queue[end][1] = col-1;
            end++;
        }

        if(isValid(row+1, col) && grid[row+1][col] != 1 && visited[row+1][col] == 0)
        {
            visited[row+1][col] = visited[row][col] + 1;
            queue[end][0] = row+1;
            queue[end][1] = col;
            end++;
        }

        if(isValid(row, col+1) && grid[row][col+1] != 1 && visited[row][col+1] == 0)
        {
            visited[row][col+1] = visited[row][col] + 1;
            queue[end][0] = row;
            queue[end][1] = col+1;
            end++;
        }
    }

    printf("Path not found.\n");

    free(visited);
    free(queue);
}

int main()
{
    int **grid = (int **)malloc(sizeof(int *) * ROWS);
    int i, j;
    for(i = 0; i < ROWS; i++)
    {
        grid[i] = (int *)calloc(COLS, sizeof(int));
    }

    // Mark the start and end cells
    grid[1][0] = 2; // Start
    grid[2][3] = 3; // End

    // Mark the obstacles
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[0][3] = 1;

    printf("Grid:\n");
    printGrid(grid);

    printf("Path:\n");
    findPath(grid, 1, 0, 2, 3);

    for(i = 0; i < ROWS; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}