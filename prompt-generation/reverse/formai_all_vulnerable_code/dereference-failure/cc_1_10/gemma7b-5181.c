//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

void generate_maze(int **maze, int w, int h) {
    int x, y;
    srand(time(NULL));

    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            maze[x][y] = EMPTY_CHAR + rand() % 2;
        }
    }

    maze[0][0] = PLAYER_CHAR;

    // Add a few random walls
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (maze[x][y] == EMPTY_CHAR) {
                maze[x][y] = WALL_CHAR;
            }
        }
    }
}

int main() {
    int **maze;
    int w, h;

    w = MAZE_WIDTH;
    h = MAZE_HEIGHT;

    maze = (int **)malloc(w * sizeof(int *) + h * sizeof(int));
    for (int i = 0; i < w; i++) {
        maze[i] = (int *)malloc(h * sizeof(int));
    }

    generate_maze(maze, w, h);

    // Print the maze
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            printf("%c ", maze[x][y]);
        }
        printf("\n");
    }

    free(maze);

    return 0;
}