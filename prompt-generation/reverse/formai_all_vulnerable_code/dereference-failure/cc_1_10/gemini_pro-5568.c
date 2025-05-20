//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

// Task structure
typedef struct task {
    char *name;
    int (*func)(void *arg);
    void *arg;
    struct task *next;
} task_t;

// Task queue
task_t *head = NULL;
task_t *tail = NULL;

// Task lock
pthread_mutex_t task_lock = PTHREAD_MUTEX_INITIALIZER;

// Task condition variable
pthread_cond_t task_cond = PTHREAD_COND_INITIALIZER;

// Add a task to the queue
void add_task(char *name, int (*func)(void *arg), void *arg) {
    task_t *new_task = malloc(sizeof(task_t));
    new_task->name = strdup(name);
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    pthread_mutex_lock(&task_lock);

    if (head == NULL) {
        head = new_task;
        tail = new_task;
    } else {
        tail->next = new_task;
        tail = new_task;
    }

    pthread_mutex_unlock(&task_lock);

    pthread_cond_signal(&task_cond);
}

// Remove a task from the queue
task_t *remove_task() {
    task_t *task = NULL;

    pthread_mutex_lock(&task_lock);

    if (head != NULL) {
        task = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
    }

    pthread_mutex_unlock(&task_lock);

    return task;
}

// Task scheduler thread
void *task_scheduler(void *arg) {
    while (1) {
        pthread_mutex_lock(&task_lock);

        while (head == NULL) {
            pthread_cond_wait(&task_cond, &task_lock);
        }

        task_t *task = remove_task();

        pthread_mutex_unlock(&task_lock);

        task->func(task->arg);

        free(task->name);
        free(task);
    }

    return NULL;
}

// Example task 1
int task1(void *arg) {
    printf("Task 1: %s\n", (char *)arg);
    return 0;
}

// Example task 2
int task2(void *arg) {
    printf("Task 2: %d\n", *(int *)arg);
    return 0;
}

int main() {
    // Create task scheduler thread
    pthread_t task_scheduler_thread;
    pthread_create(&task_scheduler_thread, NULL, task_scheduler, NULL);

    // Add tasks to the queue
    add_task("Task 1", task1, "Hello world!");
    add_task("Task 2", task2, malloc(sizeof(int)));
    *(int *)malloc(sizeof(int)) = 42;

    // Wait for tasks to complete
    pthread_join(task_scheduler_thread, NULL);

    return 0;
}