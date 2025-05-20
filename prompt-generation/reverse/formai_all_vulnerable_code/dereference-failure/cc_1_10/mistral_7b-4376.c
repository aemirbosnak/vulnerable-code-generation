//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} point;

void print_maze(int **maze) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(maze[i][j] == WALL ? "%c" : " ");
        printf("\n");
    }
}

point random_neighbor(point p, int **maze) {
    point neighbors[4];
    int count = 0;
    neighbors[count++] = (point){p.x - 2, p.y};
    neighbors[count++] = (point){p.x + 2, p.y};
    neighbors[count++] = (point){p.x, p.y - 2};
    neighbors[count++] = (point){p.x, p.y + 2};

    for (int i = 0; i < count; i++) {
        if (maze[neighbors[i].y][neighbors[i].x] == PATH)
            return neighbors[i];
    }
    return (point){-1, -1};
}

void generate_maze(int **maze) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;
    point start = (point){1, 1};

    maze[start.y][start.x] = PATH;
    stack[top++] = start;

    while (top) {
        point current = stack[--top];
        point next = random_neighbor(current, maze);

        if (next.x != -1) {
            maze[next.y][next.x] = PATH;
            maze[current.y + (next.y > current.y ? 1 : -1)][current.x + (next.x > current.x ? 1 : -1)] = PATH;
            stack[top++] = next;
        }
    }
}

int main() {
    srand(time(NULL));
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