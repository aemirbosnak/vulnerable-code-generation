//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 0
#define ROOM 1
#define CORRIDOR 2

#define MAX_X 100
#define MAX_Y 100

typedef struct {
    int x;
    int y;
    int type;
} Cell;

Cell** create_maze(int height, int width) {
    Cell** maze = malloc(height * sizeof(Cell*));
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(width * sizeof(Cell));
        for (int j = 0; j < width; j++) {
            maze[i][j].x = j;
            maze[i][j].y = i;
            maze[i][j].type = WALL;
        }
    }
    return maze;
}

void print_maze(Cell** maze, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j].type);
        }
        printf("\n");
    }
}

int main() {
    int height = 10;
    int width = 10;
    srand(time(NULL));
    Cell** maze = create_maze(height, width);

    // Add walls and rooms randomly
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (rand() % 2 == 0) {
                maze[i][j].type = WALL;
            } else {
                maze[i][j].type = ROOM;
            }
        }
    }

    // Connect adjacent rooms
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j].type == ROOM) {
                if (maze[i][j + 1].type == WALL || maze[i][j - 1].type == WALL || maze[i + 1][j].type == WALL || maze[i - 1][j].type == WALL) {
                    maze[i][j].type = CORRIDOR;
                }
            }
        }
    }

    // Print the maze
    print_maze(maze, height, width);

    free(maze);
    return 0;
}