//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 25
#define HEIGHT 25

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int width;
    int height;
    int **grid;
} maze;

maze *create_maze(int width, int height) {
    maze *m = malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        m->grid[i] = malloc(sizeof(int) * width);
    }
    return m;
}

void destroy_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->grid[i]);
    }
    free(m->grid);
    free(m);
}

void generate_maze(maze *m) {
    srand(time(NULL));
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            m->grid[i][j] = rand() % 2;
        }
    }
}

void print_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d", m->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    maze *m = create_maze(WIDTH, HEIGHT);
    generate_maze(m);
    print_maze(m);
    destroy_maze(m);
    return 0;
}