//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void generateMaze(char maze[101][101], int startX, int startY) {
    int width = 100;
    int height = 100;
    int numWalls = 0;
    int x = startX, y = startY;

    srand(time(NULL));

    while (numWalls < 500) {
        int dir = rand() % 4;
        switch (dir) {
            case 0:
                if (x > 0 && maze[x - 1][y] == 0) {
                    maze[x - 1][y] = 1;
                    maze[x][y] = 1;
                    numWalls++;
                }
                break;
            case 1:
                if (y < height - 1 && maze[x][y + 1] == 0) {
                    maze[x][y + 1] = 1;
                    maze[x][y] = 1;
                    numWalls++;
                }
                break;
            case 2:
                if (x < width - 1 && maze[x + 1][y] == 0) {
                    maze[x + 1][y] = 1;
                    maze[x][y] = 1;
                    numWalls++;
                }
                break;
            case 3:
                if (y > 0 && maze[x][y - 1] == 0) {
                    maze[x][y - 1] = 1;
                    maze[x][y] = 1;
                    numWalls++;
                }
                break;
        }

        if (numWalls < 500) {
            x += rand() % 2 - 1;
            y += rand() % 2 - 1;
        }
    }

    maze[startX][startY] = 0;
}

void printMaze(char maze[101][101]) {
    int i, j;

    for (i = 0; i < 101; i++) {
        for (j = 0; j < 101; j++) {
            if (maze[i][j] == 1) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    int width = 100, height = 100;
    char maze[101][101];

    srand(time(NULL));

    generateMaze(maze, rand() % width, rand() % height);

    printMaze(maze);

    return 0;
}