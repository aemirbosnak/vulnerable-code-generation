//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50
#define MARGIN 1

typedef struct {
    int rows;
    int cols;
    int **maze;
} Maze;

bool isValid(Maze* maze, int x, int y) {
    return x >= 0 && x < maze->rows && y >= 0 && y < maze->cols;
}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 1) {
                printf("*");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void generateMaze(Maze* maze, int startX, int startY, int endX, int endY) {
    // create a new maze
    maze->rows = MAX_ROWS;
    maze->cols = MAX_COLS;
    maze->maze = malloc(sizeof(int*) * maze->rows);
    for (int i = 0; i < maze->rows; i++) {
        maze->maze[i] = malloc(sizeof(int) * maze->cols);
        for (int j = 0; j < maze->cols; j++) {
            maze->maze[i][j] = 0;
        }
    }

    // create a wall around the maze
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (i == 0 || i == maze->rows - 1 || j == 0 || j == maze->cols - 1) {
                maze->maze[i][j] = 1;
            }
        }
    }

    // find a path from start to end
    bool foundPath = false;
    while (!foundPath) {
        // generate a random starting point
        int randX = rand() % (maze->cols - 1) + 1;
        int randY = rand() % (maze->rows - 1) + 1;

        // check if the starting point is valid
        if (isValid(maze, randX, randY)) {
            int currX = randX;
            int currY = randY;

            // generate a random direction
            int dirX = rand() % 4 + 1;
            int dirY = rand() % 4 + 1;

            // move in the direction until a wall is encountered
            while (true) {
                int newX = currX + dirX;
                int newY = currY + dirY;

                if (isValid(maze, newX, newY) && maze->maze[newX][newY] == 0) {
                    maze->maze[currX][currY] = 1;
                    currX = newX;
                    currY = newY;
                    break;
                } else {
                    dirX = (dirX + 1) % 4;
                    dirY = (dirY + 1) % 4;
                }
            }

            // check if the end point is valid
            if (isValid(maze, endX, endY)) {
                foundPath = true;
            }
        } else {
            // try again
            randX = rand() % (maze->cols - 1) + 1;
            randY = rand() % (maze->rows - 1) + 1;
        }
    }

    // print the maze
    printMaze(maze);
}

int main() {
    srand(time(NULL));

    // create a maze
    Maze maze;
    maze.rows = MAX_ROWS;
    maze.cols = MAX_COLS;
    maze.maze = malloc(sizeof(int*) * maze.rows);
    for (int i = 0; i < maze.rows; i++) {
        maze.maze[i] = malloc(sizeof(int) * maze.cols);
        for (int j = 0; j < maze.cols; j++) {
            maze.maze[i][j] = 0;
        }
    }

    // generate a maze
    int startX = rand() % (maze.cols - 1) + 1;
    int startY = rand() % (maze.rows - 1) + 1;
    int endX = rand() % (maze.cols - 1) + 1;
    int endY = rand() % (maze.rows - 1) + 1;
    generateMaze(&maze, startX, startY, endX, endY);

    return 0;
}