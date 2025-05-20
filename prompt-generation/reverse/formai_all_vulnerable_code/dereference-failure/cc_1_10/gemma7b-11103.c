//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_TASKS 10

typedef struct task_t {
    char name[20];
    int priority;
    int start_time;
    int end_time;
    struct task_t* next;
} task_t;

void add_task(task_t** head) {
    task_t* new_task = malloc(sizeof(task_t));
    scanf("Enter task name: ", new_task->name);
    scanf("Enter task priority (1-10): ", &new_task->priority);
    scanf("Enter task start time (HH:MM): ", &new_task->start_time);
    scanf("Enter task end time (HH:MM): ", &new_task->end_time);
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_tasks(task_t* head) {
    time_t current_time = time(NULL);
    task_t* current_task = head;

    while (current_task) {
        if (current_time >= current_task->start_time && current_time < current_task->end_time) {
            printf("Currently executing: %s\n", current_task->name);
        }
        current_task = current_task->next;
    }
}

int main() {
    task_t* head = NULL;
    add_task(&head);
    add_task(&head);
    add_task(&head);
    schedule_tasks(head);

    return 0;
}