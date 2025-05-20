//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>

#define WIDTH 21
#define HEIGHT 11
#define WALL 0
#define PATH 1
#define START 2
#define END 3

typedef struct {
    int x, y;
} Point;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(maze[i][j] == WALL ? "##" : maze[i][j] == START ? " S" : maze[i][j] == END ? " E" : "  ");
        }
        printf("\n");
    }
}

bool valid_move(int **maze, int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] == WALL;
}

void dfs_maze(int **maze, int **visited, int x, int y) {
    maze[y][x] = PATH;
    visited[y][x] = true;

    Point stack[WIDTH * HEIGHT / 2];
    int top = 0;

    stack[top++] = (Point) {x, y};

    while (top > 0) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        Point curr = stack[--top];
        int curr_x = curr.x;
        int curr_y = curr.y;

        for (int i = 0; i < 4; i++) {
            int next_x = curr_x + dx[i];
            int next_y = curr_y + dy[i];

            if (valid_move(maze, next_x, next_y)) {
                maze[next_y][next_x] = PATH;
                visited[next_y][next_x] = true;
                stack[top++] = (Point) {next_x, next_y};
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = calloc(WIDTH, sizeof(int));
    }

    int **visited = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        visited[i] = calloc(WIDTH, sizeof(bool));
    }

    maze[0][0] = START;
    maze[HEIGHT - 1][WIDTH - 1] = END;

    dfs_maze(maze, visited, 0, 0);

    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(visited[i]);
    }
    free(visited);

    return 0;
}