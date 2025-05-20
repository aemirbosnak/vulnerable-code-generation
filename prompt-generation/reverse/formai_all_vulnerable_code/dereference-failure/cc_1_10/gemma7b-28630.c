//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    int estimated_execution_time;
    struct Task *next;
} Task;

void scheduler_add(Task **head, char *name, int priority, int estimated_execution_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->estimated_execution_time = estimated_execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        Task *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void scheduler_print(Task *head) {
    printf("Tasks:\n");
    while (head) {
        printf("  - %s (Priority: %d, Estimated Execution Time: %d)\n", head->name, head->priority, head->estimated_execution_time);
        head = head->next;
    }
}

int main() {
    Task *head = NULL;

    scheduler_add(&head, "Task 1", 1, 5);
    scheduler_add(&head, "Task 2", 3, 2);
    scheduler_add(&head, "Task 3", 2, 3);
    scheduler_add(&head, "Task 4", 4, 4);

    scheduler_print(head);

    return 0;
}