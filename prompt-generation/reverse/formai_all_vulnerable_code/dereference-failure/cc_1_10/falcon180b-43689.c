//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

pthread_t threads[MAX_THREADS];
int thread_count = 0;

void *thread_func(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started\n", id);
    sleep(1);
    printf("Thread %d finished\n", id);
    return NULL;
}

int create_thread(int id) {
    pthread_attr_t attr;
    int rc;

    if (thread_count >= MAX_THREADS) {
        printf("Maximum number of threads reached\n");
        return -1;
    }

    rc = pthread_attr_init(&attr);
    if (rc!= 0) {
        printf("Error: unable to init attribute, %d\n", rc);
        return -1;
    }

    rc = pthread_attr_setstacksize(&attr, STACK_SIZE);
    if (rc!= 0) {
        printf("Error: unable to set stack size, %d\n", rc);
        return -1;
    }

    rc = pthread_create(&threads[thread_count], &attr, thread_func, (void *) id);
    if (rc!= 0) {
        printf("Error: unable to create thread, %d\n", rc);
        return -1;
    }

    thread_count++;
    return 0;
}

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        create_thread(i);
    }

    for (i = 0; i < 10; i++) {
        sleep(1);
    }

    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}