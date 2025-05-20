//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

// Maze generation algorithm: Eller's algorithm
// https://en.wikipedia.org/wiki/Maze_generation_algorithm#Eller.27s_algorithm
typedef struct {
    int n_rows;
    int n_cols;
    int **grid;
} Maze;

Maze *maze_new(int n_rows, int n_cols) {
    Maze *maze = malloc(sizeof(Maze));
    assert(maze != NULL);

    maze->n_rows = n_rows;
    maze->n_cols = n_cols;

    maze->grid = malloc(n_rows * sizeof(int *));
    assert(maze->grid != NULL);

    for (int i = 0; i < n_rows; i++) {
        maze->grid[i] = malloc(n_cols * sizeof(int));
        assert(maze->grid[i] != NULL);

        for (int j = 0; j < n_cols; j++) {
            maze->grid[i][j] = 0;
        }
    }

    return maze;
}

void maze_free(Maze *maze) {
    for (int i = 0; i < maze->n_rows; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void maze_print(Maze *maze) {
    for (int i = 0; i < maze->n_rows; i++) {
        for (int j = 0; j < maze->n_cols; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

void maze_generate_ellers(Maze *maze) {
    int n_sets = maze->n_cols;
    int *sets = malloc(n_sets * sizeof(int));
    assert(sets != NULL);

    for (int i = 0; i < n_sets; i++) {
        sets[i] = i;
    }

    for (int i = 0; i < maze->n_rows; i++) {
        for (int j = 0; j < maze->n_cols; j++) {
            if (i > 0 && rand() % 2 == 0) {
                maze->grid[i][j] |= maze->grid[i - 1][j] & 1;
            }
            if (j > 0 && rand() % 2 == 0) {
                int set_j = sets[j];
                int set_j_minus_1 = sets[j - 1];
                if (set_j != set_j_minus_1) {
                    maze->grid[i][j] |= maze->grid[i][j - 1] & 1;
                    for (int k = 0; k < n_sets; k++) {
                        if (sets[k] == set_j_minus_1) {
                            sets[k] = set_j;
                        }
                    }
                }
            }
            if (i == maze->n_rows - 1 || j == maze->n_cols - 1) {
                maze->grid[i][j] |= 1;
            }
        }
    }

    free(sets);
}

int main() {
    srand(time(NULL));

    int n_rows = 10;
    int n_cols = 10;

    Maze *maze = maze_new(n_rows, n_cols);
    maze_generate_ellers(maze);
    maze_print(maze);
    maze_free(maze);

    return 0;
}