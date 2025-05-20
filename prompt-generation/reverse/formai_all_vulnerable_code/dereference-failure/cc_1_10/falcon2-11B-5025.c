//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int height;
    int width;
    int** maze;
} Maze;

Maze* createMaze(int height, int width) {
    Maze* maze = (Maze*) malloc(sizeof(Maze));
    maze->height = height;
    maze->width = width;
    maze->maze = (int**) malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze->maze[i] = (int*) malloc(width * sizeof(int));
    }
    return maze;
}

void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

void printMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%3d", maze->maze[i][j]);
        }
        printf("\n");
    }
}

int isWall(Maze* maze, int x, int y) {
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return 1;
    }
    return maze->maze[y][x];
}

int* getRandomPath(Maze* maze) {
    int** mazeCopy = (int**) malloc(maze->height * sizeof(int*));
    for (int i = 0; i < maze->height; i++) {
        mazeCopy[i] = (int*) malloc(maze->width * sizeof(int));
    }
    memcpy(mazeCopy, maze->maze, maze->height * maze->width * sizeof(int));

    int startX = rand() % maze->width;
    int startY = rand() % maze->height;
    int endX = rand() % maze->width;
    int endY = rand() % maze->height;

    int* path = (int*) malloc(sizeof(int) * (maze->height + 1));
    path[0] = startX;
    path[1] = startY;
    mazeCopy[startY][startX] = 0;

    for (int i = 2; i <= maze->height; i++) {
        int currentX = path[i - 2];
        int currentY = path[i - 1];

        if (isWall(maze, currentX, currentY - 1) && isWall(maze, currentX, currentY + 1)) {
            path[i] = currentX;
            break;
        }

        if (isWall(maze, currentX - 1, currentY) && isWall(maze, currentX + 1, currentY)) {
            path[i] = currentX;
            break;
        }

        int nextX = currentX;
        int nextY = currentY - 1;

        if (isWall(maze, currentX, currentY + 1) &&!isWall(maze, nextX, nextY)) {
            nextX = currentX;
            nextY = currentY + 1;
        }

        if (isWall(maze, currentX - 1, currentY) &&!isWall(maze, nextX, nextY)) {
            nextX = currentX - 1;
            nextY = currentY;
        }

        if (isWall(maze, currentX + 1, currentY) &&!isWall(maze, nextX, nextY)) {
            nextX = currentX + 1;
            nextY = currentY;
        }

        if (isWall(maze, nextX, nextY)) {
            path[i] = currentX;
            break;
        }

        mazeCopy[nextY][nextX] = 0;
        path[i] = nextX;
    }

    free(mazeCopy);
    return path;
}

int main() {
    srand(time(0));
    int height = 10;
    int width = 10;
    Maze* maze = createMaze(height, width);
    int* path = getRandomPath(maze);
    printf("Path: ");
    for (int i = 0; i < maze->height; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    printMaze(maze);
    freeMaze(maze);
    return 0;
}