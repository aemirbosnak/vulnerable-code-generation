//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40
#define PIPE_SIZE 3
#define WATER_LEVEL 10
#define NUM_DROPS 1000
#define SLEEP_TIME 50

int water_level = WATER_LEVEL;
int num_drops = NUM_DROPS;
int height = HEIGHT;
int width = WIDTH;
int pipe_size = PIPE_SIZE;
int **percolation_field = NULL;

void init_field() {
    percolation_field = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        percolation_field[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            percolation_field[i][j] = 0;
        }
    }
}

void draw_field() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (percolation_field[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int is_valid_drop(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        if (percolation_field[y][x] == 0) {
            return 1;
        }
    }
    return 0;
}

void drop_water() {
    int x = rand() % width;
    int y = rand() % height;
    while (!is_valid_drop(x, y)) {
        x = rand() % width;
        y = rand() % height;
    }
    percolation_field[y][x] = 1;
}

int main() {
    srand(time(NULL));
    init_field();
    draw_field();
    for (int i = 0; i < num_drops; i++) {
        drop_water();
        draw_field();
        printf("Dropped %d drops of water.\n", i + 1);
        usleep(SLEEP_TIME * 1000);
    }
    return 0;
}