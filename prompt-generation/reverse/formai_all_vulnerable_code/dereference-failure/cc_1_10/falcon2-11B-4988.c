//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_THREADS 10

int* jobs;
int* job_sizes;
sem_t* job_sem;
sem_t* finish_sem;

void* thread_job(void* arg) {
    int thread_id = (int) arg;
    int job_id = jobs[thread_id];
    int size = job_sizes[thread_id];

    sem_wait(job_sem);
    sem_wait(finish_sem);

    for (int i = 0; i < size; i++) {
        sem_post(finish_sem);
        printf("Thread %d is processing job %d\n", thread_id, job_id);
    }

    sem_post(finish_sem);
    return NULL;
}

int main(int argc, char* argv[]) {
    int n_jobs = 5;
    int n_threads = 3;
    int job_size[n_jobs];

    jobs = (int*) malloc(n_jobs * sizeof(int));
    job_sizes = (int*) malloc(n_jobs * sizeof(int));

    for (int i = 0; i < n_jobs; i++) {
        job_size[i] = rand() % 100 + 1;
        jobs[i] = i;
    }

    job_sem = (sem_t*) malloc(MAX_THREADS * sizeof(sem_t));
    finish_sem = (sem_t*) malloc(MAX_THREADS * sizeof(sem_t));

    for (int i = 0; i < MAX_THREADS; i++) {
        sem_init(job_sem + i, 0, 0);
        sem_init(finish_sem + i, 0, 0);
    }

    pthread_t threads[n_threads];

    for (int i = 0; i < n_threads; i++) {
        int thread_id = i;
        pthread_create(&threads[thread_id], NULL, thread_job, (void*) thread_id);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        sem_destroy(job_sem + i);
        sem_destroy(finish_sem + i);
    }

    free(jobs);
    free(job_sizes);

    return 0;
}