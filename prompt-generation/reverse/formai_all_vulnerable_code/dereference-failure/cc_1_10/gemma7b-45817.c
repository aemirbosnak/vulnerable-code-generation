//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'

void generateMaze(int **maze, int w, int h) {
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            maze[y][x] = EMPTY_CHAR;
        }
    }

    int numWalls = rand() % (w * h);

    for (int i = 0; i < numWalls; i++) {
        int x = rand() % w;
        int y = rand() % h;

        maze[y][x] = WALL_CHAR;
    }

    maze[0][0] = WALL_CHAR;
    maze[0][w - 1] = WALL_CHAR;
    maze[h - 1][w - 1] = WALL_CHAR;
    maze[h - 1][0] = WALL_CHAR;
}

int main() {
    int **maze = NULL;

    maze = (int**)malloc(MAZE_HEIGHT * sizeof(int*));
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        maze[i] = (int*)malloc(MAZE_WIDTH * sizeof(int));
    }

    generateMaze(maze, MAZE_WIDTH, MAZE_HEIGHT);

    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("%c ", maze[y][x]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}