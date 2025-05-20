//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} pos_t;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf(maze[i][j] == WALL ? "##" : "  ");
        }
        printf("\n");
    }
}

void recursive_backtracking(int **maze, int x, int y, int visited[]) {
    pos_t neighbors[4];
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    visited[x * WIDTH + y] = PATH;

    for (int i = 0; i < 4; ++i) {
        neighbors[i].x = x + directions[i][0];
        neighbors[i].y = y + directions[i][1];

        if (maze[neighbors[i].x][neighbors[i].y] == WALL) {
            maze[neighbors[i].x][neighbors[i].y] = PATH;
            recursive_backtracking(maze, neighbors[i].x, neighbors[i].y, visited);
        }
    }
}

void generate_maze(int **maze) {
    srand(time(NULL));

    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            maze[i][j] = WALL;

    int visited[WIDTH * HEIGHT] = {0};

    maze[rand() % HEIGHT][rand() % WIDTH] = PATH;
    recursive_backtracking(maze, rand() % HEIGHT, rand() % WIDTH, visited);
}

int main() {
    int **maze = malloc(sizeof(int *) * HEIGHT);

    for (int i = 0; i < HEIGHT; ++i) {
        maze[i] = calloc(WIDTH, sizeof(int));
    }

    generate_maze(maze);
    print_maze(maze);

    for (int i = 0; i < HEIGHT; ++i)
        free(maze[i]);

    free(maze);

    return 0;
}