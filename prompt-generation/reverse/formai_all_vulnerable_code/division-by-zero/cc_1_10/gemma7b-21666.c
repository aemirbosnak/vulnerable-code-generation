//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20

#define WALL 1
#define EMPTY 0

void createMaze(int **maze, int w, int h) {
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            maze[r][c] = EMPTY;
        }
    }

    // Randomly generate walls
    for (int i = 0; i < 50; i++) {
        int r = rand() % h;
        int c = rand() % w;
        maze[r][c] = WALL;
    }
}

void drawMaze(int **maze, int w, int h) {
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (maze[r][c] == WALL) {
                printf("%c", '#');
            } else {
                printf("%c", '.');
            }
        }
        printf("\n");
    }
}

int main() {
    int **maze = NULL;
    int w, h;

    printf("Enter the width of the maze: ");
    scanf("%d", &w);

    printf("Enter the height of the maze: ");
    scanf("%d", &h);

    maze = (int **)malloc(h * sizeof(int *) + h);
    for (int i = 0; i < h; i++) {
        maze[i] = (int *)malloc(w * sizeof(int) + w);
    }

    createMaze(maze, w, h);

    drawMaze(maze, w, h);

    return 0;
}