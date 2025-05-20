//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL 0
#define PATH 1

typedef struct {
    int start[2];
    int end[2];
    int size;
    int walls[2][2];
} Maze;

Maze* create_maze(int rows, int cols) {
    Maze* maze = malloc(sizeof(Maze));
    maze->start[0] = rand() % rows;
    maze->start[1] = rand() % cols;
    maze->end[0] = rand() % rows;
    maze->end[1] = rand() % cols;
    maze->size = rows * cols;
    maze->walls[0][0] = maze->start[0];
    maze->walls[0][1] = maze->start[1];
    maze->walls[1][0] = maze->end[0];
    maze->walls[1][1] = maze->end[1];
    for (int i = 0; i < maze->size; i++) {
        maze->walls[0][i % 2] = -1;
        maze->walls[1][i % 2] = -1;
    }
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            if (i == maze->start[0] && j == maze->start[1]) {
                maze->walls[0][i % 2] = 0;
            } else if (i == maze->end[0] && j == maze->end[1]) {
                maze->walls[1][i % 2] = 0;
            } else {
                maze->walls[0][i % 2] = 1;
                maze->walls[1][i % 2] = 1;
            }
        }
    }
    return maze;
}

void print_maze(Maze* maze) {
    for (int i = 0; i < maze->size; i++) {
        for (int j = 0; j < maze->size; j++) {
            if (maze->walls[0][i % 2] == WALL || maze->walls[1][i % 2] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void solve_maze(Maze* maze, int* solution) {
    int x = maze->start[0];
    int y = maze->start[1];
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    maze->walls[0][x % 2] = 2;
    maze->walls[1][x % 2] = 2;
    for (int i = 0; i < maze->size; i++) {
        int path[2][2];
        path[0][0] = x;
        path[0][1] = y;
        int current = maze->walls[0][x % 2];
        int next = 0;
        int visited[2][2];
        for (int j = 0; j < 4; j++) {
            next = x + dx[j];
            if (next >= 0 && next < maze->size && y + dy[j] >= 0 && y + dy[j] < maze->size && maze->walls[0][next % 2] == current && maze->walls[1][next % 2] == current) {
                path[1][0] = next;
                path[1][1] = y + dy[j];
                maze->walls[0][next % 2] = 2;
                maze->walls[1][next % 2] = 2;
                solution[i] = i;
                return;
            }
        }
        if (current == 0) {
            maze->walls[1][x % 2] = 2;
        } else {
            maze->walls[0][x % 2] = 2;
        }
        maze->walls[1][y % 2] = 2;
        maze->walls[0][y % 2] = 2;
        x = path[0][0];
        y = path[0][1];
    }
}

int main() {
    srand(time(NULL));
    int rows = 20;
    int cols = 20;
    Maze* maze = create_maze(rows, cols);
    print_maze(maze);
    int solution[rows * cols];
    solve_maze(maze, solution);
    printf("Solution: ");
    for (int i = 0; i < rows * cols; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
    return 0;
}