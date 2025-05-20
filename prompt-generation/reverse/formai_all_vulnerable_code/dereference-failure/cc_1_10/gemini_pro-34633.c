//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Data structure to represent a job
typedef struct job {
    int id;
    int size;
    int profit;
} job;

// Data structure to represent a thread pool
typedef struct thread_pool {
    pthread_t *threads;
    int num_threads;
    pthread_mutex_t lock;
    pthread_cond_t cond;
    job *jobs;
    int num_jobs;
} thread_pool;

// Function to compare jobs based on their profit-to-size ratio
int compare_jobs(const void *a, const void *b) {
    const job *job1 = (const job *)a;
    const job *job2 = (const job *)b;
    return (job2->profit - job1->profit) / (job2->size - job1->size);
}

// Function to initialize a thread pool
thread_pool *create_thread_pool(int num_threads) {
    thread_pool *pool = malloc(sizeof(thread_pool));
    pool->num_threads = num_threads;
    pool->threads = malloc(sizeof(pthread_t) * num_threads);
    pthread_mutex_init(&pool->lock, NULL);
    pthread_cond_init(&pool->cond, NULL);
    pool->jobs = NULL;
    pool->num_jobs = 0;
    return pool;
}

// Function to destroy a thread pool
void destroy_thread_pool(thread_pool *pool) {
    pthread_mutex_destroy(&pool->lock);
    pthread_cond_destroy(&pool->cond);
    free(pool->threads);
    if (pool->jobs != NULL) {
        free(pool->jobs);
    }
    free(pool);
}

// Function to add a job to the thread pool
void add_job(thread_pool *pool, job *job) {
    pthread_mutex_lock(&pool->lock);
    pool->jobs = realloc(pool->jobs, sizeof(job) * (pool->num_jobs + 1));
    pool->jobs[pool->num_jobs++] = *job;
    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->lock);
}

// Function to get a job from the thread pool
job *get_job(thread_pool *pool) {
    pthread_mutex_lock(&pool->lock);
    while (pool->num_jobs == 0) {
        pthread_cond_wait(&pool->cond, &pool->lock);
    }
    job *job = &pool->jobs[pool->num_jobs - 1];
    pool->num_jobs--;
    pthread_mutex_unlock(&pool->lock);
    return job;
}

// Function to run a thread in the thread pool
void *thread_function(void *arg) {
    thread_pool *pool = (thread_pool *)arg;
    while (1) {
        job *job = get_job(pool);
        // Process the job
        printf("Thread %d processing job %d\n", (int)pthread_self(), job->id);
        free(job);
    }
}

// Main function
int main() {
    // Create a thread pool with 4 threads
    thread_pool *pool = create_thread_pool(4);

    // Create a list of jobs
    job jobs[] = {
        {1, 10, 100},
        {2, 20, 200},
        {3, 30, 300},
        {4, 40, 400},
        {5, 50, 500},
    };

    // Sort the jobs based on their profit-to-size ratio
    qsort(jobs, sizeof(jobs) / sizeof(job), sizeof(job), compare_jobs);

    // Add the jobs to the thread pool
    for (int i = 0; i < sizeof(jobs) / sizeof(job); i++) {
        add_job(pool, &jobs[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < pool->num_threads; i++) {
        pthread_join(pool->threads[i], NULL);
    }

    // Destroy the thread pool
    destroy_thread_pool(pool);

    return 0;
}