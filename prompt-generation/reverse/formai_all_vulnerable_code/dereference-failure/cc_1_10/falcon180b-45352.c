//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10

char *fortunes[NUM_THREADS] = {
    "You will meet someone special today. ",
    "A financial opportunity is coming your way. ",
    "You will receive good news from a friend. ",
    "A new adventure awaits you. ",
    "You will overcome a challenge successfully. ",
    "Your hard work will pay off soon. ",
    "You will experience a moment of great joy. ",
    "A pleasant surprise is in store for you. ",
    "You will find peace and tranquility. ",
    "Your creativity will be rewarded. "
};

struct thread_data {
    int thread_id;
    char *fortune;
};

void *thread_function(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int sleep_time = rand() % 5 + 1; // sleep for a random time between 1 and 5 seconds
    printf("Thread %d is sleeping for %d seconds...\n", data->thread_id, sleep_time);
    sleep(sleep_time);
    printf("Thread %d woke up and your fortune is: %s\n", data->thread_id, data->fortune);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    srand(time(NULL)); // seed the random number generator with the current time

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
        data->thread_id = i + 1; // thread IDs start from 1
        data->fortune = fortunes[i];
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) data);
        if (rc) {
            printf("Error: unable to create thread %d, %s\n", i + 1, strerror(rc));
            exit(1);
        }
    }

    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread %d, %s\n", i + 1, strerror(rc));
            exit(1);
        }
    }

    return 0;
}