//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x, y;
} Point;

bool is_valid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

void print_maze(bool maze[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            putchar(maze[j][i] ? ' ' : '#');
        }
        putchar('\n');
    }
}

void recursive_maze(bool maze[WIDTH][HEIGHT], int x, int y) {
    maze[x][y] = true;

    int dx[4] = {-2, 2, 2, -2};
    int dy[4] = {-2, -2, 2, 2};

    int index = 0;
    for (; index < 4; ++index) {
        int nx = x + dx[index], ny = y + dy[index];
        if (is_valid(nx, ny) && !maze[nx][ny]) {
            maze[nx][ny] = true;
            recursive_maze(maze, nx, ny);
            break;
        }
    }

    if (index == 4) {
        int backx = x, backy = y;
        for (int i = 1; i < 4; ++i) {
            int dx1 = dx[i - 1], dy1 = dy[i - 1];
            x -= dx1 >> 1;
            y -= dy1 >> 1;
            maze[x][y] = false;
        }
        maze[backx][backy] = false;
    }
}

int main() {
    srand(time(NULL));

    bool maze[WIDTH][HEIGHT] = {false};

    int x = rand() % WIDTH, y = rand() % HEIGHT;
    recursive_maze(maze, x, y);

    print_maze(maze);

    return 0;
}