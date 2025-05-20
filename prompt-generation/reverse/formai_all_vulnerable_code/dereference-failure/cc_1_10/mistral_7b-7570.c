//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} Point;

typedef struct {
    int **grid;
    int visited[WIDTH][HEIGHT];
    Point stack[WIDTH * HEIGHT / 2];
    int top;
} Maze;

void initMaze(Maze *maze) {
    int i, j;

    maze->grid = malloc(WIDTH * sizeof(int *));
    for (i = 0; i < WIDTH; i++) {
        maze->grid[i] = calloc(HEIGHT, sizeof(int));
        for (j = 0; j < HEIGHT; j++) {
            maze->grid[i][j] = WALL;
            maze->visited[i][j] = false;
        }
    }

    maze->top = -1;
}

bool isValid(Maze *maze, int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze->grid[x][y] == WALL;
}

void printMaze(Maze *maze) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (maze->top >= 0 && maze->stack[maze->top].x == i && maze->stack[maze->top].y == j)
                printf("S");
            else if (maze->visited[i][j])
                printf(".");
            else {
                if (maze->grid[i][j] == PATH)
                    printf(" ");
                else
                    printf("#");
            }
        }
        printf("\n");
    }
}

void recursiveBacktracking(Maze *maze, int x, int y) {
    maze->grid[x][y] = PATH;
    maze->visited[x][y] = true;
    maze->stack[++maze->top] = (Point){x, y};

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(maze, nx, ny)) {
            maze->grid[nx][ny] = PATH;
            recursiveBacktracking(maze, nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));

    Maze maze;
    initMaze(&maze);

    int startX, startY;
    do {
        startX = rand() % WIDTH;
        startY = rand() % HEIGHT;
    } while (maze.grid[startX][startY] != WALL);

    maze.grid[startX][startY] = PATH;
    recursiveBacktracking(&maze, startX, startY);

    printf("Sherlock Holmes's Hidden Maze:\n");
    printMaze(&maze);

    return 0;
}