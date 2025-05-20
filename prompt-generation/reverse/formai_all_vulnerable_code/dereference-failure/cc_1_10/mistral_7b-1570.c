//MISTRAL-7B DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11
#define START 0
#define END 19
#define WALL 1
#define PATH 0
#define VISITED 2
#define SLEEP_MS 5

typedef struct { int x, y; } point;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : maze[i][j] == PATH ? "  " : " V");
        printf("\n");
    }
}

void dfs(int **maze, int x, int y, int *visited) {
    visited[x * WIDTH + y] = VISITED;
    maze[x][y] = PATH;

    for (int dx = -2; dx <= 2; dx += 2) {
        int nx = x + dx / 2, ny = y + dx % 2;
        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH &&
            maze[nx][ny] != WALL && visited[nx * WIDTH + ny] != VISITED)
            dfs(maze, nx, ny, visited);
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    point start = {START / WIDTH, START % WIDTH};
    point end = {END / WIDTH, END % WIDTH};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
                maze[i][j] = WALL;
            else
                maze[i][j] = rand() % 2;
        }
    }

    int *visited = calloc(WIDTH * HEIGHT, sizeof(int));

    dfs(maze, start.x, start.y, visited);

    printf("Maze solved:\n");
    print_maze(maze);

    free(visited);
    for (int i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    while (1)
        usleep(SLEEP_MS * 1000);

    return 0;
}