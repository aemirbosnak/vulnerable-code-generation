//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20
#define MAX_DIRECTIONS 4

typedef struct {
    int row;
    int col;
    int direction;
} Cell;

typedef struct {
    Cell **maze;
    int rows;
    int cols;
    int directions[MAX_DIRECTIONS];
} Maze;

void printMaze(Maze *maze) {
    int i, j;
    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j].direction);
        }
        printf("\n");
    }
}

void generateMaze(Maze *maze) {
    int i, j, k;
    Cell **newMaze;

    srand(time(NULL));

    newMaze = (Cell **)malloc(sizeof(Cell*) * maze->rows);
    for (i = 0; i < maze->rows; i++) {
        newMaze[i] = (Cell *)malloc(sizeof(Cell) * maze->cols);
    }

    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            newMaze[i][j].direction = 0;
            newMaze[i][j].row = i;
            newMaze[i][j].col = j;
        }
    }

    for (k = 0; k < MAX_DIRECTIONS; k++) {
        maze->directions[k] = 0;
    }

    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            if (newMaze[i][j].direction == 0) {
                maze->directions[0] = 1;
                maze->maze[i][j].direction = 0;
                maze->maze[i][j].row = i;
                maze->maze[i][j].col = j;

                for (k = 1; k < MAX_DIRECTIONS; k++) {
                    maze->directions[k] = 0;
                }

                int direction = rand() % MAX_DIRECTIONS;
                if (direction == 0) {
                    for (j = 0; j < maze->cols; j++) {
                        if (newMaze[i][j].direction == 0) {
                            maze->directions[direction] = 1;
                            maze->maze[i][j].direction = direction;
                            maze->maze[i][j].row = i;
                            maze->maze[i][j].col = j;
                        }
                    }
                } else if (direction == 1) {
                    for (j = 0; j < maze->cols; j++) {
                        if (newMaze[i][j].direction == 0) {
                            maze->directions[direction] = 1;
                            maze->maze[i][j].direction = direction;
                            maze->maze[i][j].row = i;
                            maze->maze[i][j].col = j;
                        }
                    }
                } else if (direction == 2) {
                    for (j = 0; j < maze->cols; j++) {
                        if (newMaze[i][j].direction == 0) {
                            maze->directions[direction] = 1;
                            maze->maze[i][j].direction = direction;
                            maze->maze[i][j].row = i;
                            maze->maze[i][j].col = j;
                        }
                    }
                } else {
                    for (j = 0; j < maze->cols; j++) {
                        if (newMaze[i][j].direction == 0) {
                            maze->directions[direction] = 1;
                            maze->maze[i][j].direction = direction;
                            maze->maze[i][j].row = i;
                            maze->maze[i][j].col = j;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    Maze maze;
    maze.rows = MAX_ROWS;
    maze.cols = MAX_COLS;
    maze.directions[0] = 1;
    maze.directions[1] = 1;
    maze.directions[2] = 1;

    generateMaze(&maze);

    printMaze(&maze);

    return 0;
}