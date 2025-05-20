//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

typedef struct {
    int width;
    int height;
    char **grid;
} Maze;

void initializeMaze(Maze *maze, int width, int height) {
    maze->width = width;
    maze->height = height;
    maze->grid = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = (char*)malloc(width * sizeof(char));
    }
}

void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
}

void generateMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (i % 2 == 1 && j % 2 == 1) {
                maze->grid[i][j] = PATH;
            } else {
                maze->grid[i][j] = WALL;
            }
        }
    }

    for (int i = 1; i < maze->height - 1; i += 2) {
        for (int j = 1; j < maze->width - 1; j += 2) {
            int direction = rand() % 4;
            if (direction == 0 && i > 1) { // Up
                maze->grid[i-1][j] = PATH;
            } else if (direction == 1 && j < maze->width - 2) { // Right
                maze->grid[i][j+1] = PATH;
            } else if (direction == 2 && i < maze->height - 2) { // Down
                maze->grid[i+1][j] = PATH;
            } else if (direction == 3 && j > 1) { // Left
                maze->grid[i][j-1] = PATH;
            }
        }
    }
}

void setStartAndEnd(Maze *maze) {
    maze->grid[1][0] = START; // Starting point at (1, 0)
    maze->grid[maze->height - 2][maze->width - 1] = END; // Endpoint at bottom right
}

void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int width = 21;  // Must be odd
    int height = 21; // Must be odd

    Maze maze;
    initializeMaze(&maze, width, height);
    generateMaze(&maze);
    setStartAndEnd(&maze);
    printMaze(&maze);

    freeMaze(&maze);
    return 0;
}