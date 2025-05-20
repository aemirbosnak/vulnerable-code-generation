//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

// Task structure
typedef struct {
    int id;
    int priority;
    int duration;
} Task;

// Task queue
typedef struct {
    Task tasks[MAX_TASKS];
    int front;
    int rear;
} TaskQueue;

// Initialize task queue
void initQueue(TaskQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

// Check if task queue is empty
int isEmpty(TaskQueue *queue) {
    return queue->rear == -1;
}

// Check if task queue is full
int isFull(TaskQueue *queue) {
    return queue->rear == MAX_TASKS - 1;
}

// Add task to queue
void addTask(TaskQueue *queue, Task task) {
    if (isFull(queue)) {
        printf("Task queue is full\n");
        return;
    }
    queue->tasks[++queue->rear] = task;
}

// Remove task from queue
Task removeTask(TaskQueue *queue) {
    Task task;
    if (isEmpty(queue)) {
        printf("Task queue is empty\n");
        return (Task){0, 0, 0};
    }
    task = queue->tasks[queue->front++];
    return task;
}

// Task scheduler
void *taskScheduler(void *arg) {
    TaskQueue *queue = arg;
    while (1) {
        Task task = removeTask(queue);
        printf("Executing task %d with priority %d\n", task.id, task.priority);
        sleep(task.duration);
    }
    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    pthread_t thread_id;
    TaskQueue queue;
    initQueue(&queue);

    // Add tasks to queue
    addTask(&queue, (Task){1, 2, 3});
    addTask(&queue, (Task){2, 1, 2});
    addTask(&queue, (Task){3, 3, 1});

    // Create task scheduler thread
    pthread_create(&thread_id, NULL, taskScheduler, &queue);

    // Wait for task scheduler to finish
    pthread_join(thread_id, NULL);

    return 0;
}