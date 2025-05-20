//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define N 9

struct cell {
    int value;
    bool fixed;
};

struct sudoku {
    struct cell grid[N][N];
};

static struct sudoku *init_sudoku(int seed) {
    struct sudoku *s = malloc(sizeof(*s));
    if (!s) {
        return NULL;
    }

    srand(seed);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            s->grid[i][j].value = 0;
            s->grid[i][j].fixed = false;
        }
    }

    for (int i = 0; i < N; i++) {
        int j = rand() % N;
        int k = rand() % N;
        s->grid[i][j].value = rand() % N + 1;
        s->grid[i][j].fixed = true;
    }

    return s;
}

static void free_sudoku(struct sudoku *s) {
    if (s) {
        free(s);
    }
}

static bool is_valid_sudoku(const struct sudoku *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->grid[i][j].value == 0) {
                continue;
            }

            for (int k = 0; k < N; k++) {
                if (k == j) {
                    continue;
                }

                if (s->grid[i][k].value == s->grid[i][j].value) {
                    return false;
                }
            }

            for (int k = 0; k < N; k++) {
                if (k == i) {
                    continue;
                }

                if (s->grid[k][j].value == s->grid[i][j].value) {
                    return false;
                }
            }

            int box_i = i / 3;
            int box_j = j / 3;

            for (int k = box_i * 3; k < box_i * 3 + 3; k++) {
                for (int l = box_j * 3; l < box_j * 3 + 3; l++) {
                    if (k == i && l == j) {
                        continue;
                    }

                    if (s->grid[k][l].value == s->grid[i][j].value) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

static bool solve_sudoku(struct sudoku *s) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s->grid[i][j].fixed) {
                continue;
            }

            for (int k = 1; k <= N; k++) {
                s->grid[i][j].value = k;

                if (is_valid_sudoku(s)) {
                    if (solve_sudoku(s)) {
                        return true;
                    }
                }

                s->grid[i][j].value = 0;
            }

            return false;
        }
    }

    return true;
}

static void print_sudoku(const struct sudoku *s) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0) {
            printf("+-----+-----+-----+\n");
        }

        for (int j = 0; j < N; j++) {
            if (j % 3 == 0) {
                printf("| ");
            }

            if (s->grid[i][j].fixed) {
                printf("%d ", s->grid[i][j].value);
            } else {
                printf("- ");
            }
        }

        printf("|\n");
    }

    printf("+-----+-----+-----+\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s SEED\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);

    struct sudoku *s = init_sudoku(seed);
    if (!s) {
        fprintf(stderr, "Failed to allocate memory for sudoku\n");
        return 1;
    }

    print_sudoku(s);
    printf("\n");

    if (solve_sudoku(s)) {
        print_sudoku(s);
    } else {
        printf("No solution found\n");
    }

    free_sudoku(s);

    return 0;
}