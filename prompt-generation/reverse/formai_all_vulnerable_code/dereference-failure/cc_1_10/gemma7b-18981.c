//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, int estimated_time) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_time = estimated_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void print_tasks(Task* head) {
    while (head) {
        printf("%s (priority: %d, estimated time: %d)\n", head->name, head->priority, head->estimated_time);
        head = head->next;
    }
}

void schedule_tasks(Task* head) {
    time_t now = time(NULL);
    for (Task* current_task = head; current_task; current_task = current_task->next) {
        int estimated_time = current_task->estimated_time;
        if (estimated_time - now >= 0) {
            printf("%s is scheduled to start in %d minutes\n", current_task->name, (estimated_time - now) / 60);
        }
    }
}

int main() {
    Task* head = NULL;

    add_task(&head, "Task 1", 1, 30);
    add_task(&head, "Task 2", 2, 45);
    add_task(&head, "Task 3", 3, 60);

    print_tasks(head);
    schedule_tasks(head);

    return 0;
}