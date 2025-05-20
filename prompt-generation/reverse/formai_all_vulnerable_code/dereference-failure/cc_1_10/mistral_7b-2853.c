//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 10
#define DEPTH 10
#define SIZE WIDTH * HEIGHT * DEPTH
#define ESC "\033["

typedef struct {
    int x, y, z;
} point3d;

void print_point(point3d p) {
    int r = p.x % 4, g = p.y % 4, b = p.z % 4;
    printf(ESC"%d;%d;%dm.", r * 16 + g * 4 + b, p.x, p.y);
}

void print_cube(point3d p, int value) {
    int i;
    point3d corners[8] = {
        {p.x - 1, p.y - 1, p.z - 1},
        {p.x - 1, p.y - 1, p.z},
        {p.x - 1, p.y - 1, p.z + 1},
        {p.x - 1, p.y, p.z - 1},
        {p.x - 1, p.y, p.z},
        {p.x - 1, p.y, p.z + 1},
        {p.x, p.y - 1, p.z - 1},
        {p.x, p.y - 1, p.z + 1}
    };

    printf(ESC"[2J");
    for (i = 0; i < 8; i++) {
        print_point(corners[i]);
        printf("%s%d%s\n", value > corners[i].x ? ">" : "<", value, "\033[0m");
    }
}

void visualize_matrix(int *matrix) {
    int i, j, k;
    point3d p;

    srand(time(NULL));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            for (k = 0; k < DEPTH; k++) {
                p.x = j + rand() % 2;
                p.y = i + rand() % 2;
                p.z = k;
                print_cube(p, matrix[i * WIDTH * DEPTH + j * DEPTH + k]);
            }
        }
    }
}

int main() {
    int *matrix = malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        matrix[i] = rand() % 2;
    }

    visualize_matrix(matrix);

    free(matrix);

    return 0;
}