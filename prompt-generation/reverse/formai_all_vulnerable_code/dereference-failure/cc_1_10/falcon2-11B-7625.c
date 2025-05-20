//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    int **grid;
} maze_t;

void initialize_maze(maze_t *maze) {
    maze->width = 10;
    maze->height = 10;
    maze->grid = (int **)malloc(maze->height * sizeof(int *));
    for (int i = 0; i < maze->height; i++) {
        maze->grid[i] = (int *)malloc(maze->width * sizeof(int));
        for (int j = 0; j < maze->width; j++) {
            maze->grid[i][j] = 0;
        }
    }
}

void display_maze(maze_t maze) {
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            printf("%d ", maze.grid[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(maze_t *maze) {
    srand(time(NULL));
    int width = maze->width;
    int height = maze->height;
    int i, j;

    // Fill in the first row
    for (i = 0; i < width; i++) {
        maze->grid[0][i] = 1;
    }

    // Fill in the first column
    for (j = 0; j < height; j++) {
        maze->grid[j][0] = 1;
    }

    // Fill in the rest of the maze
    for (i = 1; i < height; i++) {
        for (j = 1; j < width; j++) {
            // If it's a wall, don't change it
            if (maze->grid[i - 1][j] == 1 || maze->grid[i][j - 1] == 1 ||
                    maze->grid[i - 1][j - 1] == 1) {
                maze->grid[i][j] = 1;
            }
        }
    }

    // Fill in the rest of the walls
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (maze->grid[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int new_i = i + (rand() % 2 == 0? 1 : -1);
                    int new_j = j + (rand() % 2 == 0? 1 : -1);
                    if (new_i >= 0 && new_i < height &&
                            new_j >= 0 && new_j < width &&
                            maze->grid[new_i][new_j] == 0) {
                        maze->grid[i][j] = 1;
                        maze->grid[new_i][new_j] = 1;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    maze_t maze;
    initialize_maze(&maze);
    generate_maze(&maze);
    display_maze(maze);
    return 0;
}