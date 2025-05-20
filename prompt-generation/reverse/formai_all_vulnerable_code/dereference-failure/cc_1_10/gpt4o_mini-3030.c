//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

typedef struct {
    int thread_id;
    int num_lines;
} ThreadData;

void *printPattern(void *data) {
    ThreadData *t_data = (ThreadData *)data;
    int id = t_data->thread_id;
    int lines = t_data->num_lines;

    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", id);
        }
        printf("\n");
        sleep(1);  // Sleep to simulate work and make output readable
    }

    pthread_exit(NULL);
}

void *printStars(void *data) {
    int thread_id = *(int *)data;
    int rows = 5; // Fixed number of rows for stars

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
        sleep(1); // Sleep to simulate work and make output readable
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int rc;
    int star_thread_id = NUM_THREADS; // Star pattern thread ID

    // Create threads for printing numbers in patterns
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].thread_id = i + 1; // Thread IDs: 1 to NUM_THREADS
        threadData[i].num_lines = i + 3; // Number of lines varies
        rc = pthread_create(&threads[i], NULL, printPattern, (void *)&threadData[i]);

        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Create a thread to print stars
    rc = pthread_create(&threads[NUM_THREADS], NULL, printStars, (void *)&star_thread_id);
    if (rc) {
        fprintf(stderr, "Error creating star thread: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    // Wait for all threads to finish
    for (int i = 0; i <= NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All patterns printed successfully!\n");
    pthread_exit(NULL);
}