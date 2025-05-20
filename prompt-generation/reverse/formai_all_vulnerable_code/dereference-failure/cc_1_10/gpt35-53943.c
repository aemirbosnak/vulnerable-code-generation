//FormAI DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// A task struct
typedef struct task {
    int taskId;
    int priority;
    void (*function)(void);
    struct task *next;
} Task;

// A queue struct
typedef struct queue {
    Task *head;
    Task *tail;
    int size;
    pthread_mutex_t lock;
} Queue;

// A function to create a new task
Task *newTask(int taskId, int priority, void (*function)(void)) {
    Task *task = (Task *) malloc(sizeof(Task));
    task->taskId = taskId;
    task->priority = priority;
    task->function = function;
    task->next = NULL;
    return task;
}

// A function to create a new queue
Queue *newQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    pthread_mutex_init(&queue->lock, NULL);
    return queue;
}

// A function to add a task to the queue
void enqueue(Queue *queue, Task *task) {
    pthread_mutex_lock(&queue->lock);
    if (queue->tail == NULL) {
        queue->head = task;
        queue->tail = task;
    } else {
        Task *p = queue->head;
        Task *prev = NULL;
        while (p != NULL && p->priority <= task->priority) {
            prev = p;
            p = p->next;
        }
        if (prev == NULL) {
            queue->head = task;
        } else {
            prev->next = task;
        }
        task->next = p;
        if (p == NULL) {
            queue->tail = task;
        }
    }
    queue->size++;
    pthread_mutex_unlock(&queue->lock);
}

// A function to get the highest priority task from the queue
Task *dequeue(Queue *queue) {
    pthread_mutex_lock(&queue->lock);
    Task *task = NULL;
    if (queue->head != NULL) {
        task = queue->head;
        queue->head = task->next;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        queue->size--;
    }
    pthread_mutex_unlock(&queue->lock);
    return task;
}

// A function to do some work
void work() {
    printf("Task %ld is running\n", pthread_self());
    sleep(rand() % 5);
}

// A function to create some random tasks and add them to the queue
void createTasks(Queue *queue) {
    for (int i = 1; i <= 10; i++) {
        int priority = rand() % 3 + 1;
        Task *task = newTask(i, priority, work);
        enqueue(queue, task);
        printf("Task %d with priority %d added to the queue\n", i, priority);
    }
}

// The main function
int main() {
    srand(time(NULL));
    Queue *queue = newQueue();
    createTasks(queue);
    while (queue->size > 0) {
        Task *task = dequeue(queue);
        if (task != NULL) {
            printf("Task %d with priority %d dequeued\n", task->taskId, task->priority);
            task->function();
            free(task);
        }
    }
    free(queue);
    return 0;
}