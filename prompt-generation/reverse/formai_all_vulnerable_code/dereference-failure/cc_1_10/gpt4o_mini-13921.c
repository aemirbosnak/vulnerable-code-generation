//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_THREADS 5
#define MAX_QUEUE_SIZE 20

typedef struct {
    void (*function)(void *);
    void *arg;
} Task;

typedef struct {
    Task taskQueue[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} TaskQueue;

typedef struct {
    pthread_t threads[MAX_THREADS];
    TaskQueue *taskQueue;
    int stop;
} ThreadPool;

void *worker(void *pool);

void initQueue(TaskQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->size = 0;
    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->cond, NULL);
}

int isQueueEmpty(TaskQueue *queue) {
    return queue->size == 0;
}

int isQueueFull(TaskQueue *queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(TaskQueue *queue, Task task) {
    pthread_mutex_lock(&queue->mutex);
    while (isQueueFull(queue)) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    queue->taskQueue[queue->rear] = task;
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->size++;
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
}

Task dequeue(TaskQueue *queue) {
    pthread_mutex_lock(&queue->mutex);
    while (isQueueEmpty(queue)) {
        pthread_cond_wait(&queue->cond, &queue->mutex);
    }
    Task task = queue->taskQueue[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    pthread_cond_signal(&queue->cond);
    pthread_mutex_unlock(&queue->mutex);
    return task;
}

ThreadPool *createThreadPool() {
    ThreadPool *pool = malloc(sizeof(ThreadPool));
    pool->taskQueue = malloc(sizeof(TaskQueue));
    initQueue(pool->taskQueue);
    pool->stop = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&pool->threads[i], NULL, worker, (void *)pool);
    }
    
    return pool;
}

void destroyThreadPool(ThreadPool *pool) {
    pool->stop = 1;
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(pool->threads[i], NULL);
    }
    free(pool->taskQueue);
    free(pool);
}

void *worker(void *pool) {
    ThreadPool *tPool = (ThreadPool *)pool;
    
    while (!tPool->stop) {
        Task task = dequeue(tPool->taskQueue);
        if (task.function) {
            task.function(task.arg);
        }
    }
    
    return NULL;
}

void exampleTask(void *arg) {
    int taskId = *(int *)arg;
    printf("Task %d is running.\n", taskId);
    sleep(1); // Simulate some work
    printf("Task %d is completed.\n", taskId);
}

int main() {
    ThreadPool *pool = createThreadPool();
    
    for (int i = 0; i < 10; i++) {
        int *taskId = malloc(sizeof(int));
        *taskId = i;
        Task task;
        task.function = exampleTask;
        task.arg = taskId;
        enqueue(pool->taskQueue, task);
    }
    
    sleep(5); // Allow time for tasks to finish
    destroyThreadPool(pool);
    
    return 0;
}