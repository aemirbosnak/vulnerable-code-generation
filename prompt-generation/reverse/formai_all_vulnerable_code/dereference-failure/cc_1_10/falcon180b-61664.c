//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

typedef struct task {
    void (*func)(void *);
    void *arg;
    struct task *next;
} task_t;

task_t *task_list = NULL;
pthread_t thread_id[MAX_TASKS];
int task_count = 0;

void add_task(void (*func)(void *), void *arg) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));
    if (new_task == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        task_t *temp = task_list;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }

    task_count++;
}

void *task_thread(void *param) {
    task_t *task = (task_t *) param;
    task->func(task->arg);
    free(task);
    return NULL;
}

int main() {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, STACK_SIZE);

    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        pthread_create(&thread_id[i], &attr, task_thread, NULL);
    }

    while (1) {
        printf("Enter 1 to add a task or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            void (*func)(void *) = NULL;
            void *arg = NULL;

            printf("Enter the function to execute: ");
            scanf("%p", &func);

            printf("Enter the argument for the function: ");
            scanf("%p", &arg);

            add_task(func, arg);
        }
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}