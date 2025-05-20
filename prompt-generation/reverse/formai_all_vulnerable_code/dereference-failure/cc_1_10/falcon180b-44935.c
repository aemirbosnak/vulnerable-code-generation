//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 30
#define DROPS 5000
#define THRESHOLD 3

int **grid;
int num_drops;

void init_grid() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            grid[i][j] = 0;
        }
    }
}

void create_grid() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(rand() % 2 == 0) {
                grid[i][j] = 1;
            }
        }
    }
}

void print_grid() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int x, int y) {
    int count = 0;
    if(x > 0 && grid[x-1][y] == 1) count++;
    if(x < HEIGHT-1 && grid[x+1][y] == 1) count++;
    if(y > 0 && grid[x][y-1] == 1) count++;
    if(y < WIDTH-1 && grid[x][y+1] == 1) count++;
    return count;
}

void percolate() {
    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            if(grid[i][j] == 1) {
                int neighbors = count_neighbors(i, j);
                if(neighbors < THRESHOLD) {
                    grid[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_grid();
    create_grid();
    print_grid();

    int i;
    for(i = 0; i < DROPS; i++) {
        int x = rand() % HEIGHT;
        int y = rand() % WIDTH;
        if(grid[x][y] == 0) {
            grid[x][y] = 1;
        }
    }

    print_grid();

    percolate();

    print_grid();

    return 0;
}