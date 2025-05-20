//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 10          // Size of the grid
#define NUM_THREADS 5 // Number of threads to operate on the grid

typedef struct {
    int **grid;
    int thread_id;
    int iterations;
} ThreadData;

void initialize_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0; // Initialize grid to be blocked
        }
    }
}

void print_grid(int **grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void *percolate(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int **grid = data->grid;
    int iterations = data->iterations;

    srand(time(NULL) ^ (data->thread_id)); // Seed for randomness using thread id

    for (int k = 0; k < iterations; k++) {
        int x = rand() % N;
        int y = rand() % N;

        // Open a site
        grid[x][y] = 1; // Mark site as open
        
        // Simulating percolation (not a complete algorithm)
        if (x == N-1 || (x > 0 && grid[x-1][y] == 1) || (x < N-1 && grid[x+1][y] == 1) || 
            (y > 0 && grid[x][y-1] == 1) || (y < N-1 && grid[x][y+1] == 1)) {
            printf("Thread %d opened site (%d, %d)\n", data->thread_id, x, y);
        }
        
        // Print the grid state every so often for visualization
        if (k % 10 == 0) {
            printf("Grid state after %d iterations by thread %d:\n", k, data->thread_id);
            print_grid(grid);
        }

        usleep(100000); // Sleep for a short while to visualize
    }
    return NULL;
}

int main() {
    // Allocate grid
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
    }
    initialize_grid(grid);

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    // Start percolation threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].grid = grid;
        thread_data[i].thread_id = i;
        thread_data[i].iterations = 50; // Each thread will run for 50 iterations

        pthread_create(&threads[i], NULL, percolate, (void *)&thread_data[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}