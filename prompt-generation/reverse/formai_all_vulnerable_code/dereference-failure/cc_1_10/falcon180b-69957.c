//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    char name[20];
    int priority;
    void (*function)(void *arg);
    void *arg;
    struct task *next;
} task_t;

void add_task(task_t **head, char *name, int priority, void (*function)(void *arg), void *arg) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->function = function;
    new_task->arg = arg;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
        return;
    }

    task_t *current = *head;
    while (current->next!= NULL && current->next->priority >= priority) {
        current = current->next;
    }

    new_task->next = current->next;
    current->next = new_task;
}

void execute_tasks(task_t *head) {
    while (head!= NULL) {
        head->function(head->arg);
        head = head->next;
    }
}

void *task_thread(void *arg) {
    task_t *task = (task_t *) arg;
    task->function(task->arg);
    pthread_exit(0);
}

int main() {
    task_t *head = NULL;

    add_task(&head, "Task 1", 5, (void (*)(void *)) printf, "Hello, World!");
    add_task(&head, "Task 2", 3, (void (*)(void *)) printf, "How are you?");
    add_task(&head, "Task 3", 7, (void (*)(void *)) printf, "I'm doing great!");

    execute_tasks(head);

    pthread_t threads[MAX_TASKS];
    int count = 0;

    while (head!= NULL) {
        task_t *task = head;
        head = head->next;

        pthread_create(&threads[count], NULL, task_thread, task);
        count++;
    }

    for (int i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}