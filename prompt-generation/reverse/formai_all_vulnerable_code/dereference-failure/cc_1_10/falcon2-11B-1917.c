//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **maze;
} maze_t;

int is_valid(maze_t *maze, int row, int col) {
    if (row >= 0 && row < maze->rows && col >= 0 && col < maze->cols) {
        return maze->maze[row][col] == 0;
    }
    return 0;
}

void print_maze(maze_t *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int rows = rand() % 30 + 1;
    int cols = rand() % 30 + 1;
    maze_t maze = {rows, cols, malloc(rows * sizeof(int*))};
    maze.maze = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        maze.maze[i] = malloc(cols * sizeof(int));
    }

    int start = rand() % (rows * cols);
    maze.maze[start / cols][start % cols] = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (is_valid(&maze, i, j)) {
                maze.maze[i][j] = rand() % 2 + 1;
            }
        }
    }

    print_maze(&maze);
    free(maze.maze);
    free(maze.maze);
    return 0;
}