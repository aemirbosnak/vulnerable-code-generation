//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int sum;
    pthread_mutex_t mutex;
};

void *runner(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    struct v *shared = malloc(sizeof(struct v));

    shared->sum = 0;
    pthread_mutex_init(&shared->mutex, NULL);

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, shared);
        if (rc) {
            printf("Error:unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error:unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("The sum is: %d\n", shared->sum);

    return 0;
}

void *runner(void *param) {
    int i = 0;
    struct v *shared = param;

    pthread_mutex_lock(&shared->mutex);
    shared->sum += i;
    pthread_mutex_unlock(&shared->mutex);

    return NULL;
}