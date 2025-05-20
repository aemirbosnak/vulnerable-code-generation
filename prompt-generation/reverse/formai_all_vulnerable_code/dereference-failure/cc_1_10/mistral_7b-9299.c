//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} Point;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "##" : "  ");
        printf("\n");
    }
}

void random_walk(int **maze, Point *start, Point *current, int **visited) {
    while (1) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int dir = rand() % 4;
        int nx = current->x + dx[dir], ny = current->y + dy[dir];

        if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT)
            continue;

        if (maze[ny][nx] == WALL || visited[ny][nx] == PATH)
            continue;

        visited[ny][nx] = PATH;
        maze[current->y][current->x] = PATH;
        maze[ny][nx] = PATH;

        current->x = nx;
        current->y = ny;

        if (maze[start->y][start->x] == WALL) {
            maze[start->y][start->x] = PATH;
            visited[start->y][start->x] = PATH;
            print_maze(maze);
            return;
        }
    }
}

void generate_maze(int **maze) {
    int visited[HEIGHT][WIDTH] = {0};
    Point start = {rand() % WIDTH, rand() % HEIGHT}, current;

    maze[start.y][start.x] = PATH;
    visited[start.y][start.x] = PATH;

    random_walk(maze, &start, &current, visited);
}

int main() {
    int t;
    srand(time(&t));

    int **maze = malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    generate_maze(maze);
    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    return 0;
}