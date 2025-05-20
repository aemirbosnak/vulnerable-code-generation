//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;
    char **names = malloc(NUM_THREADS * sizeof(char*));

    for (int i = 0; i < NUM_THREADS; i++) {
        names[i] = malloc(10 * sizeof(char));
        sprintf(names[i], "Thread %d", i+1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_function, (void*)names[i]);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
        thread_ids[i] = rc;
        printf("Created thread %d with id %d\n", i+1, thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join with thread, %d\n", rc);
            exit(-1);
        }
        printf("Joined with thread %d\n", i+1);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}

void *thread_function(void *param) {
    char *name = param;
    printf("Thread %s started.\n", name);
    sleep(1);
    printf("Thread %s finished.\n", name);
    return NULL;
}