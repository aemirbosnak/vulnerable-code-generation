//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    struct Task *next;
} Task;

void addTask(Task **head, char *name, int priority) {
    Task *newTask = (Task *)malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task *head) {
    time_t now = time(NULL);
    Task *currentTask = head;

    while (currentTask) {
        if (now >= currentTask->priority) {
            printf("Executing task: %s\n", currentTask->name);
            sleep(2);
            printf("Task %s completed.\n", currentTask->name);
            currentTask = currentTask->next;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task *head = NULL;

    addTask(head, "Task 1", 10);
    addTask(head, "Task 2", 5);
    addTask(head, "Task 3", 15);
    addTask(head, "Task 4", 2);

    scheduleTasks(head);

    return 0;
}