//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x, y;
} point;

bool** grid;
bool occupied[WIDTH][HEIGHT];
point puddles[WIDTH * HEIGHT];
int num_puddles = 0;

void print_grid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(grid[j][i] ? "X " : "O ");
        }
        printf("\n");
    }
}

void simulate_drop(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return;
    }

    if (!occupied[x][y]) {
        occupied[x][y] = true;
        grid[x][y] = true;
        puddles[num_puddles++] = (point){x, y};

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int nx = x + dx, ny = y + dy;
                simulate_drop(nx, ny);
            }
        }
    }
}

void generate_random_puddles(int num) {
    for (int i = 0; i < num; i++) {
        int x, y;
        do {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        } while (occupied[x][y]);

        simulate_drop(x, y);
    }
}

int main() {
    srand(time(NULL));

    grid = malloc(WIDTH * sizeof(bool*));
    for (int i = 0; i < WIDTH; i++) {
        grid[i] = calloc(HEIGHT, sizeof(bool));
    }

    printf("Initial Grid:\n");
    print_grid();

    printf("\nDropping %d random puddles:\n", 50);
    generate_random_puddles(50);
    print_grid();

    free(grid);
    return 0;
}