//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct {
    int row;
    int col;
} Coordinate;

typedef struct {
    int width;
    int height;
    Coordinate start;
    Coordinate end;
    int** grid;
} Maze;

Maze createMaze(int rows, int cols) {
    Maze maze;
    maze.width = cols;
    maze.height = rows;
    maze.start.row = rand() % rows;
    maze.start.col = rand() % cols;
    maze.end.row = rand() % rows;
    maze.end.col = rand() % cols;
    maze.grid = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze.grid[i] = (int*) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze.grid[i][j] = rand() % 2;
        }
    }
    return maze;
}

void printMaze(Maze maze) {
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            printf("%d ", maze.grid[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(Maze maze, Coordinate current, Coordinate next) {
    if (next.row < 0 || next.row >= maze.height || next.col < 0 || next.col >= maze.width) {
        return 0;
    }
    return 1;
}

Coordinate findNextStep(Maze maze, Coordinate current) {
    Coordinate next;
    next.row = current.row;
    next.col = current.col;
    int i = 0;
    int j = 0;
    int minDist = 0;
    Coordinate currentStep = maze.start;
    Coordinate nextStep;
    while (i < maze.height && j < maze.width) {
        if (maze.grid[i][j] == 1) {
            if (isValidMove(maze, currentStep, nextStep)) {
                minDist += 1;
                if (minDist > 0) {
                    return nextStep;
                }
                currentStep = nextStep;
            }
            nextStep.row = i;
            nextStep.col = j;
            j++;
        } else {
            i++;
        }
    }
    return nextStep;
}

void solveMaze(Maze maze) {
    Coordinate current = maze.start;
    Coordinate nextStep;
    while (isValidMove(maze, current, nextStep)) {
        current = nextStep;
        nextStep = findNextStep(maze, current);
    }
    printf("Solution: ");
    printMaze(maze);
}

int main() {
    srand(time(NULL));
    Maze maze = createMaze(MAX_ROWS, MAX_COLS);
    printMaze(maze);
    solveMaze(maze);
    free(maze.grid);
    return 0;
}