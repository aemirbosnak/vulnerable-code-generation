//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define SIZE 30
#define THREAD_COUNT 4

typedef struct {
    int **grid;
    int start_row;
    int end_row;
    pthread_mutex_t *lock;
} thread_data;

int is_open(int **grid, int x, int y) {
    return grid[x][y] == 1;
}

void *percolate(void *arg) {
    thread_data *data = (thread_data *)arg;
    int **grid = data->grid;
    int start_row = data->start_row;
    int end_row = data->end_row;
    pthread_mutex_lock(data->lock);

    for (int row = start_row; row < end_row; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (is_open(grid, row, col)) {
                // Simulate percolation (checking if it connects to the bottom)
                if (row == SIZE - 1) {
                    printf("Liquid percolates through at (%d, %d)\n", row, col);
                }
            }
        }
    }

    pthread_mutex_unlock(data->lock);
    return NULL;
}

int **create_grid() {
    int **grid = (int **)malloc(SIZE * sizeof(int *));
    for (int i = 0; i < SIZE; i++) {
        grid[i] = (int *)malloc(SIZE * sizeof(int));
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2; // Randomly open or blocked cells
        }
    }
    return grid;
}

void display_grid(int **grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void free_grid(int **grid) {
    for (int i = 0; i < SIZE; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main() {
    srand(time(NULL));
    
    int **grid = create_grid();
    display_grid(grid);
    
    pthread_t threads[THREAD_COUNT];
    pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);

    int rows_per_thread = SIZE / THREAD_COUNT;
    thread_data thread_args[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_args[i].grid = grid;
        thread_args[i].start_row = i * rows_per_thread;
        thread_args[i].end_row = (i + 1) * rows_per_thread;
        thread_args[i].lock = &lock;
        pthread_create(&threads[i], NULL, percolate, &thread_args[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    free_grid(grid);

    return 0;
}