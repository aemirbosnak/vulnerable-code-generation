//MISTRAL-7B DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 21
#define HEIGHT 21
#define START_X 1
#define START_Y 1
#define END_X WIDTH - 2
#define END_Y HEIGHT - 2

typedef struct {
    int x;
    int y;
} Point;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void dfs(int **maze, int **visited, int x, int y, int *path_x, int *path_y) {
    visited[x][y] = 1;
    if (x == END_X && y == END_Y) {
        *path_x = x;
        *path_y = y;
        return;
    }

    int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && maze[nx][ny] == 0 && visited[nx][ny] == 0) {
            dfs(maze, visited, nx, ny, path_x, path_y);
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = calloc(HEIGHT, sizeof(int *));
    for (int i = 0; i < HEIGHT; ++i) {
        maze[i] = calloc(WIDTH, sizeof(int));
    }

    // Fill the maze with walls randomly
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            maze[i][j] = rand() % 2;
        }
    }

    int **visited = calloc(HEIGHT, sizeof(int *));
    for (int i = 0; i < HEIGHT; ++i) {
        visited[i] = calloc(WIDTH, sizeof(int));
    }

    int path_x = 0;
    int path_y = 0;

    dfs(maze, visited, START_X, START_Y, &path_x, &path_y);

    print_maze(maze);
    printf("Solution: (%d, %d)\n", path_x, path_y);

    for (int i = 0; i < HEIGHT; ++i) {
        free(maze[i]);
    }
    free(maze);

    for (int i = 0; i < HEIGHT; ++i) {
        free(visited[i]);
    }
    free(visited);

    return 0;
}