//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 21
#define HEIGHT 21

typedef struct {
    int x, y;
} point;

void generateMaze(int **maze, int x, int y, int visited[][WIDTH]);
void printMaze(int **maze, int width, int height);

int main() {
    srand(time(NULL));
    int maze[HEIGHT][WIDTH], visited[HEIGHT][WIDTH] = {0};
    generateMaze(maze, 0, 0, visited);
    printMaze(maze, WIDTH, HEIGHT);
    return 0;
}

void generateMaze(int **maze, int x, int y, int visited[][WIDTH]) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;
    maze[x][y] = 1;
    visited[x][y] = 1;
    stack[top++] = (point){x, y};

    while (top > 0) {
        int currX = stack[top - 1].x;
        int currY = stack[top - 1].y;

        int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++) {
            int nextX = currX + neighbors[i][0];
            int nextY = currY + neighbors[i][1];

            if (nextX >= 0 && nextX < HEIGHT && nextY >= 0 && nextY < WIDTH &&
                maze[nextX][nextY] == 0 && visited[nextX][nextY] == 0) {
                maze[nextX][nextY] = 1;
                visited[nextX][nextY] = 1;
                stack[top++] = (point){nextX, nextY};
                generateMaze(maze, nextX, nextY, visited);
            }
        }

        maze[currX][currY] = 0;
        visited[currX][currY] = 0;
        top--;
    }
}

void printMaze(int **maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 0) {
                printf(" . ");
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}