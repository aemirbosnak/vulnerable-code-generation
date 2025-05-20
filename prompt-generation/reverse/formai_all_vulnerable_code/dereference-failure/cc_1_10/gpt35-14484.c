//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Function to print the maze
void printMaze(char** maze, int w, int h) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze
void generateMaze(char** maze, int w, int h) {
    // Initialize the maze
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            maze[i][j] = '#';
        }
    }

    // Set the starting and ending positions
    int startX = 1;
    int startY = 1;
    int endX = w - 2;
    int endY = h - 2;
    maze[startY][startX] = 'S';
    maze[endY][endX] = 'E';

    // Generate the maze using a random DFS algorithm
    int visited[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            visited[i][j] = 0;
        }
    }
    visited[startY][startX] = 1;

    int stackX[h*w];
    int stackY[h*w];
    int stackIndex = 0;
    stackX[stackIndex] = startX;
    stackY[stackIndex] = startY;

    srand(time(NULL));
    while (stackIndex >= 0) {
        int curX = stackX[stackIndex];
        int curY = stackY[stackIndex];
        stackIndex--;

        int dirs[4] = {0, 1, 2, 3};
        for (int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp = dirs[i];
            dirs[i] = dirs[j];
            dirs[j] = temp;
        }

        for (int i = 0; i < 4; i++) {
            int dir = dirs[i];
            int newX, newY;
            if (dir == 0) {
                newX = curX;
                newY = curY - 2;
            } else if (dir == 1) {
                newX = curX + 2;
                newY = curY;
            } else if (dir == 2) {
                newX = curX;
                newY = curY + 2;
            } else {
                newX = curX - 2;
                newY = curY;
            }

            if (newX < 1 || newY < 1 || newX >= w-1 || newY >= h-1 || visited[newY][newX]) {
                continue;
            }

            if (dir == 0) {
                maze[newY+1][newX] = ' ';
            } else if (dir == 1) {
                maze[newY][newX-1] = ' ';
            } else if (dir == 2) {
                maze[newY-1][newX] = ' ';
            } else {
                maze[newY][newX+1] = ' ';
            }

            visited[newY][newX] = 1;
            stackIndex++;
            stackX[stackIndex] = newX;
            stackY[stackIndex] = newY;
        }

    }

}

int main() {
    // Define the dimensions of the maze
    int w = 21;
    int h = 21;

    // Allocate memory for the maze
    char** maze = (char**) malloc(h * sizeof(char*));
    for (int i = 0; i < h; i++) {
        maze[i] = (char*) malloc(w * sizeof(char));
    }

    // Generate and print the maze
    generateMaze(maze, w, h);
    printMaze(maze, w, h);

    // Free the memory used by the maze
    for (int i = 0; i < h; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}