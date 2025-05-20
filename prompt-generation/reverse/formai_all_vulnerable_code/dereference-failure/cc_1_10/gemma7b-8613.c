//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char *name;
    int priority;
    int execution_time;
    struct Task *next;
} Task;

Task *create_task(char *name, int priority, int execution_time) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    return new_task;
}

void add_task(Task **head, Task *new_task) {
    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
        *head = new_task;
    }
}

void schedule_tasks(Task *head) {
    while (head) {
        printf("Task name: %s, priority: %d, execution time: %d\n", head->name, head->priority, head->execution_time);
        sleep(head->execution_time);
        head = head->next;
    }
}

int main() {
    Task *head = NULL;
    Task *new_task1 = create_task("Task 1", 1, 5);
    Task *new_task2 = create_task("Task 2", 2, 3);
    Task *new_task3 = create_task("Task 3", 3, 2);

    add_task(&head, new_task1);
    add_task(&head, new_task2);
    add_task(&head, new_task3);

    schedule_tasks(head);

    return 0;
}