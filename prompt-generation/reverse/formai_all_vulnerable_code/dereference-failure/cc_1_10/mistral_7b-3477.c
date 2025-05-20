//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} pos_t;

void print_maze(int **maze) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : "  ");
        printf("\n");
    }
}

int rand_in_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int is_valid(int **maze, int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] == WALL);
}

void connect(int **maze, int x1, int y1, int x2, int y2) {
    maze[y1][x1] = maze[y2][x2] = PATH;
}

void recursive_backtracking(int **maze, int x, int y) {
    pos_t stack[WIDTH * HEIGHT];
    int top = 0;

    stack[top++] = (pos_t){x, y};

    while (top > 0) {
        int current_x = stack[top - 1].x;
        int current_y = stack[top - 1].y;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int next_x, next_y;

        for (int i = 0; i < 4; i++) {
            next_x = current_x + dx[i];
            next_y = current_y + dy[i];

            if (is_valid(maze, next_x, next_y)) {
                maze[current_y][current_x] = PATH;
                stack[top++] = (pos_t){next_x, next_y};
                recursive_backtracking(maze, next_x, next_y);
            }
        }

        maze[current_y][current_x] = WALL;
        top--;
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(sizeof(int *) * HEIGHT);

    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = calloc(WIDTH, sizeof(int));
        for (int j = 0; j < WIDTH; j++)
            maze[i][j] = WALL;
    }

    pos_t start = {rand_in_range(0, WIDTH - 1), rand_in_range(0, HEIGHT - 1)};

    maze[start.y][start.x] = PATH;

    recursive_backtracking(maze, start.x, start.y);

    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    return 0;
}