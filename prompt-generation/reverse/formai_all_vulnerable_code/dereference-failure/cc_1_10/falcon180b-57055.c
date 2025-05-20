//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(char maze[HEIGHT][WIDTH]) {
    int startX = rand() % WIDTH | 1;
    int startY = rand() % HEIGHT | 1;
    maze[startY][startX] = 'S';

    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int numDirections = rand() % 4 + 1;

    for (int i = 0; i < numDirections; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];

        int x = startX + dx;
        int y = startY + dy;

        while (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] == '#') {
            maze[y][x] = '.';
            x += dx;
            y += dy;
        }
    }
}

void printMaze(char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char maze[HEIGHT][WIDTH];
    generateMaze(maze);
    printMaze(maze);

    return 0;
}