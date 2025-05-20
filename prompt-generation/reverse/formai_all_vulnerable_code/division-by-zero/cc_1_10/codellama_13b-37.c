//Code Llama-13B DATASET v1.0 Category: Maze Route Finder ; Style: lively
// maze_route_finder.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10
#define WALL 1
#define PATH 0

int maze[MAZE_SIZE][MAZE_SIZE];
int visited[MAZE_SIZE][MAZE_SIZE];

int start_x, start_y, end_x, end_y;

void init_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = WALL;
            visited[i][j] = 0;
        }
    }

    start_x = 0;
    start_y = 0;
    end_x = MAZE_SIZE - 1;
    end_y = MAZE_SIZE - 1;

    maze[start_x][start_y] = PATH;
    maze[end_x][end_y] = PATH;
}

void print_maze() {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void find_path() {
    int x = start_x;
    int y = start_y;
    int path[MAZE_SIZE * MAZE_SIZE];
    int path_size = 0;

    while (x != end_x || y != end_y) {
        visited[x][y] = 1;
        int neighbors[4];
        int num_neighbors = 0;

        if (x > 0 && maze[x - 1][y] == PATH && !visited[x - 1][y]) {
            neighbors[num_neighbors++] = x - 1;
        }
        if (x < MAZE_SIZE - 1 && maze[x + 1][y] == PATH && !visited[x + 1][y]) {
            neighbors[num_neighbors++] = x + 1;
        }
        if (y > 0 && maze[x][y - 1] == PATH && !visited[x][y - 1]) {
            neighbors[num_neighbors++] = y - 1;
        }
        if (y < MAZE_SIZE - 1 && maze[x][y + 1] == PATH && !visited[x][y + 1]) {
            neighbors[num_neighbors++] = y + 1;
        }

        int next_x = neighbors[rand() % num_neighbors];
        int next_y = neighbors[rand() % num_neighbors];

        x = next_x;
        y = next_y;

        path[path_size++] = x;
        path[path_size++] = y;
    }

    for (int i = 0; i < path_size; i += 2) {
        maze[path[i]][path[i + 1]] = PATH;
    }
}

int main() {
    init_maze();
    print_maze();
    find_path();
    print_maze();
    return 0;
}