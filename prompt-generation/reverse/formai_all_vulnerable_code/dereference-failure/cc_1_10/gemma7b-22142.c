//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int execution_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, int execution_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->execution_time = execution_time;
    newTask->next = NULL;

    return newTask;
}

void addTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        newTask->next = head;
        head = newTask;
    }
}

void executeTasks(Task* head) {
    time_t start_time = time(NULL);
    Task* currentTask = head;

    while (currentTask) {
        int remaining_time = currentTask->execution_time - (time(NULL) - start_time);

        if (remaining_time > 0) {
            printf("Executing task: %s, remaining time: %d\n", currentTask->name, remaining_time);
            sleep(remaining_time);
        } else {
            printf("Task: %s completed.\n", currentTask->name);
            free(currentTask);
            currentTask = currentTask->next;
        }
    }

    printf("All tasks completed.\n");
}

int main() {
    Task* head = NULL;
    addTask(head, createTask("Task 1", 1, 5));
    addTask(head, createTask("Task 2", 2, 3));
    addTask(head, createTask("Task 3", 1, 2));

    executeTasks(head);

    return 0;
}