//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 41
#define HEIGHT 21
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} point;

bool is_valid(int x, int y, int **maze) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] == WALL;
}

void print_maze(int **maze) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf(maze[i][j] == WALL ? "%c" : " ");
        }
        printf("\n");
    }
}

void recursive_backtracking(int **maze, point start) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;
    maze[start.y][start.x] = PATH;
    stack[top++] = start;

    while (top > 0) {
        point current = stack[--top];
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int x = current.x + dx[i];
            int y = current.y + dy[i];

            if (is_valid(x, y, maze)) {
                maze[y][x] = PATH;
                stack[top++] = (point){x, y};
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int **maze = malloc(HEIGHT * sizeof(int *));

    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = calloc(WIDTH, sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }

    point start = {rand() % WIDTH, rand() % HEIGHT};
    maze[start.y][start.x] = PATH;

    clock_t start_time = clock();
    recursive_backtracking(maze, (point){start.x, start.y});
    clock_t end_time = clock();

    printf("Maze generated in %.3fs\n", (end_time - start_time) / CLOCKS_PER_SEC);
    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}