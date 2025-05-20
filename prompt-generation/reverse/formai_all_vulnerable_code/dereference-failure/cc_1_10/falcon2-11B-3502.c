//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **maze;
} Maze;

Maze* create_maze(int rows, int cols) {
    Maze* maze = malloc(sizeof(Maze));
    if (maze == NULL) {
        printf("Out of memory!\n");
        return NULL;
    }
    maze->rows = rows;
    maze->cols = cols;
    maze->maze = malloc(rows * sizeof(int*));
    if (maze->maze == NULL) {
        printf("Out of memory!\n");
        return NULL;
    }
    for (int i = 0; i < rows; i++) {
        maze->maze[i] = malloc(cols * sizeof(int));
        if (maze->maze[i] == NULL) {
            printf("Out of memory!\n");
            return NULL;
        }
    }
    return maze;
}

void destroy_maze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->maze[i]);
    }
    free(maze->maze);
    free(maze);
}

void print_maze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(Maze* maze, int x, int y, int rows, int cols) {
    if (x >= rows || y >= cols) {
        return;
    }
    maze->maze[x][y] = 1;
    generate_maze(maze, x + 1, y, rows, cols);
    generate_maze(maze, x, y + 1, rows, cols);
    generate_maze(maze, x + 1, y + 1, rows, cols);
}

int main() {
    srand(time(NULL));
    int rows = 10, cols = 10;
    Maze* maze = create_maze(rows, cols);
    if (maze == NULL) {
        printf("Failed to create maze.\n");
        return 1;
    }
    generate_maze(maze, 0, 0, rows, cols);
    print_maze(maze);
    destroy_maze(maze);
    return 0;
}