//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
} Cell;

typedef struct {
    Cell cells[WIDTH][HEIGHT];
} Grid;

void initGrid(Grid *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            grid->cells[i][j].x = i;
            grid->cells[i][j].y = j;
        }
    }
}

void printGrid(Grid *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("(%d, %d) ", grid->cells[i][j].x, grid->cells[i][j].y);
        }
        printf("\n");
    }
}

void applyRules(Grid *grid) {
    int i, j;

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (grid->cells[i][j].x < WIDTH / 2) {
                if (grid->cells[i][j].y < HEIGHT / 2) {
                    grid->cells[i][j].x += 1;
                } else {
                    grid->cells[i][j].y += 1;
                }
            } else {
                if (grid->cells[i][j].y < HEIGHT / 2) {
                    grid->cells[i][j].x -= 1;
                } else {
                    grid->cells[i][j].y -= 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Grid *grid = malloc(sizeof(Grid));
    initGrid(grid);

    for (int i = 0; i < 100; i++) {
        applyRules(grid);
        printGrid(grid);

        if (grid->cells[WIDTH / 2][HEIGHT / 2].x == WIDTH / 2) {
            printf("Congratulations, you have a winner! \n");
            break;
        }
    }

    free(grid);

    return 0;
}