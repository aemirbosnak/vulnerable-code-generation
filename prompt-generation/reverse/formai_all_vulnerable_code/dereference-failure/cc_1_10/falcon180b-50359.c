//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_WORKERS 10
#define MAX_JOBS 100

typedef struct {
    int id;
    int job_id;
    int status;
} Worker;

typedef struct {
    int id;
    int status;
} Job;

typedef struct {
    Worker workers[MAX_WORKERS];
    Job jobs[MAX_JOBS];
    pthread_t threads[MAX_WORKERS];
    sem_t job_sem;
} ThreadPool;

void *worker(void *arg) {
    Worker *worker = arg;
    while (1) {
        sem_wait(&((ThreadPool *)worker->job_id)->job_sem);
        Job *job = &((ThreadPool *)worker->job_id)->jobs[worker->job_id];
        if (job->status == 1) {
            printf("Worker %d is processing job %d\n", worker->id, job->id);
            sleep(2);
            job->status = 0;
        }
    }
    return NULL;
}

void *manager(void *arg) {
    ThreadPool *pool = arg;
    while (1) {
        sleep(1);
        for (int i = 0; i < MAX_WORKERS; i++) {
            if (pool->workers[i].status == 0) {
                int job_id = i;
                while (pool->jobs[job_id].status == 1) {
                    job_id = (job_id + 1) % MAX_JOBS;
                }
                pool->jobs[job_id].status = 1;
                pool->workers[i].job_id = job_id;
                pool->workers[i].status = 1;
                printf("Manager assigned job %d to worker %d\n", job_id, i);
                break;
            }
        }
    }
    return NULL;
}

int main() {
    ThreadPool *pool = malloc(sizeof(ThreadPool));
    for (int i = 0; i < MAX_WORKERS; i++) {
        pool->workers[i].id = i;
        pool->workers[i].status = 0;
        pthread_create(&pool->threads[i], NULL, worker, &i);
    }
    for (int i = 0; i < MAX_JOBS; i++) {
        pool->jobs[i].id = i;
        pool->jobs[i].status = 0;
    }
    pthread_create(&pool->threads[MAX_WORKERS], NULL, manager, pool);
    while (1) {
        sleep(10);
    }
    return 0;
}