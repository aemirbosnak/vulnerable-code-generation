//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void scheduler_insert(Task** head, Task* new_task) {
    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
        *head = new_task;
    }
}

void scheduler_print(Task* head) {
    while (head) {
        printf("%s (priority: %d), start: %s, end: %s\n", head->name, head->priority, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;
    Task* new_task;

    // Create a few tasks
    new_task = malloc(sizeof(Task));
    strcpy(new_task->name, "Task 1");
    new_task->priority = 1;
    new_task->start_time = time(NULL) + 300;
    new_task->end_time = time(NULL) + 600;
    scheduler_insert(&head, new_task);

    new_task = malloc(sizeof(Task));
    strcpy(new_task->name, "Task 2");
    new_task->priority = 3;
    new_task->start_time = time(NULL) + 400;
    new_task->end_time = time(NULL) + 700;
    scheduler_insert(&head, new_task);

    new_task = malloc(sizeof(Task));
    strcpy(new_task->name, "Task 3");
    new_task->priority = 2;
    new_task->start_time = time(NULL) + 500;
    new_task->end_time = time(NULL) + 800;
    scheduler_insert(&head, new_task);

    // Print the tasks
    scheduler_print(head);

    return 0;
}