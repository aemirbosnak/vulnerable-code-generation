//MISTRAL-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

typedef struct Cell {
    int value;
    struct Cell *up, *down, *left, *right;
} Cell;

Cell **level;

void generate_level() {
    int i, j, r, c;
    srand(time(NULL));

    level = (Cell **)calloc(HEIGHT, sizeof(Cell *));
    for (i = 0; i < HEIGHT; ++i) {
        level[i] = (Cell *)calloc(WIDTH, sizeof(Cell));

        for (j = 0; j < WIDTH; ++j) {
            level[i][j].value = 0;

            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                level[i][j].value = 1;
            }

            if (rand() % 2) {
                level[i][j].value = 2;

                if (i > 0 && level[i - 1][j].value == 0) {
                    level[i][j].up = &level[i - 1][j];
                    level[i - 1][j].down = &level[i][j];
                }

                if (j > 0 && level[i][j - 1].value == 0) {
                    level[i][j].left = &level[i][j - 1];
                    level[i][j - 1].right = &level[i][j];
                }
            }
        }

        if (i > 0) {
            level[i][0].up = &level[i - 1][0];
            level[i - 1][0].down = &level[i][0];
        }

        if (i < HEIGHT - 1) {
            level[i][WIDTH - 1].down = &level[i + 1][WIDTH - 1];
            level[i + 1][WIDTH - 1].up = &level[i][WIDTH - 1];
        }
    }
}

void print_level() {
    int i, j;

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            printf("%d ", level[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    generate_level();
    print_level();

    return 0;
}