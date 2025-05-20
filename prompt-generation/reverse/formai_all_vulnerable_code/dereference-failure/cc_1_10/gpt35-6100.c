//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#define ROW 5
#define COL 5

// function prototypes
int** createGrid(int rows, int cols);
void printGrid(int **grid, int rows, int cols);
void freeGrid(int **grid, int rows);
int distance(int x1, int y1, int x2, int y2);
int manhattan(int x1, int y1, int x2, int y2);
int euclidean(int x1, int y1, int x2, int y2);
void aStar(int **grid, int rows, int cols, int startX, int startY, int endX, int endY);

int main(void) {
    // create the grid
    int **grid = createGrid(ROW, COL);
    // print the initial grid
    printf("Initial Grid:\n");
    printGrid(grid, ROW, COL);
    // A* algorithm
    printf("Pathfinding using A Star Algorithm:\n\n");
    aStar(grid, ROW, COL, 0, 0, 4, 4);
    // free the grid memory
    freeGrid(grid, ROW);
    return 0;
}

// function to create the grid
int** createGrid(int rows, int cols) {
    int **grid = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        grid[i] = (int *) malloc(cols * sizeof(int));
        for(int j=0; j<cols; j++)
            grid[i][j] = 0;
    }
    // set the obstacle cells
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
    grid[3][3] = 1;
    return grid;
}

// function to print the grid
void printGrid(int **grid, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        printf("|");
        for(int j=0; j<cols; j++) {
            if(grid[i][j] == 0)
                printf(" O |");
            else
                printf(" X |");
        }
        printf("\n");
    }
}

// function to free the grid memory
void freeGrid(int **grid, int rows) {
    for(int i=0; i<rows; i++)
        free(grid[i]);
    free(grid);
}

// function to calculate the distance between two points (x1, y1) and (x2, y2)
int distance(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
}

// function to calculate the manhattan distance between two points (x1, y1) and (x2, y2)
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x2-x1) + abs(y2-y1);
}

// function to calculate the euclidean distance between two points (x1, y1) and (x2, y2)
int euclidean(int x1, int y1, int x2, int y2) {
    return (int) sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// A* algorithm
void aStar(int **grid, int rows, int cols, int startX, int startY, int endX, int endY) {
    // initialize the open and closed lists
    int openList[rows*cols][3], closedList[rows*cols][3];
    int openCount = 0, closedCount = 0;
    // add the start node to the open list
    openList[openCount][0] = startX;
    openList[openCount][1] = startY;
    openList[openCount++][2] = 0;
    // loop until the end cell is reached or the open list is empty
    while(openCount > 0) {
        // find the node with the lowest f value in the open list
        int lowest = 0;
        for(int i=0; i<openCount; i++)
            if(openList[i][2] < openList[lowest][2])
                lowest = i;
        int currX = openList[lowest][0], currY = openList[lowest][1], currF = openList[lowest][2];
        // move the current node to the closed list
        closedList[closedCount][0] = currX;
        closedList[closedCount++][1] = currY;
        // if the end node is reached, exit the loop
        if(currX == endX && currY == endY)
            break;
        // remove the current node from the open list
        for(int i=lowest; i<openCount-1; i++)
            openList[i][0] = openList[i+1][0], openList[i][1] = openList[i+1][1], openList[i][2] = openList[i+1][2];
        openCount--;
        // process the 8 adjacent cells of the current node
        for(int i=-1; i<=1; i++)
            for(int j=-1; j<=1; j++) {
                if(i==0 && j==0)
                    continue;
                int x = currX+i, y = currY+j;
                int dist = distance(currX, currY, x, y);
                if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y]==1 || grid[currX][y]==1 || grid[x][currY]==1)
                    continue;
                int g = currF + dist;
                int h = manhattan(x, y, endX, endY);
                int f = g + h;
                // add the child node to the open list
                int flag = 1;
                for(int i=0; i<openCount; i++)
                    if(openList[i][0] == x && openList[i][1] == y && openList[i][2] < f)
                        flag = 0;
                for(int i=0; i<closedCount; i++)
                    if(closedList[i][0] == x && closedList[i][1] == y && closedList[i][2] < f)
                        flag = 0;
                if(flag) {
                    openList[openCount][0] = x;
                    openList[openCount][1] = y;
                    openList[openCount++][2] = f;
                }
            }
    }
    // print the final path
    printf("Final Path:\n");
    int pathX[closedCount], pathY[closedCount];
    int curr = closedCount-1;
    pathX[curr] = endX, pathY[curr] = endY;
    while(curr > 0) {
        int currX = closedList[curr][0], currY = closedList[curr][1], currF = closedList[curr][2];
        for(int i=curr-1; i>=0; i--) {
            int x = closedList[i][0], y = closedList[i][1], f = closedList[i][2];
            if(x<currX-1 || x>currX+1 || y<currY-1 || y>currY+1)
                continue;
            if(f < currF) {
                curr = i;
                pathX[curr] = x, pathY[curr] = y;
                break;
            }
        }
    }
    for(int i=0; i<=curr; i++)
        printf("(%d, %d) ", pathX[i], pathY[i]);
    printf("\n\n");
}