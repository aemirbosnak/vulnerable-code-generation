//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define GRID_SIZE 100
#define CELL_SIZE 10

typedef struct cell {
    int x;
    int y;
    int state;
} cell_t;

typedef struct grid {
    cell_t** grid;
    int rows;
    int cols;
} grid_t;

void* thread_alive(void* arg) {
    grid_t* grid = arg;
    while (1) {
        // Loop until the grid is empty
        for (int i = 0; i < grid->rows; i++) {
            for (int j = 0; j < grid->cols; j++) {
                cell_t* cell = &grid->grid[i][j];
                if (cell->state == 1) {
                    // Alive cell, increment its neighbors
                    int neighbors = 0;
                    if (i - 1 >= 0 && grid->grid[i - 1][j].state == 1) {
                        neighbors++;
                    }
                    if (i + 1 < grid->rows && grid->grid[i + 1][j].state == 1) {
                        neighbors++;
                    }
                    if (j - 1 >= 0 && grid->grid[i][j - 1].state == 1) {
                        neighbors++;
                    }
                    if (j + 1 < grid->cols && grid->grid[i][j + 1].state == 1) {
                        neighbors++;
                    }
                    if (neighbors == 2 || neighbors == 3) {
                        cell->state = 1; // Alive cell stays alive
                    } else {
                        cell->state = 0; // Alive cell dies
                    }
                }
            }
        }
        usleep(1000); // Sleep for 1ms before checking again
    }
    return NULL;
}

int main() {
    pthread_t threads[GRID_SIZE];
    grid_t grid;

    // Initialize grid and create threads
    for (int i = 0; i < GRID_SIZE; i++) {
        pthread_create(&threads[i], NULL, thread_alive, &grid);
    }

    // Wait for all threads to finish
    for (int i = 0; i < GRID_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}