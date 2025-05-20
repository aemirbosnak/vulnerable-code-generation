//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x;
    int y;
} Point;

void init_maze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
}

void print_maze(const char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(const char maze[ROWS][COLS], int x, int y, int dx, int dy) {
    if (dx == 0 && dy == 0) {
        return 1;
    }
    if (dx == 0) {
        return maze[x][y - 1] == '.';
    }
    if (dy == 0) {
        return maze[x - 1][y] == '.';
    }
    if (dx == dy) {
        return (maze[x][y - 1] == '.' && maze[x - 1][y] == '.') ||
               (maze[x][y - 1] == '#' && maze[x - 1][y] == '#');
    }
    return 0;
}

void find_route(const char maze[ROWS][COLS], Point start, Point end) {
    int x = start.x;
    int y = start.y;
    int dx = end.x - x;
    int dy = end.y - y;

    while (is_valid_move(maze, x, y, dx, dy)) {
        if (dx == 0 && dy == 0) {
            printf("Found route!\n");
            return;
        }
        if (dx == 0) {
            y--;
        }
        if (dy == 0) {
            x--;
        }
        if (dx == dy) {
            x--;
            y--;
        }
    }
    printf("No route found.\n");
}

int main() {
    char maze[ROWS][COLS];
    init_maze(maze);

    Point start = {0, 0};
    Point end = {ROWS - 1, COLS - 1};

    print_maze(maze);

    find_route(maze, start, end);

    return 0;
}