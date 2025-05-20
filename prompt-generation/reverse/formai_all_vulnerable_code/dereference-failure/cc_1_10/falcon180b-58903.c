//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

struct thread_data {
    int thread_id;
    void *(*func)(void *);
    void *arg;
};

void *thread_function(void *data) {
    struct thread_data *tdata = (struct thread_data *) data;
    void *result = tdata->func(tdata->arg);
    printf("Thread %d finished execution\n", tdata->thread_id);
    pthread_exit(result);
}

int create_thread(pthread_t *thread, void *(*func)(void *), void *arg) {
    struct thread_data *tdata = malloc(sizeof(struct thread_data));
    if (tdata == NULL) {
        printf("Error: Unable to allocate memory for thread data\n");
        return -1;
    }
    tdata->thread_id = *thread;
    tdata->func = func;
    tdata->arg = arg;
    if (pthread_create(thread, NULL, thread_function, tdata)!= 0) {
        printf("Error: Unable to create thread\n");
        free(tdata);
        return -1;
    }
    return 0;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, ret;
    void *result;

    for (i = 0; i < MAX_THREADS; i++) {
        ret = create_thread(&threads[i], &thread_function, (void *) i);
        if (ret!= 0) {
            printf("Error: Unable to create thread %d\n", i);
            return -1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        ret = pthread_join(threads[i], &result);
        if (ret!= 0) {
            printf("Error: Unable to join thread %d\n", i);
            return -1;
        }
    }

    printf("All threads finished execution\n");
    return 0;
}