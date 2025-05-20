//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_TASKS 10
#define STACK_SIZE 100

typedef struct task {
    void (*func)(void *param);
    void *param;
    struct task *next;
} Task;

typedef struct {
    Task *head;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} TaskQueue;

static TaskQueue task_queue = { NULL, PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER };

void task_queue_push(Task *task) {
    pthread_mutex_lock(&task_queue.mutex);
    task->next = task_queue.head;
    task_queue.head = task;
    pthread_mutex_unlock(&task_queue.mutex);
    pthread_cond_signal(&task_queue.cond);
}

Task *task_queue_pop() {
    Task *task = NULL;
    pthread_mutex_lock(&task_queue.mutex);
    while (task_queue.head == NULL) {
        pthread_cond_wait(&task_queue.cond, &task_queue.mutex);
    }
    task = task_queue.head;
    task_queue.head = task->next;
    pthread_mutex_unlock(&task_queue.mutex);
    return task;
}

void *task_thread(void *arg) {
    Task *task = arg;
    task->func(task->param);
    free(task);
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_TASKS];

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_thread, NULL);
    }

    while (1) {
        int choice;
        printf("Enter your choice:\n");
        printf("1. Add task\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            void (*func)(void *param);
            void *param;
            printf("Enter the function to execute:\n");
            scanf("%p", &func);
            printf("Enter the parameter for the function:\n");
            scanf("%p", &param);

            Task *task = malloc(sizeof(Task));
            task->func = func;
            task->param = param;

            task_queue_push(task);
        } else if (choice == 2) {
            break;
        }
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}