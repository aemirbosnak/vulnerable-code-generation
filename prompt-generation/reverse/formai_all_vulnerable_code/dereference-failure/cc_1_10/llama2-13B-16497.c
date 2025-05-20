//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH  1024
#define HEIGHT 768
#define FPS 60

typedef struct Particle {
    int x;
    int y;
    int vx;
    int vy;
} Particle;

typedef struct Grid {
    Particle** grid;
    int width;
    int height;
} Grid;

void initGrid(Grid* g) {
    g->width = WIDTH;
    g->height = HEIGHT;
    g->grid = (Particle**) malloc(g->width * g->height * sizeof(Particle*));
    for (int i = 0; i < g->width; i++) {
        for (int j = 0; j < g->height; j++) {
            g->grid[i * g->height + j] = (Particle*) malloc(sizeof(Particle));
            g->grid[i * g->height + j]->x = i * 10;
            g->grid[i * g->height + j]->y = j * 10;
            g->grid[i * g->height + j]->vx = (rand() % 2) - 1;
            g->grid[i * g->height + j]->vy = (rand() % 2) - 1;
        }
    }
}

void updateGrid(Grid* g) {
    for (int i = 0; i < g->width; i++) {
        for (int j = 0; j < g->height; j++) {
            g->grid[i * g->height + j]->x += g->grid[i * g->height + j]->vx;
            g->grid[i * g->height + j]->y += g->grid[i * g->height + j]->vy;
            g->grid[i * g->height + j]->vx += (rand() % 2) - 1;
            g->grid[i * g->height + j]->vy += (rand() % 2) - 1;
            if (g->grid[i * g->height + j]->x < 0 || g->grid[i * g->height + j]->x > WIDTH - 10 ||
                    g->grid[i * g->height + j]->y < 0 || g->grid[i * g->height + j]->y > HEIGHT - 10) {
                g->grid[i * g->height + j]->x = (rand() % WIDTH) * 10;
                g->grid[i * g->height + j]->y = (rand() % HEIGHT) * 10;
            }
        }
    }
}

void drawGrid(Grid* g) {
    for (int i = 0; i < g->width; i++) {
        for (int j = 0; j < g->height; j++) {
            printf("%d, %d\n", g->grid[i * g->height + j]->x, g->grid[i * g->height + j]->y);
        }
    }
}

int main() {
    srand(time(NULL));
    Grid g;
    initGrid(&g);
    for (int i = 0; i < FPS; i++) {
        updateGrid(&g);
        drawGrid(&g);
        sleep(1);
    }
    return 0;
}