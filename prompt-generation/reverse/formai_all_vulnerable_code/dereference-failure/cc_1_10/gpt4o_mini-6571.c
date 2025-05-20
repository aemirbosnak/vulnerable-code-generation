//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define NUM_TASKS 20

typedef struct {
    int task_id;
    int work_load;
} task_t;

typedef struct {
    task_t *tasks;
    int front, rear, capacity;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} task_queue_t;

task_queue_t queue;

void init_queue(int capacity) {
    queue.capacity = capacity;
    queue.front = queue.rear = 0;
    queue.tasks = (task_t *)malloc(capacity * sizeof(task_t));
    sem_init(&queue.empty, 0, 0);
    sem_init(&queue.full, 0, capacity);
    pthread_mutex_init(&queue.mutex, NULL);
}

void destroy_queue() {
    free(queue.tasks);
    sem_destroy(&queue.empty);
    sem_destroy(&queue.full);
    pthread_mutex_destroy(&queue.mutex);
}

void enqueue(task_t task) {
    sem_wait(&queue.full); // Wait if queue is full
    pthread_mutex_lock(&queue.mutex);
    
    queue.tasks[queue.rear] = task;
    queue.rear = (queue.rear + 1) % queue.capacity;

    pthread_mutex_unlock(&queue.mutex);
    sem_post(&queue.empty); // Signal that new task is available
}

task_t dequeue() {
    sem_wait(&queue.empty); // Wait if queue is empty
    pthread_mutex_lock(&queue.mutex);
    
    task_t task = queue.tasks[queue.front];
    queue.front = (queue.front + 1) % queue.capacity;

    pthread_mutex_unlock(&queue.mutex);
    sem_post(&queue.full); // Signal that space is available
    return task;
}

void *worker(void *arg) {
    int thread_id = *((int *)arg);
    while (1) {
        task_t task = dequeue();
        printf("Thread %d processing task %d with workload %d.\n", thread_id, task.task_id, task.work_load);
        sleep(task.work_load); // Simulate work
        printf("Thread %d finished processing task %d.\n", thread_id, task.task_id);
    }
    return NULL;
}

void create_tasks(int num_tasks) {
    for (int i = 0; i < num_tasks; i++) {
        task_t new_task;
        new_task.task_id = i;
        new_task.work_load = rand() % 3 + 1; // Workload between 1 and 3
            
        enqueue(new_task);
    }
}

int main() {
    srand(time(NULL));
    init_queue(NUM_TASKS);

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create worker threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, (void *)&thread_ids[i]);
    }

    // Create and enqueue tasks
    create_tasks(NUM_TASKS);

    // Allow some time for threads to process tasks
    sleep(10);

    // Cleanup and exit
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }

    destroy_queue();
    
    return 0;
}