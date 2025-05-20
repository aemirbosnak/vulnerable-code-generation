//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 5
#define COLS 5

void printGrid(char** grid, int rows, int cols);
bool isValidMove(char** grid, int x, int y, int rows, int cols);
void findPath(char** grid, int startX, int startY, int endX, int endY, int rows, int cols);

int main() {
    printf("Welcome to this unique C Pathfinding algorithm program!\n");

    // initialize the grid
    char** grid = (char**) malloc(sizeof(char*) * ROWS); 
    for (int i = 0; i < ROWS; i++) {
        grid[i] = (char*) malloc(sizeof(char) * COLS);
    }
    memset(grid, '.', ROWS * COLS * sizeof(char));

    // set start and end points
    int startX = 1;
    int startY = 1;
    int endX = 4;
    int endY = 4;
    grid[startX][startY] = 'S';
    grid[endX][endY] = 'E';

    // add some obstacles
    int obstacles[5][2] = {{1, 3}, {2, 3}, {3, 3}, {3, 2}, {3, 1}};
    for (int i = 0; i < 5; i++) {
        int obstacleX = obstacles[i][0];
        int obstacleY = obstacles[i][1];
        grid[obstacleX][obstacleY] = 'X';
    }

    // print the initial grid
    printGrid(grid, ROWS, COLS);

    // find the path from start to end
    findPath(grid, startX, startY, endX, endY, ROWS, COLS);

    // free memory
    for (int i = 0; i < ROWS; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

void printGrid(char** grid, int rows, int cols) {
    printf("\nGrid:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(char** grid, int x, int y, int rows, int cols) {
    if (x < 0 || y < 0 || x >= rows || y >= cols) {
        return false;
    }
    if (grid[x][y] == 'X' || grid[x][y] == 'V') {
        return false;
    }
    return true;
}

void findPath(char** grid, int startX, int startY, int endX, int endY, int rows, int cols) {
    printf("\nFinding path from (%d, %d) to (%d, %d):\n", startX, startY, endX, endY);

    // initialize stacks for x and y positions
    int* xStack = (int*) malloc(sizeof(int) * (rows * cols));
    int* yStack = (int*) malloc(sizeof(int) * (rows * cols));
    int sp = 0; // stack pointer

    // push the start position onto the stack
    xStack[sp] = startX;
    yStack[sp] = startY;
    sp++;

    // depth-first search for the path
    while (sp > 0) {
        // pop the current position from the stack
        sp--;
        int x = xStack[sp];
        int y = yStack[sp];

        // mark the current position as visited
        grid[x][y] = 'V';

        // check if we have reached the end position
        if (x == endX && y == endY) {
            printf("Path found!\n");
            break;
        }

        // generate all possible moves from the current position
        int possibleMoves[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
        for (int i = 0; i < 4; i++) {
            int newX = possibleMoves[i][0];
            int newY = possibleMoves[i][1];
            if (isValidMove(grid, newX, newY, rows, cols)) {
                // push the new position onto the stack
                xStack[sp] = newX;
                yStack[sp] = newY;
                sp++;
            }
        }
    }

    // if the stack is empty and we haven't found the path, it doesn't exist
    if (sp == 0) {
        printf("No path found.\n");
    }

    // print the final grid with the path
    printGrid(grid, rows, cols);

    // free memory
    free(xStack);
    free(yStack);
}