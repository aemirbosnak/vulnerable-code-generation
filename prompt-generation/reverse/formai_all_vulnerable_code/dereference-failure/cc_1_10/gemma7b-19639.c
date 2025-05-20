//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
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
    Task *newTask = (Task *)malloc(sizeof(Task));
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
    time_t now = time(NULL);
    Task *current = head;

    while (current) {
        if (current->start_time <= now && now <= current->end_time) {
            printf("Executing task: %s\n", current->name);
        }
        current = current->next;
    }
}

int main() {
    Task *head = NULL;

    addTask(head, "Task 1", 1, time(NULL) + 60, time(NULL) + 90);
    addTask(head, "Task 2", 2, time(NULL) + 30, time(NULL) + 60);
    addTask(head, "Task 3", 1, time(NULL) + 45, time(NULL) + 75);

    scheduleTasks(head);

    return 0;
}