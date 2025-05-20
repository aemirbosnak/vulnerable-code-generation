//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 11
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} point;

void print_maze(int **maze) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : "  ");
        printf("\n");
    }
}

void random_walk(int **maze, point *start, int *visited) {
    point current = *start;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int rand_num;

    maze[current.y][current.x] = PATH;
    visited[current.x + current.y * WIDTH] = 1;

    while (1) {
        rand_num = rand() % 4;

        current.x += dx[rand_num];
        current.y += dy[rand_num];

        if (current.x < 0 || current.x >= WIDTH || current.y < 0 || current.y >= HEIGHT) {
            current.x = start->x;
            current.y = start->y;
            continue;
        }

        if (maze[current.y][current.x] == WALL) {
            maze[current.y][current.x] = PATH;
            visited[current.x + current.y * WIDTH] = 1;
            continue;
        }

        if (visited[current.x + current.y * WIDTH] == 1) {
            current.x -= dx[rand_num];
            current.y -= dy[rand_num];
            continue;
        }

        break;
    }

    visited[current.x + current.y * WIDTH] = 1;
    maze[current.y][current.x] = PATH;

    random_walk(maze, &current, visited);
}

int main() {
    int i, j, **maze, *visited;
    point start = {5, 5};

    srand(time(NULL));

    maze = calloc(HEIGHT, sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    visited = calloc(WIDTH * HEIGHT, sizeof(int));

    maze[start.y][start.x] = PATH;
    visited[start.x + start.y * WIDTH] = 1;

    random_walk(maze, &start, visited);

    print_maze(maze);

    for (i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);
    free(visited);

    return 0;
}