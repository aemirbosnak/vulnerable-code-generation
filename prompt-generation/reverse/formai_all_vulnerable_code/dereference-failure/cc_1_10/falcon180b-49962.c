//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define WALL '#'
#define PATH''
#define START 'S'
#define END 'E'

void generateMaze(char maze[HEIGHT][WIDTH]);
void printMaze(const char maze[HEIGHT][WIDTH]);
int isValid(int x, int y);

int main() {
    srand(time(NULL));
    char maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}

void generateMaze(char maze[HEIGHT][WIDTH]) {
    int x, y;
    for (y = 0; y < HEIGHT; ++y) {
        for (x = 0; x < WIDTH; ++x) {
            maze[y][x] = WALL;
        }
    }
    maze[0][0] = START;
    maze[HEIGHT - 1][WIDTH - 1] = END;
    int count = 0;
    while (count < 100) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;
        if (dx == 0 && dy == 0)
            continue;
        int nx = (x + dx + WIDTH) % WIDTH;
        int ny = (y + dy + HEIGHT) % HEIGHT;
        if (isValid(nx, ny)) {
            maze[y][x] |= (1 << (4 - dx + 8 - dy));
            maze[ny][nx] |= (1 << (4 - dy + 8 - dx));
            ++count;
        }
    }
}

void printMaze(const char maze[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

int isValid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}