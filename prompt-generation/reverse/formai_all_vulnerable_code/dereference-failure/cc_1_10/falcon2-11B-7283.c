//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 30
#define MAX_COLS 30

typedef struct {
    int rows;
    int cols;
    int **maze;
} Maze;

void print_maze(Maze *maze);

Maze *create_maze(int rows, int cols);

void find_path(Maze *maze, int start_row, int start_col, int end_row, int end_col);

int main(int argc, char *argv[]) {
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    Maze *maze = create_maze(rows, cols);

    int start_row = atoi(argv[3]);
    int start_col = atoi(argv[4]);

    int end_row = atoi(argv[5]);
    int end_col = atoi(argv[6]);

    find_path(maze, start_row, start_col, end_row, end_col);

    print_maze(maze);

    return 0;
}

Maze *create_maze(int rows, int cols) {
    Maze *maze = malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;
    maze->maze = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        maze->maze[i] = malloc(cols * sizeof(int));

        for (int j = 0; j < cols; j++) {
            maze->maze[i][j] = -1;
        }
    }

    return maze;
}

void print_maze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

void find_path(Maze *maze, int start_row, int start_col, int end_row, int end_col) {
    int x1, y1;
    int x2, y2;

    maze->maze[start_row][start_col] = 0;

    x1 = start_row;
    y1 = start_col;

    while (x1!= end_row || y1!= end_col) {
        x2 = x1;
        y2 = y1;

        if (x1 < end_row && maze->maze[x1 + 1][y1] == 0) {
            x1++;
        } else if (x1 > 0 && maze->maze[x1 - 1][y1] == 0) {
            x1--;
        } else if (y1 < end_col && maze->maze[x1][y1 + 1] == 0) {
            y1++;
        } else if (y1 > 0 && maze->maze[x1][y1 - 1] == 0) {
            y1--;
        }

        maze->maze[x2][y2] = 1;
    }
}