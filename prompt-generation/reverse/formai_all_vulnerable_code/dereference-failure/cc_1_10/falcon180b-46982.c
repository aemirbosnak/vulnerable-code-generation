//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x, y;
} Point;

void generateMaze(char maze[HEIGHT][WIDTH]) {
    int startX = rand() % WIDTH | 1;
    int startY = rand() % HEIGHT | 1;

    maze[startY][startX] = 'S';

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int currentDirection = rand() % 4;

    Point current = {startX, startY};

    while (1) {
        int nextX = current.x + directions[currentDirection][0];
        int nextY = current.y + directions[currentDirection][1];

        if (nextX < 0 || nextX >= WIDTH || nextY < 0 || nextY >= HEIGHT) {
            currentDirection = (currentDirection + 1) % 4;
            continue;
        }

        if (maze[nextY][nextX] == '#') {
            currentDirection = (currentDirection + 1) % 4;
            continue;
        }

        maze[nextY][nextX] = '.';
        current.x = nextX;
        current.y = nextY;
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