//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_WORKERS 5
#define TASKS_PER_WORKER 10

typedef struct {
    int worker_id;
    int task_id;
} Task;

typedef struct {
    Task *tasks;
    int task_count;
    pthread_mutex_t lock;
} TaskQueue;

void *worker_function(void *arg) {
    TaskQueue *task_queue = (TaskQueue *)arg;
    for (int i = 0; i < TASKS_PER_WORKER; i++) {
        pthread_mutex_lock(&task_queue->lock);
        if (task_queue->task_count > 0) {
            Task task = task_queue->tasks[--task_queue->task_count];
            pthread_mutex_unlock(&task_queue->lock);
            
            printf("Worker %d performing Task %d\n", task.worker_id, task.task_id);
            // Simulate some work
            sleep(rand() % 2);
        } else {
            pthread_mutex_unlock(&task_queue->lock);
            break;
        }
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    // Prepare task queue
    TaskQueue task_queue;
    task_queue.tasks = malloc(NUM_WORKERS * TASKS_PER_WORKER * sizeof(Task));
    task_queue.task_count = NUM_WORKERS * TASKS_PER_WORKER;
    pthread_mutex_init(&task_queue.lock, NULL);

    // Initialize tasks
    for (int i = 0; i < NUM_WORKERS; i++) {
        for (int j = 0; j < TASKS_PER_WORKER; j++) {
            task_queue.tasks[i * TASKS_PER_WORKER + j].worker_id = i;
            task_queue.tasks[i * TASKS_PER_WORKER + j].task_id = j;
        }
    }

    // Create worker threads
    pthread_t workers[NUM_WORKERS];
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_create(&workers[i], NULL, worker_function, (void *)&task_queue);
    }

    // Wait for worker threads to finish
    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }

    // Clean up
    pthread_mutex_destroy(&task_queue.lock);
    free(task_queue.tasks);

    printf("All tasks completed!\n");
    return 0;
}