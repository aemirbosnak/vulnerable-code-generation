//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

bool **grid;
bool visited[WIDTH][HEIGHT];
int count;
int x, y;

void percolate(int depth, int i, int j) {
    if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH || visited[j][i] || grid[i][j] == false)
        return;

    visited[j][i] = true;
    count++;
    grid[i][j] = false;

    percolate(depth + 1, i + 1, j);
    percolate(depth + 1, i - 1, j);
    percolate(depth + 1, i, j + 1);
    percolate(depth + 1, i, j - 1);
}

bool percolation() {
    bool isFull = true;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
            if (grid[i][j] == 0)
                isFull = false;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1 && i == 0) {
                x = i;
                y = j;
                count = 0;
                percolate(0, x, y);

                if (count == WIDTH)
                    return true;
            }
        }
    }

    return isFull;
}

int main() {
    srand(time(NULL));

    grid = malloc(HEIGHT * sizeof(bool *));
    for (int i = 0; i < HEIGHT; i++)
        grid[i] = calloc(WIDTH, sizeof(bool));

    bool result = percolation();

    if (result)
        printf("Percolation occurs!\n");
    else
        printf("Percolation does not occur.\n");

    for (int i = 0; i < HEIGHT; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}