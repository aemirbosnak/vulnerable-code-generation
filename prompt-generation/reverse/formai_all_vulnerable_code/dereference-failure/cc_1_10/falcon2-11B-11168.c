//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int width;
    int height;
    int **maze;
} Maze;

void generate_maze(Maze *maze);
void print_maze(Maze maze);

int main() {
    Maze maze;
    srand(time(NULL));

    maze.width = 20;
    maze.height = 20;

    generate_maze(&maze);
    print_maze(maze);

    return 0;
}

void generate_maze(Maze *maze) {
    maze->maze = malloc(maze->height * sizeof(int *));

    for (int i = 0; i < maze->height; i++) {
        maze->maze[i] = malloc(maze->width * sizeof(int));

        for (int j = 0; j < maze->width; j++) {
            maze->maze[i][j] = 1;
        }
    }

    int x, y;
    int dirs[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int num_dirs = sizeof(dirs) / sizeof(dirs[0]);

    for (int i = 0; i < num_dirs; i++) {
        int dx = dirs[i] % maze->width;
        int dy = dirs[i] / maze->width;

        x = rand() % maze->width;
        y = rand() % maze->height;

        maze->maze[y][x] = 0;

        for (int j = 0; j < num_dirs; j++) {
            int next_x = x + dx;
            int next_y = y + dy;

            if (next_x < 0 || next_x >= maze->width || next_y < 0 || next_y >= maze->height) {
                continue;
            }

            maze->maze[next_y][next_x] = 0;
        }
    }
}

void print_maze(Maze maze) {
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            if (maze.maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}