//MISTRAL-7B DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x, y;
} Point;

bool isValid(Point p, int **maze) {
    if (p.x < 0 || p.x >= WIDTH || p.y < 0 || p.y >= HEIGHT)
        return false;
    if (maze[p.y][p.x] == 1)
        return false;
    return true;
}

void dfs(Point start, Point end, int **maze, bool **visited) {
    visited[start.y][start.x] = true;

    if (start.x == end.x && start.y == end.y) {
        printf("Path found: %d %d\n", start.x, start.y);
        exit(0);
    }

    Point next;

    for (int dx = -2; dx <= 2; ++dx) {
        for (int dy = -2; dy <= 2; ++dy) {
            if (dx == 0 && dy == 0)
                continue;

            next.x = start.x + dx;
            next.y = start.y + dy;

            if (isValid(next, maze) && !visited[next.y][next.x]) {
                maze[start.y][start.x] = 2;
                dfs(next, end, maze, visited);
            }
        }
    }

    visited[start.y][start.x] = false;
    maze[start.y][start.x] = 0;
}

int main() {
    int **maze = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; ++i)
        maze[i] = calloc(WIDTH, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            maze[i][j] = rand() % 3;
            if (maze[i][j] == 0) {
                maze[i][j] = 1;
                maze[i + 1][j] = 1;
            }
        }
    }

    Point start = {2, 2}, end = {19, 9};

    bool **visited = calloc(HEIGHT, sizeof(bool *));
    for (int i = 0; i < HEIGHT; ++i)
        visited[i] = calloc(WIDTH, sizeof(bool));

    dfs(start, end, maze, visited);

    for (int i = 0; i < HEIGHT; ++i) {
        free(visited[i]);
    }
    free(visited);

    free(maze);

    printf("Could not find a path.\n");

    return 0;
}