//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 50
#define COLS 50
#define NEIGHBORS 8
#define ALIVE 1
#define DEAD 0

typedef struct {
    int row, col;
    int alive;
} cell;

typedef struct {
    cell *grid;
    int generations;
} game;

pthread_mutex_t lock;
game *g;

void *run(void *arg) {
    int i, j, k, x, y, neighbors;
    while (1) {
        pthread_mutex_lock(&lock);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                neighbors = 0;
                for (k = 0; k < NEIGHBORS; k++) {
                    x = i + (k % 3) - 1;
                    y = j + (k / 3) - 1;
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
                        neighbors += g->grid[x * COLS + y].alive;
                    }
                }
                if (g->grid[i * COLS + j].alive) {
                    if (neighbors < 2 || neighbors > 3) {
                        g->grid[i * COLS + j].alive = DEAD;
                    }
                } else {
                    if (neighbors == 3) {
                        g->grid[i * COLS + j].alive = ALIVE;
                    }
                }
            }
        }
        g->generations++;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i, j;
    pthread_t thread;

    g = malloc(sizeof(game));
    g->grid = malloc(sizeof(cell) * ROWS * COLS);
    g->generations = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            g->grid[i * COLS + j].row = i;
            g->grid[i * COLS + j].col = j;
            g->grid[i * COLS + j].alive = rand() % 2;
        }
    }

    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread, NULL, run, NULL);

    while (1) {
        pthread_mutex_lock(&lock);
        printf("\nGeneration: %d", g->generations);
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                printf("%c ", g->grid[i * COLS + j].alive ? '#' : '.');
            }
            printf("\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(1);
    }

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&lock);
    free(g->grid);
    free(g);

    return 0;
}