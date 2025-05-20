//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generateMaze(int rows, int cols);
void printMaze(int** maze, int rows, int cols);

int main() {
    srand(time(NULL)); // set random seed

    int rows, cols;

    printf("Enter number of rows in the maze: ");
    scanf("%d", &rows);

    printf("Enter number of columns in the maze: ");
    scanf("%d", &cols);

    generateMaze(rows, cols); // generate maze

    return 0;
}

// generate maze using Prim's algorithm
void generateMaze(int rows, int cols) {
    // initialize maze with all walls
    int** maze = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = 1;
        }
    }

    // randomly choose starting cell
    int startX = rand() % rows;
    int startY = rand() % cols;

    // mark starting cell as visited
    maze[startX][startY] = 0;

    // create list of unvisited cells
    int unvisitedCount = (rows - 1) * (cols - 1);
    int* unvisited = (int*)malloc(unvisitedCount * 2 * sizeof(int));
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 1) {
                unvisited[index] = i;
                unvisited[index + 1] = j;
                index += 2;
            }
        }
    }

    // while there are unvisited cells
    while (unvisitedCount > 0) {
        // choose randomly an unvisited cell
        int cellIndex = rand() % unvisitedCount;
        int cellX = unvisited[cellIndex * 2];
        int cellY = unvisited[cellIndex * 2 + 1];

        // create list of neighboring visited cells
        int neighbors[4][2] = {{cellX - 1, cellY}, {cellX, cellY + 1}, {cellX + 1, cellY}, {cellX, cellY - 1}};
        int neighborCount = 0;
        for (int i = 0; i < 4; i++) {
            int neighborX = neighbors[i][0];
            int neighborY = neighbors[i][1];
            if (neighborX >= 0 && neighborX < rows && neighborY >= 0 && neighborY < cols && maze[neighborX][neighborY] == 0) {
                neighbors[neighborCount][0] = neighborX;
                neighbors[neighborCount][1] = neighborY;
                neighborCount++;
            }
        }

        if (neighborCount > 0) { // if there are neighboring visited cells
            // choose randomly one of the neighbors
            int neighborIndex = rand() % neighborCount;
            int neighborX = neighbors[neighborIndex][0];
            int neighborY = neighbors[neighborIndex][1];

            // remove wall between current cell and neighboring cell
            if (neighborX < cellX) {
                maze[cellX][cellY] &= 0b1110;
                maze[neighborX][neighborY] &= 0b0011;
            } else if (neighborX > cellX) {
                maze[cellX][cellY] &= 0b0011;
                maze[neighborX][neighborY] &= 0b1110;
            } else if (neighborY < cellY) {
                maze[cellX][cellY] &= 0b1101;
                maze[neighborX][neighborY] &= 0b1011;
            } else {
                maze[cellX][cellY] &= 0b1011;
                maze[neighborX][neighborY] &= 0b1101;
            }

            // mark neighboring cell as visited
            maze[neighborX][neighborY] = 0;

            // remove neighboring cell from unvisited list
            unvisited[cellIndex * 2] = unvisited[(unvisitedCount - 1) * 2];
            unvisited[cellIndex * 2 + 1] = unvisited[(unvisitedCount - 1) * 2 + 1];
            unvisitedCount--;
        } else { // if there are no neighboring visited cells
            // remove cell from unvisited list
            unvisited[cellIndex * 2] = unvisited[(unvisitedCount - 1) * 2];
            unvisited[cellIndex * 2 + 1] = unvisited[(unvisitedCount - 1) * 2 + 1];
            unvisitedCount--;
        }
    }

    printMaze(maze, rows, cols); // print finished maze
}

// print maze as ASCII art
void printMaze(int** maze, int rows, int cols) {
    printf(" ");
    for (int i = 0; i < cols; i++) {
        printf("_ ");
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("|");
        for (int j = 0; j < cols; j++) {
            if ((maze[i][j] & 0b0001) == 1) { // print bottom wall
                printf("_");
            } else {
                printf(" ");
            }
            if ((maze[i][j] & 0b0010) == 2) { // print right wall
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}