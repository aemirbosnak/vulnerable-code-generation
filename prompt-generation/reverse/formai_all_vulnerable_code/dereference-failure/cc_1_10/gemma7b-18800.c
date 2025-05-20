//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: modular
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

void scheduler_init(Task** head) {
    *head = NULL;
}

void scheduler_add(Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* new_task = malloc(sizeof(Task));
    strcpy(new_task->name, name);
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

time_t scheduler_get_next_task(Task** head) {
    time_t now = time(NULL);
    Task* current = *head;

    while (current) {
        if (now >= current->start_time && now < current->end_time) {
            return current->start_time;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    Task* head = NULL;
    scheduler_init(&head);

    scheduler_add(&head, "Task 1", 1, 10, 20);
    scheduler_add(&head, "Task 2", 2, 15, 25);
    scheduler_add(&head, "Task 3", 3, 20, 30);

    time_t next_task_time = scheduler_get_next_task(&head);
    if (next_task_time != -1) {
        printf("Next task start time: %ld\n", next_task_time);
    } else {
        printf("No tasks found.\n");
    }

    return 0;
}