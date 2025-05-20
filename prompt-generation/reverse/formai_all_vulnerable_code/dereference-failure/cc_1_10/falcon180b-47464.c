//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

void generateMaze(char maze[HEIGHT][WIDTH]);
void printMaze(char maze[HEIGHT][WIDTH]);

int main() {
    srand(time(NULL));
    char maze[HEIGHT][WIDTH];

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[HEIGHT][WIDTH]) {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            maze[y][x] = rand() % 2? '.' : '#';
        }
    }

    int startX = rand() % WIDTH;
    int startY = rand() % HEIGHT;

    maze[startY][startX] = 'S';
    maze[startY - 1][startX] = '.';

    int endX = rand() % WIDTH;
    int endY = rand() % HEIGHT;

    maze[endY][endX] = 'E';
    maze[endY - 1][endX] = '.';
}

void printMaze(char maze[HEIGHT][WIDTH]) {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}