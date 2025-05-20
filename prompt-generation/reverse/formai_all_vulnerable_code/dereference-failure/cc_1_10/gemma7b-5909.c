//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    struct Task *next;
} Task;

Task *scheduler_insert(Task *head, char *name, int priority) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task *current = head;
        Task *previous = NULL;
        while (current) {
            if (new_task->priority < current->priority) {
                previous = current;
                current = current->next;
            }
        }
        if (previous) {
            previous->next = new_task;
        } else {
            head = new_task;
        }
    }

    return head;
}

void scheduler_print(Task *head) {
    Task *current = head;
    while (current) {
        printf("%s (priority: %d)\n", current->name, current->priority);
        current = current->next;
    }
}

int main() {
    Task *head = NULL;

    head = scheduler_insert(head, "Task 1", 1);
    head = scheduler_insert(head, "Task 2", 3);
    head = scheduler_insert(head, "Task 3", 2);
    head = scheduler_insert(head, "Task 4", 4);

    scheduler_print(head);

    return 0;
}