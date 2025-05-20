//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 25
#define HEIGHT 25
#define WALL 0
#define PATH 1

typedef struct {
    int x, y;
} Point;

void maze_generate(int x, int y, int **maze);
bool is_valid_move(int x, int y, int **maze);
void print_maze(int **maze);

int main() {
    int *maze = malloc(sizeof(int) * WIDTH * HEIGHT);
    memset(maze, WALL, sizeof(int) * WIDTH * HEIGHT);

    srand(time(NULL));

    maze_generate(0, 0, maze);
    print_maze(maze);

    free(maze);
    return 0;
}

void maze_generate(int x, int y, int **maze) {
    Point stack[WIDTH * HEIGHT / 2];
    int top = 0;

    maze[x][y] = PATH;
    stack[top++] = (Point){x, y};

    while (top > 0) {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        int rand_dir = rand() % 4;
        int nx = x + dx[rand_dir];
        int ny = y + dy[rand_dir];

        if (!is_valid_move(nx, ny, maze)) {
            continue;
        }

        maze_generate(nx, ny, maze);
        maze[x][y] = PATH;
        x = nx;
        y = ny;

        stack[top--] = (Point){x, y};
    }
}

bool is_valid_move(int x, int y, int **maze) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return false;
    }

    if (maze[x][y] == PATH) {
        return false;
    }

    return true;
}

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[j][i] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}