//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    void (*func)(void);
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, void (*func)(void)) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->func = func;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        head->next = newTask;
    }
}

void scheduler() {
    Task* currentTask = head;

    while (currentTask) {
        printf("Executing task: %s\n", currentTask->name);
        currentTask->func();
        currentTask = currentTask->next;
    }
}

void task1() {
    printf("Task 1 is running\n");
}

void task2() {
    printf("Task 2 is running\n");
}

void task3() {
    printf("Task 3 is running\n");
}

int main() {
    addTask("Task 1", task1);
    addTask("Task 2", task2);
    addTask("Task 3", task3);

    scheduler();

    return 0;
}