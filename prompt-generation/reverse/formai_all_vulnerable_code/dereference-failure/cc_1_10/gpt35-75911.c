//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//function to print final route
void printRoute(int **maze, int row, int col, int *path, int len) {
    printf("The route to reach end is:\n");
    for(int i=0; i<len; i++) {
        int r = path[i] / col;
        int c = path[i] % col;
        printf("(%d,%d)->", r, c);
    }
    printf("Exit\n");
}

//function to check if given location is valid for path
bool isSafe(int **maze, int row, int col, int r, int c) {
    if(r>=0 && r<row && c>=0 && c<col && maze[r][c]==1)
        return true;
    return false;
}

//recursive function to find the path
bool findPath(int **maze, int row, int col, int r, int c, int *path, int index) {
    //base case - reached at the end
    if(r==row-1 && c==col-1) {
        path[index] = r*col + c;
        printRoute(maze, row, col, path, index+1);
        return true;
    }
    //checking if current cell is safe to move
    if(isSafe(maze, row, col, r, c)) {
        //marking cell as visited
        maze[r][c] = 0;
        path[index] = r*col + c;
        //moving in all the possible directions
        if(findPath(maze, row, col, r+1, c, path, index+1))
            return true;
        if(findPath(maze, row, col, r, c+1, path, index+1))
            return true;
        if(findPath(maze, row, col, r-1, c, path, index+1))
            return true;
        if(findPath(maze, row, col, r, c-1, path, index+1))
            return true;
        //unmarking the cell as backtracking is required
        maze[r][c] = 1;
    }
    return false;
}

int main() {
    int row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int **maze = (int **)malloc(row * sizeof(int *));
    int *path = (int *)malloc(row*col * sizeof(int));

    printf("Enter the maze in form of 0's and 1's:\n");
    for(int i=0; i<row; i++) {
        maze[i] = (int *)malloc(col * sizeof(int));
        for(int j=0; j<col; j++)
            scanf("%d", &maze[i][j]);
    }
    //kicking off the function from starting location
    if(!findPath(maze, row, col, 0, 0, path, 0))
        printf("Route to end is not possible!\n");

    //freeing up memory
    for(int i=0; i<row; i++)
        free(maze[i]);
    free(maze);
    free(path);

    return 0;
}