//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: post-apocalyptic
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
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(maze[i][j] == WALL ? "##" : "  ");
        }
        printf("\n");
    }
}

point random_neighbor(int **maze, int x, int y) {
    point neighbors[4];
    int count = 0;

    if (x > 0 && maze[y][x - 1] == PATH) {
        neighbors[count++] = (point){x - 1, y};
    }

    if (x < WIDTH - 1 && maze[y][x + 1] == PATH) {
        neighbors[count++] = (point){x + 1, y};
    }

    if (y > 0 && maze[y - 1][x] == PATH) {
        neighbors[count++] = (point){x, y - 1};
    }

    if (y < HEIGHT - 1 && maze[y + 1][x] == PATH) {
        neighbors[count++] = (point){x, y + 1};
    }

    if (count > 0) {
        return neighbors[rand() % count];
    }

    return (point){-1, -1};
}

void generate_maze(int **maze) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;

    maze[0][0] = PATH;
    stack[top++] = (point){1, 0};

    while (top > 0) {
        int x = stack[top - 1].x;
        int y = stack[top - 1].y;

        point next = random_neighbor(maze, x, y);

        if (next.x != -1) {
            maze[next.y][next.x] = PATH;
            stack[top++] = next;
        } else {
            top--;
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = calloc(WIDTH, sizeof(int));
    }

    generate_maze(maze);
    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}