//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ROWS;
int COLS;
char **maze;

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze() {
    // Initialize maze with walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = '#';
        }
    }

    srand(time(NULL));

    // Starting point
    int startX = rand() % COLS;
    int startY = rand() % ROWS;
    maze[startY][startX] = ' ';

    // Stack for backtracking
    int stackX[ROWS * COLS], stackY[ROWS * COLS];
    int stackPtr = 0;
    stackX[stackPtr] = startX;
    stackY[stackPtr] = startY;

    int visitedCells = 1;
    while (visitedCells < ROWS * COLS) {
        int currX = stackX[stackPtr];
        int currY = stackY[stackPtr];

        // Check available neighbors
        int neighborsX[4], neighborsY[4];
        int numNeighbors = 0;
        if (currX > 0 && maze[currY][currX - 1] == '#') {
            neighborsX[numNeighbors] = currX - 1;
            neighborsY[numNeighbors] = currY;
            numNeighbors++;
        }
        if (currX < COLS - 1 && maze[currY][currX + 1] == '#') {
            neighborsX[numNeighbors] = currX + 1;
            neighborsY[numNeighbors] = currY;
            numNeighbors++;
        }
        if (currY > 0 && maze[currY - 1][currX] == '#') {
            neighborsX[numNeighbors] = currX;
            neighborsY[numNeighbors] = currY - 1;
            numNeighbors++;
        }
        if (currY < ROWS - 1 && maze[currY + 1][currX] == '#') {
            neighborsX[numNeighbors] = currX;
            neighborsY[numNeighbors] = currY + 1;
            numNeighbors++;
        }

        if (numNeighbors > 0) {
            // Choose a random neighbor and carve a path to it
            int chosenNeighbor = rand() % numNeighbors;
            int newX = neighborsX[chosenNeighbor];
            int newY = neighborsY[chosenNeighbor];
            if (newX < currX) {
                maze[currY][currX - 1] = ' ';
            } else if (newX > currX) {
                maze[currY][currX + 1] = ' ';
            } else if (newY < currY) {
                maze[currY - 1][currX] = ' ';
            } else {
                maze[currY + 1][currX] = ' ';
            }

            // Push new cell to stack and mark as visited
            stackPtr++;
            stackX[stackPtr] = newX;
            stackY[stackPtr] = newY;
            visitedCells++;
        } else {
            // No available neighbors, backtrack
            stackPtr--;
        }
    }
}

int main() {
    printf("Enter number of rows and columns (minimum 5): ");
    scanf("%d %d", &ROWS, &COLS);

    if (ROWS < 5 || COLS < 5) {
        printf("Invalid input\n");
        return 1;
    }

    // Allocate memory for maze
    maze = (char **) malloc(ROWS * sizeof(char *));
    for (int i = 0; i < ROWS; i++) {
        maze[i] = (char *) malloc(COLS * sizeof(char));
    }

    generateMaze();
    printMaze();

    // Free memory
    for (int i = 0; i < ROWS; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}