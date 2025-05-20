//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    int x, y;
} Position;

void generate_maze(char maze[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void print_maze(const char maze[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void solve_maze(char maze[HEIGHT][WIDTH], Position start, Position end) {
    int stack[HEIGHT][WIDTH];
    int x = start.x, y = start.y, dx = 0, dy = 0;
    int path_count = 0;
    int stack_top = 0;

    stack[0][0] = 1;

    while (path_count < WIDTH * HEIGHT) {
        if (dx == 0 && dy == 0) {
            int directions = 0;

            if (maze[y - 1][x] == '.') {
                directions |= UP;
            }
            if (maze[y + 1][x] == '.') {
                directions |= DOWN;
            }
            if (maze[y][x - 1] == '.') {
                directions |= LEFT;
            }
            if (maze[y][x + 1] == '.') {
                directions |= RIGHT;
            }

            if (directions == 0) {
                return;
            }

            int r = rand() % 4;
            switch (r) {
                case 0:
                    dx = 0;
                    dy = 1;
                    break;
                case 1:
                    dx = 0;
                    dy = -1;
                    break;
                case 2:
                    dx = 1;
                    dy = 0;
                    break;
                case 3:
                    dx = -1;
                    dy = 0;
                    break;
            }
        }

        x += dx;
        y += dy;
        path_count++;

        if (maze[y][x] == '.') {
            continue;
        }

        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            continue;
        }

        if (stack[y][x]) {
            continue;
        }

        stack[stack_top][0] = x;
        stack[stack_top][1] = y;
        stack_top++;
        stack[y][x] = 1;
    }
}

int main() {
    srand(time(NULL));
    char maze[HEIGHT][WIDTH];
    generate_maze(maze);
    print_maze(maze);

    Position start = {0, rand() % HEIGHT};
    Position end = {WIDTH - 1, rand() % HEIGHT};

    solve_maze(maze, start, end);

    return 0;
}