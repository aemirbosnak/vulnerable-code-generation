//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
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

Point stack[WIDTH * HEIGHT / 2];
int top = 0;

void print_maze(int **maze) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j] == WALL)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void recursive_backtracking(int **maze, int x, int y) {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int i;

    maze[x][y] = PATH;

    stack[top++] = (Point){x, y};

    for (i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && maze[nx][ny] == WALL) {
            maze[nx][ny] = PATH;
            recursive_backtracking(maze, nx, ny);
        }
    }
}

int main() {
    int i, j, **maze;

    srand(time(NULL));

    maze = calloc(WIDTH, sizeof(int *)), *maze = malloc(WIDTH * sizeof(int));
    for (i = 0; i < HEIGHT; i++)
        maze[i] = maze[i] + WIDTH;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            maze[i][j] = WALL;
    }

    recursive_backtracking(maze, rand() % HEIGHT, rand() % WIDTH);

    printf("Maze solved by %s:\n", "Sherlock Holmes");
    print_maze(maze);

    free(maze);

    return 0;
}