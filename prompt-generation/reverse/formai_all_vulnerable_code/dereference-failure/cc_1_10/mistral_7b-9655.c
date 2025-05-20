//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
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

void print_maze(int **maze, point start) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;
    maze[start.x][start.y] = PATH;
    stack[top++] = start;

    while (top > 0) {
        point current = stack[--top];
        int dx[] = {0, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1};
        int dy[] = {-1, -1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};

        for (int i = 0; i < 14; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT && maze[nx][ny] == WALL) {
                maze[current.x + dx[(i + 1) % 14] / 2][current.y + dy[(i + 1) % 14] / 2] = PATH;
                maze[nx][ny] = PATH;
                stack[top++] = (point){nx, ny};
                break;
            }
        }
    }
}

void die(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

int main() {
    srand(time(NULL));
    int **maze = malloc(WIDTH * sizeof(int *) + HEIGHT * WIDTH * sizeof(int));

    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        maze[i / WIDTH] = maze + i + WIDTH + (i < WIDTH ? 0 : HEIGHT);
        for (int j = 0; j < WIDTH; j++)
            maze[i / WIDTH][j] = WALL;
    }

    point start = {rand() % WIDTH, rand() % HEIGHT};
    maze[start.x][start.y] = WALL;

    if (start.x % 2 || start.y % 2)
        die("Starting point must be on a border.\n");

    print_maze(maze, start);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            if (maze[i][j] == WALL)
                putchar('#');
            else
                putchar(' ');
        putchar('\n');
    }

    free(maze);
    return 0;
}