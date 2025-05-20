//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define WIDTH 21
#define HEIGHT 21

typedef struct {
    int x, y;
} Point;

bool is_valid(int x, int y, int **maze) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return false;
    if (maze[y][x] == -1) return false;
    return true;
}

void carve(int x, int y, int **maze) {
    maze[y][x] = 0;

    for (int dx = -2; dx <= 2; ++dx) {
        for (int dy = -2; dy <= 2; ++dy) {
            if (dx != 0 || dy != 0) {
                int nx = x + dx, ny = y + dy;
                if (is_valid(nx, ny, maze)) {
                    maze[ny][nx] = -2;
                    carve(nx, ny, maze);
                }
            }
        }
    }
}

void print_maze(int **maze) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (maze[y][x] == -1) printf("##");
            else if (maze[y][x] == 0) printf("   ");
            else printf("%3d", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(HEIGHT * sizeof(int *));
    for (int y = 0; y < HEIGHT; ++y) {
        maze[y] = calloc(WIDTH, sizeof(int));
        for (int x = 0; x < WIDTH; ++x) maze[y][x] = -1;
    }

    int start_x = rand() % WIDTH, start_y = rand() % HEIGHT;
    maze[start_y][start_x] = 0;

    carve(start_x, start_y, maze);

    print_maze(maze);

    for (int y = 0; y < HEIGHT; ++y) free(maze[y]);
    free(maze);

    return 0;
}