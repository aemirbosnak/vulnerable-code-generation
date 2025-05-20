//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define MAX_ATTEMPTS 100

typedef struct {
    int x, y;
} Point;

void generateMaze(char maze[HEIGHT][WIDTH]) {
    int startX = rand() % WIDTH | 1;
    int startY = rand() % HEIGHT | 1;

    maze[startY][startX] = 'S';

    int attempts = 0;

    while (attempts < MAX_ATTEMPTS) {
        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        int newX = startX + dx;
        int newY = startY + dy;

        if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && maze[newY][newX] == '#') {
            maze[newY][newX] = '.';
            maze[startY][startX] = '.';

            startX = newX;
            startY = newY;

            attempts = 0;
        } else {
            attempts++;
        }
    }

    maze[startY][startX] = 'S';
}

void printMaze(char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
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