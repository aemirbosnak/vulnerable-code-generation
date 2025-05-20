//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

typedef struct {
    int x, y;
} Point;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            printf(maze[i][j] == 1 ? "  ## " : "  .  ");
        printf("\n");
    }
}

void dfs(int **maze, int x, int y) {
    maze[x][y] = 1;

    int dx[4] = {1, -1, -1, 1};
    int dy[4] = {-1, -1, 1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH && maze[nx][ny] == 0) {
            maze[nx][ny] = 1;
            dfs(maze, nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = malloc(sizeof(int *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
        maze[i] = calloc(WIDTH, sizeof(int));

    int start_x = rand() % HEIGHT, start_y = rand() % WIDTH;
    maze[start_x][start_y] = 1;

    dfs(maze, start_x, start_y);

    print_maze(maze);

    for (int i = 0; i < HEIGHT; i++)
        free(maze[i]);
    free(maze);

    return 0;
}