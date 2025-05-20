//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define VISITED '.'

typedef struct {
    int x, y;
} Cell;

void initializeMaze(char*** maze, int width, int height) {
    *maze = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        (*maze)[i] = (char*)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            (*maze)[i][j] = WALL;
        }
    }
}

void freeMaze(char** maze, int height) {
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
}

void printMaze(char** maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(maze[i][j]);
        }
        putchar('\n');
    }
}

int isValidMove(int x, int y, int width, int height) {
    return (x >= 0 && x < width && y >= 0 && y < height);
}

void generateMaze(char** maze, int x, int y, int width, int height) {
    int dir[4][2] = { {0, 2}, {2, 0}, {0, -2}, {-2, 0} };
    maze[y][x] = PATH;

    for (int i = 0; i < 4; i++) {
        int randDir = rand() % 4;
        int nx = x + dir[randDir][0];
        int ny = y + dir[randDir][1];

        if (isValidMove(nx, ny, width, height) && maze[ny][nx] == WALL) {
            maze[y + dir[randDir][1] / 2][x + dir[randDir][0] / 2] = PATH;
            generateMaze(maze, nx, ny, width, height);
        }
    }
}

int main() {
    srand(time(NULL));

    int width, height;

    printf("Enter maze width (odd number): ");
    scanf("%d", &width);
    printf("Enter maze height (odd number): ");
    scanf("%d", &height);

    if (width % 2 == 0 || height % 2 == 0 || width < 5 || height < 5) {
        printf("Please enter odd dimensions greater than 5.\n");
        return 1;
    }

    char** maze;
    initializeMaze(&maze, width, height);

    // Start generating the maze from (1, 1) to avoid walls at the edges
    generateMaze(maze, 1, 1, width, height);

    printMaze(maze, width, height);

    freeMaze(maze, height);

    return 0;
}