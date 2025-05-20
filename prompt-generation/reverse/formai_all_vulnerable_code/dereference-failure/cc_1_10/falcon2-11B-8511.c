//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cell {
    int x;
    int y;
};

struct maze {
    int size;
    struct cell **cells;
};

struct maze generateMaze(int size) {
    struct maze maze;
    maze.size = size;
    maze.cells = malloc(size * size * sizeof(struct cell*));
    for (int i = 0; i < size; i++) {
        maze.cells[i] = malloc(size * sizeof(struct cell));
    }
    return maze;
}

void printMaze(struct maze maze) {
    for (int i = 0; i < maze.size; i++) {
        for (int j = 0; j < maze.size; j++) {
            printf("%d ", maze.cells[i][j].x + 1);
        }
        printf("\n");
    }
}

void clearMaze(struct maze maze) {
    for (int i = 0; i < maze.size; i++) {
        for (int j = 0; j < maze.size; j++) {
            maze.cells[i][j].x = 0;
        }
    }
}

int isWall(struct maze maze, int x, int y) {
    return maze.cells[x][y].x == 1;
}

void placeWall(struct maze maze, int x, int y) {
    maze.cells[x][y].x = 1;
}

void removeWall(struct maze maze, int x, int y) {
    maze.cells[x][y].x = 0;
}

void connect(struct maze maze, int x1, int y1, int x2, int y2) {
    if (isWall(maze, x1, y1) && isWall(maze, x2, y2)) {
        placeWall(maze, x1, y1);
        placeWall(maze, x2, y2);
    }
}

void recurse(struct maze maze, int x, int y) {
    int size = maze.size;
    int i, j;
    if (x < 0 || y < 0 || x >= size || y >= size || isWall(maze, x, y)) {
        return;
    }
    if (maze.cells[x][y].x == 1) {
        return;
    }
    maze.cells[x][y].x = 1;
    recurse(maze, x + 1, y);
    recurse(maze, x - 1, y);
    recurse(maze, x, y + 1);
    recurse(maze, x, y - 1);
    connect(maze, x, y, x + 1, y);
    connect(maze, x, y, x - 1, y);
    connect(maze, x, y, x, y + 1);
    connect(maze, x, y, x, y - 1);
}

void printMazeAndPath(struct maze maze, int x1, int y1, int x2, int y2) {
    clearMaze(maze);
    recurse(maze, x1, y1);
    printMaze(maze);
    printf("Path from (%d, %d) to (%d, %d):\n", x1, y1, x2, y2);
    for (int i = 0; i < maze.size; i++) {
        for (int j = 0; j < maze.size; j++) {
            printf("%d ", maze.cells[i][j].x + 1);
        }
        printf("\n");
    }
}

int main() {
    struct maze maze = generateMaze(5);
    printMaze(maze);
    printf("\n");
    printMazeAndPath(maze, 0, 0, 3, 3);
    return 0;
}