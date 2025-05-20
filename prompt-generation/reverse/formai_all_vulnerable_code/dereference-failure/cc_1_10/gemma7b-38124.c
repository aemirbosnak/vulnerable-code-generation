//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task *next;
} Task;

void addTask(Task **head, char *name, int priority, time_t start_time, time_t end_time) {
    Task *newTask = malloc(sizeof(Task));
    newTask->name = strdup(name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task *head) {
    time_t current_time = time(NULL);
    Task *currentTask = head;

    while (currentTask) {
        if (current_time >= currentTask->start_time && current_time < currentTask->end_time) {
            printf("Executing task: %s\n", currentTask->name);
        }
        currentTask = currentTask->next;
    }
}

int main() {
    Task *head = NULL;

    addTask(head, "Task A", 1, 10, 15);
    addTask(head, "Task B", 2, 12, 16);
    addTask(head, "Task C", 1, 14, 18);

    scheduleTasks(head);

    return 0;
}