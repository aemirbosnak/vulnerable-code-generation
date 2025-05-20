//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_THREADS 5
#define BAG_SIZE 4

// Global variables
int bags[NUM_BAGS];
int num_threads;
int num_bags;
int thread_id;
int bag_size;
int *thread_args;

void *bag_handler(void *arg);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // Initialize variables
    num_threads = NUM_THREADS;
    num_bags = NUM_BAGS;
    bag_size = BAG_SIZE;
    thread_args = malloc(num_threads * sizeof(int));

    // Generate random baggage
    for (int i = 0; i < num_bags; i++) {
        bags[i] = rand() % 10; // Random value between 0 and 9
    }

    // Create threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, bag_handler, (void *)&thread_args[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All bags have been processed.\n");
    free(thread_args);
    return 0;
}

void *bag_handler(void *arg) {
    int thread_id = *((int *) arg);
    int start_index = thread_id * bag_size;
    int end_index = (thread_id + 1) * bag_size;

    for (int i = start_index; i < end_index; i++) {
        if (i >= num_bags) {
            break;
        }
        printf("Thread %d is processing bag %d\n", thread_id, bags[i]);
    }

    return NULL;
}