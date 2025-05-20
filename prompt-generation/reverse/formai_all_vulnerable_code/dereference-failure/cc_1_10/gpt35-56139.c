//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

//Function to print the maze
void printMaze(int ** maze, int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the current position is in bound and unvisited
int isSafe(int ** maze, int n, int row, int col, int ** visited) {
    return (row>=0 && row<n && col>=0 && col<n && maze[row][col]==1 && visited[row][col]!=1);
}

//Main function to find the route through the maze
int findRoute(int ** maze, int ** visited, int n, int row, int col, int ** route, int index) {
    //Check if the end point has been reached
    if(row==n-1 && col==n-1 && maze[row][col]==1) {
        route[index][0] = row;
        route[index][1] = col;
        return 1;
    }

    //If the current position is safe
    if(isSafe(maze,n,row,col,visited)) {
        visited[row][col] = 1;
        route[index][0] = row;
        route[index][1] = col;

        //Move right
        if(findRoute(maze,visited,n,row,col+1,route,index+1)==1) {
            return 1;
        }

        //Move down
        if(findRoute(maze,visited,n,row+1,col,route,index+1)==1) {
            return 1;
        }

        //Move left
        if(findRoute(maze,visited,n,row,col-1,route,index+1)==1) {
            return 1;
        }

        //Move up
        if(findRoute(maze,visited,n,row-1,col,route,index+1)==1) {
            return 1;
        }

        //If there is no route in any direction
        visited[row][col] = 0;
        route[index][0] = -1;
        route[index][1] = -1;
        return 0;
    }
    //If the current position is not safe
    return 0;
}

int main() {
    //Size of the maze
    int n = 5;

    //Initialize the maze
    int **maze = (int **)malloc(n * sizeof(int *));
    for(int i=0;i<n;i++) {
        maze[i] = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++) {
            maze[i][j] = 1;
        }
    }
    maze[1][1] = 0;
    maze[2][1] = 0;
    maze[3][3] = 0;

    //Initialize the visited array
    int **visited = (int **)malloc(n * sizeof(int *));
    for(int i=0;i<n;i++) {
        visited[i] = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++) {
            visited[i][j] = 0;
        }
    }

    //Initialize the route array
    int **route = (int **)malloc(n * n * sizeof(int *));
    for(int i=0;i<n*n;i++) {
        route[i] = (int *)malloc(2 * sizeof(int));
        route[i][0] = -1;
        route[i][1] = -1;
    }

    printf("The maze:\n");
    printMaze(maze,n);

    int foundRoute = findRoute(maze,visited,n,0,0,route,0);

    if(foundRoute) {
        printf("\nRoute found:\n");
        for(int i=0;i<n*n;i++) {
            if(route[i][0]!=-1 && route[i][1]!=-1) {
                printf("(%d,%d)->",route[i][0],route[i][1]);
            }
            else {
                break;
            }
        }
    }
    else {
        printf("\nNo route found.\n");
    }
    return 0;
}