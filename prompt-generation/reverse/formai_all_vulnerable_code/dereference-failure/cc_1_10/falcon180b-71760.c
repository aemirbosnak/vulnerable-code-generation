//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x, y;
} Point;

void generateMaze(char maze[HEIGHT][WIDTH]);
void printMaze(const char maze[HEIGHT][WIDTH]);
int isValidMove(const char maze[HEIGHT][WIDTH], int x, int y, int dx, int dy);
void carvePath(char maze[HEIGHT][WIDTH], int x, int y, int dx, int dy);

int main() {
    srand(time(NULL));

    char maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    int startX = rand() % WIDTH | 1;
    int startY = rand() % HEIGHT | 1;
    maze[startY][startX] = 'S';

    carvePath(maze, startX, startY, 0, -1);
}

void printMaze(const char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(const char maze[HEIGHT][WIDTH], int x, int y, int dx, int dy) {
    if (x < 1 || x >= WIDTH - 1 || y < 1 || y >= HEIGHT - 1) {
        return 0;
    }

    if (maze[y + dy][x + dx] == '#') {
        return 0;
    }

    return 1;
}

void carvePath(char maze[HEIGHT][WIDTH], int x, int y, int dx, int dy) {
    maze[y][x] = '.';

    while (isValidMove(maze, x, y, dx, dy)) {
        x += dx;
        y += dy;
        maze[y][x] = '.';
    }
}