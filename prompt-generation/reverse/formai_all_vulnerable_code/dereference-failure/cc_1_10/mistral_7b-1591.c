//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define WIDTH 41
#define HEIGHT 21
#define MAZE_FILE "maze.bin"

typedef struct {
    unsigned char data[WIDTH * HEIGHT];
} maze_t;

typedef struct {
    int x, y;
} pos_t;

static bool is_valid(pos_t pos, maze_t *maze) {
    if (pos.x < 0 || pos.x >= WIDTH || pos.y < 0 || pos.y >= HEIGHT)
        return false;
    return maze->data[pos.y * WIDTH + pos.x] != 0;
}

static void randomize_maze(maze_t *maze) {
    pos_t stack[WIDTH * HEIGHT / 2];
    int top = 0;
    int visited[WIDTH * HEIGHT];
    int x, y;
    srand(time(NULL));

    memset(visited, 0, sizeof(visited));

    // mark starting cell as visited
    maze->data[0] = 1;
    stack[top++] = (pos_t){0, 0};

    while (top) {
        x = stack[top - 1].x;
        y = stack[top - 1].y;

        while (true) {
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            int n;

            for (n = 0; n < 4; n++) {
                int new_x = x + dx[n];
                int new_y = y + dy[n];

                if (is_valid((pos_t){new_x, new_y}, maze) && !visited[new_y * WIDTH + new_x]) {
                    visited[new_y * WIDTH + new_x] = 1;
                    maze->data[new_y * WIDTH + new_x] = 1;
                    stack[top++] = (pos_t){new_x, new_y};
                    break;
                }
            }

            if (n == 4) {
                if (top) {
                    x = stack[--top].x;
                    y = stack[--top].y;
                } else {
                    break;
                }
            }
        }
    }
}

int main() {
    int fd;
    maze_t *maze;

    fd = open(MAZE_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    maze = mmap(NULL, WIDTH * HEIGHT, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    randomize_maze(maze);

    close(fd);
    munmap(maze, WIDTH * HEIGHT);

    // print maze to console (for testing purposes)
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", maze->data[y * WIDTH + x] ? ' ' : '#');
        }
        printf("\n");
    }

    return 0;
}