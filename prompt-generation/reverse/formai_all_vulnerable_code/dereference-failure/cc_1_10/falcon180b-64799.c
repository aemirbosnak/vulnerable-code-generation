//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
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

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int count = 0;

        while (count < 10) {
            int nx = startX + dx * count;
            int ny = startY + dy * count;

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[ny][nx] == '#') {
                maze[ny][nx] = '.';
                count++;
            } else {
                break;
            }
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

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = '#';
        }
    }

    generateMaze(maze);

    printMaze(maze);

    return 0;
}