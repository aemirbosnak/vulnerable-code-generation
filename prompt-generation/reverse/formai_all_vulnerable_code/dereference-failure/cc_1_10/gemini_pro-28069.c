//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point start;
    point end;
    bool **maze;
} maze_t;

bool is_valid_move(maze_t *maze, point p) {
    return p.x >= 0 && p.x < MAZE_SIZE && p.y >= 0 && p.y < MAZE_SIZE && !maze->maze[p.x][p.y];
}

void print_maze(maze_t *maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            printf("%c", maze->maze[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

bool find_path(maze_t *maze, point p, point end) {
    if (!is_valid_move(maze, p)) {
        return false;
    }

    if (p.x == end.x && p.y == end.y) {
        return true;
    }

    maze->maze[p.x][p.y] = true;

    if (find_path(maze, (point) {p.x + 1, p.y}, end)) {
        return true;
    }

    if (find_path(maze, (point) {p.x - 1, p.y}, end)) {
        return true;
    }

    if (find_path(maze, (point) {p.x, p.y + 1}, end)) {
        return true;
    }

    if (find_path(maze, (point) {p.x, p.y - 1}, end)) {
        return true;
    }

    maze->maze[p.x][p.y] = false;

    return false;
}

int main() {
    maze_t maze = {
        .start = {0, 0},
        .end = {MAZE_SIZE - 1, MAZE_SIZE - 1},
        .maze = malloc(MAZE_SIZE * sizeof(bool *))
    };

    for (int i = 0; i < MAZE_SIZE; i++) {
        maze.maze[i] = malloc(MAZE_SIZE * sizeof(bool));
    }

    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze.maze[i][j] = false;
        }
    }

    // Create a simple maze
    maze.maze[0][1] = true;
    maze.maze[1][1] = true;
    maze.maze[2][1] = true;
    maze.maze[3][1] = true;
    maze.maze[4][1] = true;
    maze.maze[5][1] = true;
    maze.maze[6][1] = true;
    maze.maze[7][1] = true;
    maze.maze[8][1] = true;
    maze.maze[9][1] = true;

    print_maze(&maze);

    if (find_path(&maze, maze.start, maze.end)) {
        printf("Found a path!\n");
    } else {
        printf("No path found.\n");
    }

    for (int i = 0; i < MAZE_SIZE; i++) {
        free(maze.maze[i]);
    }

    free(maze.maze);

    return 0;
}