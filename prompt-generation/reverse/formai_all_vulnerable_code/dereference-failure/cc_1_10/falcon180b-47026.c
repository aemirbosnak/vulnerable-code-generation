//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold thread data
struct thread_data {
    int id;
    char *name;
};

// Function to be executed by each thread
void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;

    // Print thread information
    printf("Thread %d (%s) started.\n", data->id, data->name);

    // Sleep for a random amount of time
    int delay = rand() % 5 + 1;
    printf("Thread %d (%s) sleeping for %d seconds.\n", data->id, data->name, delay);
    sleep(delay);

    // Print thread information
    printf("Thread %d (%s) finished.\n", data->id, data->name);

    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    struct thread_data data[num_threads];

    // Initialize thread data
    for (int i = 0; i < num_threads; i++) {
        data[i].id = i + 1;
        data[i].name = (char *) malloc(10 * sizeof(char));
        sprintf(data[i].name, "Thread %d", i + 1);
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}