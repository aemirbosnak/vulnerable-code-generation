//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

typedef struct {
    int x, y;
} point;

void dfs(int** maze, int x, int y, int* visited) {
    point p[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    visited[x * WIDTH + y] = 1;
    maze[x][y] = 0;

    for (int i = 0; i < 4; ++i) {
        int nx = x + p[i].x;
        int ny = y + p[i].y;

        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH &&
            maze[nx][ny] && !visited[nx * WIDTH + ny]) {
            dfs(maze, nx, ny, visited);
        }
    }
}

int main() {
    srand(time(NULL));
    int** maze = malloc(HEIGHT * sizeof(int*));
    for (int i = 0; i < HEIGHT; ++i)
        maze[i] = calloc(WIDTH, sizeof(int));

    point start = {rand() % HEIGHT, rand() % WIDTH};
    int* visited = calloc(HEIGHT * WIDTH, sizeof(int));

    maze[start.y][start.x] = 1;
    visited[start.y * WIDTH + start.x] = 1;

    dfs(maze, start.y, start.x, visited);

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            putchar(maze[i][j] ? '#' : ' ');
        }
        putchar('\n');
    }

    free(visited);
    for (int i = 0; i < HEIGHT; ++i)
        free(maze[i]);
    free(maze);

    return 0;
}