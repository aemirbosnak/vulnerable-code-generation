//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} point;

void print_maze(int **maze) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : "  ");
        printf("\n");
    }
}

void random_walk(int **maze, int *visited, point *start) {
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, r;
    point current = *start;

    while (maze[current.y][current.x] != WALL) {
        maze[current.y][current.x] = PATH;
        visited[current.y * WIDTH + current.x] = 1;

        r = rand() % 4;
        current.x += dx[r], current.y += dy[r];
    }
}

void generate_maze(int **maze, int *visited) {
    int i, j, x, y;
    point start = {1, 1};

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            maze[i][j] = WALL;
        maze[i][j] = PATH;
        visited[i * WIDTH + j] = 1;
    }

    random_walk(maze, visited, &start);
}

int main() {
    int i, j, *visited, **maze;

    srand(time(NULL));

    maze = malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    visited = calloc(WIDTH * HEIGHT, sizeof(int));

    generate_maze(maze, visited);

    print_maze(maze);

    free(visited);
    for (i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    return 0;
}