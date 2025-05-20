//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 21
#define HEIGHT 11
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} Point;

void print_maze(int **maze) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : "  ");
        printf("\n");
    }
}

void randomize_maze(int **maze) {
    int i, j, r1, r2;
    bool visited[WIDTH][HEIGHT];

    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            maze[i][j] = WALL;

    maze[0][0] = maze[0][1] = maze[1][0] = PATH;
    visited[0][0] = visited[0][1] = visited[1][0] = true;

    Point stack[WIDTH * HEIGHT / 2];
    int top = 0;

    stack[top++] = (Point){0, 0};

    while (top > 0) {
        Point current = stack[--top];

        for (i = -2; i <= 2; i++) {
            for (j = -2; j <= 2; j++) {
                if (i == 0 && j == 0)
                    continue;

                int new_x = current.x + i, new_y = current.y + j;

                if (new_x >= 0 && new_x < WIDTH && new_y >= 0 && new_y < HEIGHT &&
                    maze[new_y][new_x] == WALL &&
                    !visited[new_x][new_y]) {
                    maze[new_y][new_x] = PATH;
                    maze[current.y + i / 2][current.x + j / 2] = PATH;

                    visited[new_x][new_y] = true;
                    stack[top++] = (Point){new_x, new_y};
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(sizeof(int *) * HEIGHT);
    int i;

    for (i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    randomize_maze(maze);
    print_maze(maze);

    for (i = 0; i < HEIGHT; i++)
        free(maze[i]);

    free(maze);

    return 0;
}