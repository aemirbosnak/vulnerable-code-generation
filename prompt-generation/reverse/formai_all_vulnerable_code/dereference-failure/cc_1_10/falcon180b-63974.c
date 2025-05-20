//Falcon-180B DATASET v1.0 Category: Mortgage Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define MAX_THREADS 10

struct thread_data {
    int start;
    int end;
};

void *runner(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int start = data->start;
    int end = data->end;

    for (int i = start; i <= end; i++) {
        printf("Thread %d is working on number %d\n", pthread_self(), i);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;

    for (i = 0; i < MAX_THREADS; i++) {
        struct thread_data data;
        data.start = i * 10;
        data.end = (i + 1) * 10 - 1;

        rc = pthread_create(&threads[i], NULL, runner, (void *) &data);
        if (rc) {
            printf("Trouble with pthread_create for thread %d, return code %d\n", i, rc);
            exit(1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Trouble with pthread_join for thread %d, return code %d\n", i, rc);
            exit(1);
        }
    }

    return 0;
}