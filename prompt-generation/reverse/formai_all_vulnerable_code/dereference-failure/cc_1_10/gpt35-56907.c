//FormAI DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 100
#define COLS 100
#define NUM_THREADS 4

struct thread_args {
    unsigned char *image;
    int start_row;
    int end_row;
};

void *thread_function(void *arg) {
    struct thread_args *t_args = (struct thread_args *) arg;

    for (int i = t_args->start_row; i <= t_args->end_row; i++) {
        for (int j = 0; j < COLS; j++) {
            int pixel_index = (i * COLS) + j; // calculate pixel index
            
            // Perform image editing operation
            t_args->image[pixel_index] = t_args->image[pixel_index] + 50;
        }
    }

    pthread_exit(NULL);
}

int main() {
    // Allocate image memory
    unsigned char *image = (unsigned char *) malloc(ROWS * COLS * sizeof(unsigned char));

    // Initialize image with random values
    for (int i = 0; i < ROWS * COLS; i++) {
        image[i] = rand() % 256;
    }

    // Initialize thread arguments
    struct thread_args args[NUM_THREADS];
    int rows_per_thread = (ROWS + NUM_THREADS - 1) / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].image = image;
        args[i].start_row = i * rows_per_thread;
        args[i].end_row = (i + 1) * rows_per_thread - 1;

        if (args[i].end_row >= ROWS) {
            args[i].end_row = ROWS - 1;
        }
    }

    // Create and execute threads
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &args[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print modified image
    printf("Modified Image:\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[(i * COLS) + j]);
        }

        printf("\n");
    }

    // Free image memory
    free(image);

    return 0;
}