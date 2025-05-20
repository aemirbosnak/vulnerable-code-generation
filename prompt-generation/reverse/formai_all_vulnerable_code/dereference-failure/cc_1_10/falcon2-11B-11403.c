//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *worker(void *data) {
    int *job_id = (int *)data;
    int job_count = *job_id;

    while (job_count-- > 0) {
        // Do some work...
        printf("Worker %d: Working on task %d\n", pthread_self(), *job_id);

        // Update the job_id
        job_id++;
    }

    pthread_exit(NULL);
}

int main() {
    int job_count = 10;
    int *job_ids = (int *)malloc(sizeof(int) * job_count);

    for (int i = 0; i < job_count; i++) {
        job_ids[i] = i;
    }

    pthread_t threads[job_count];
    int err = pthread_create(&threads[0], NULL, worker, (void *)&job_ids[0]);

    if (err!= 0) {
        printf("Failed to create thread\n");
        return -1;
    }

    for (int i = 1; i < job_count; i++) {
        err = pthread_create(&threads[i], NULL, worker, (void *)&job_ids[i]);

        if (err!= 0) {
            printf("Failed to create thread\n");
            return -1;
        }
    }

    for (int i = 0; i < job_count; i++) {
        err = pthread_join(threads[i], NULL);

        if (err!= 0) {
            printf("Failed to join thread\n");
            return -1;
        }
    }

    printf("All tasks completed successfully\n");

    return 0;
}