//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10 // Size of the grid
#define NUM_THREADS 4 // Number of threads

typedef struct {
    int row;
    int col;
    bool **grid;
    int *sites_opened;
    pthread_mutex_t *mutex;
} thread_data_t;

void *open_sites(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    srand(time(NULL) ^ pthread_self()); // Seed with thread id for randomness
    for (int i = 0; i < data->sites_opened[data->row]; i++) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;

        pthread_mutex_lock(data->mutex);
        if (!data->grid[r][c]) {
            data->grid[r][c] = true;
            printf("Thread %ld opened site (%d, %d)\n", pthread_self(), r, c);
        }
        pthread_mutex_unlock(data->mutex);
    }
    return NULL;
}

void initialize_grid(bool **grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = false; // All sites are initially blocked
        }
    }
}

void print_grid(bool **grid) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%s ", grid[i][j] ? "O" : "X");
        }
        printf("\n");
    }
}

int main() {
    // Allocate grid
    bool **grid = malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; i++)
        grid[i] = malloc(SIZE * sizeof(bool));

    initialize_grid(grid);

    // Prepare data for threads
    pthread_t threads[NUM_THREADS];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    thread_data_t thread_data[NUM_THREADS];
    int sites_per_thread = (SIZE * SIZE) / NUM_THREADS;
    
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].row = i;
        thread_data[i].col = i % SIZE;
        thread_data[i].grid = grid;
        thread_data[i].sites_opened = malloc(NUM_THREADS * sizeof(int));
        thread_data[i].sites_opened[i] = sites_per_thread;
        thread_data[i].mutex = &mutex;

        pthread_create(&threads[i], NULL, open_sites, (void *)&thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        free(thread_data[i].sites_opened);
    }

    // Print the final state of the grid
    printf("Final grid state:\n");
    print_grid(grid);

    // Free allocated memory
    for (int i = 0; i < SIZE; i++)
        free(grid[i]);
    free(grid);
    
    pthread_mutex_destroy(&mutex);
    return 0;
}