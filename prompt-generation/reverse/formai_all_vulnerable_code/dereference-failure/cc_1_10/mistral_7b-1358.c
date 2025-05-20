//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 41
#define HEIGHT 21
#define CELL_SIZE 4

typedef struct {
    int x, y;
} cell;

void print_maze(int **maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 0)
                printf("  ");
            else
                printf("%2c", maze[i][j] + 'A' - 1);
        }
        printf("\n");
    }
}

void dfs(int **maze, int x, int y) {
    maze[y][x] = 0;
    int dx[4] = {-1, 0, 1, 1}, dy[4] = {-1, 1, 1, 0};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT &&
            maze[ny][nx] != 0) {
            maze[ny][nx] = 0;
            dfs(maze, nx, ny);
        }
    }
}

int main() {
    srand(time(NULL));

    int **maze = mmap(NULL, HEIGHT * WIDTH * sizeof(int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = 1;
        }
    }

    int start_x = rand() % WIDTH, start_y = rand() % HEIGHT;
    maze[start_y][start_x] = 0;

    dfs(maze, start_x, start_y);

    print_maze(maze);

    munmap(maze, HEIGHT * WIDTH * sizeof(int));

    return 0;
}