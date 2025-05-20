//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 31
#define HEIGHT 21
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} point;

void maze_generate(int **maze, int width, int height) {
    bool visited[width][height];
    point stack[WIDTH * HEIGHT];
    int top = 0;

    maze[0][0] = PATH;
    point start = {.x = 0, .y = 0};
    stack[top++] = start;
    visited[start.x][start.y] = true;

    while (top > 0) {
        int x = stack[top - 1].x;
        int y = stack[top - 1].y;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[nx][ny] && maze[nx][ny] == WALL) {
                maze[x + dx[i]][y + dy[i]] = PATH;
                maze[nx][ny] = PATH;
                point current = {.x = nx, .y = ny};
                stack[top++] = current;
                visited[nx][ny] = true;
            }
        }

        maze[x][y] = PATH;
        stack[top - 1].x = stack[top - 2].x;
        stack[top - 1].y = stack[top - 2].y;
        top--;
    }
}

void print_maze(int *maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf(maze[i * WIDTH + j] == WALL ? "##" : "  ");
        }
        printf("\n");
    }
}

int main() {
    int width = WIDTH;
    int height = HEIGHT;

    int *maze = malloc(sizeof(int) * width * height);

    srand(time(NULL));

    maze_generate(maze, width, height);
    print_maze(maze, width, height);

    free(maze);

    return 0;
}