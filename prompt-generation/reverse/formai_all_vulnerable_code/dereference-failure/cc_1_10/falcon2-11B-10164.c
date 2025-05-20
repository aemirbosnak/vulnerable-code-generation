//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **maze;
} maze_t;

void init_maze(maze_t *maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    maze->maze = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        maze->maze[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            maze->maze[i][j] = 0;
        }
    }
}

void print_maze(maze_t *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

void solve_maze(maze_t *maze, int start_row, int start_col) {
    maze->maze[start_row][start_col] = 1;
    int rows = maze->rows;
    int cols = maze->cols;
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < rows * cols; i++) {
        int row = i / cols;
        int col = i % cols;
        if (row == start_row && col == start_col) {
            continue;
        }
        for (int j = 0; j < 4; j++) {
            int new_row = row + directions[j][0];
            int new_col = col + directions[j][1];
            if (new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) {
                continue;
            }
            if (maze->maze[new_row][new_col] == 1) {
                continue;
            }
            maze->maze[new_row][new_col] = 1;
            solve_maze(maze, new_row, new_col);
        }
    }
}

int main() {
    srand(time(NULL));

    int rows = 20;
    int cols = 20;
    maze_t maze;
    init_maze(&maze, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze.maze[i][j] = rand() % 2;
        }
    }

    print_maze(&maze);
    solve_maze(&maze, 0, 0);
    print_maze(&maze);

    return 0;
}