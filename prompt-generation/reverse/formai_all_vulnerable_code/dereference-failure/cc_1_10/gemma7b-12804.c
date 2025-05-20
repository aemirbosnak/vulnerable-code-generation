//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct Task {
    char *name;
    int (*func)(void);
    struct Task *next;
} Task;

void addTask(Task **head, char *name, int (*func)(void)) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->func = func;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void executeTasks(Task *head) {
    while (head) {
        printf("Executing task: %s\n", head->name);
        head->func();
        sleep(1);
        head = head->next;
    }
}

int task1() {
    return 1;
}

int task2() {
    return 2;
}

int task3() {
    return 3;
}

int main() {
    Task *head = NULL;
    addTask(&head, "Task 1", task1);
    addTask(&head, "Task 2", task2);
    addTask(&head, "Task 3", task3);

    executeTasks(head);

    return 0;
}