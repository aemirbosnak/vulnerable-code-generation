//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct Task {
    char *name;
    int priority;
    int start_time;
    int end_time;
    struct Task *next;
} Task;

void add_task(Task **head, char *name, int priority, int start_time, int end_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_tasks(Task *head) {
    time_t current_time = time(NULL);
    Task *current_task = head;

    while (current_task) {
        if (current_time >= current_task->start_time && current_time < current_task->end_time) {
            printf("Task: %s, Priority: %d, Start Time: %d, End Time: %d\n", current_task->name, current_task->priority, current_task->start_time, current_task->end_time);
        }
        current_task = current_task->next;
    }
}

int main() {
    Task *head = NULL;

    add_task(&head, "Task 1", 1, 10, 20);
    add_task(&head, "Task 2", 2, 15, 25);
    add_task(&head, "Task 3", 3, 20, 30);
    add_task(&head, "Task 4", 4, 25, 35);
    add_task(&head, "Task 5", 5, 30, 40);

    schedule_tasks(head);

    return 0;
}