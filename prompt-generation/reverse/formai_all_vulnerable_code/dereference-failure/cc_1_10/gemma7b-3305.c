//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_execution_time;
    struct Task* next;
} Task;

void add_task(Task** head, char* name, int priority, int estimated_execution_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->estimated_execution_time = estimated_execution_time;
    new_task->next = NULL;

    if (*head == NULL) {
        *head = new_task;
    } else {
        (*head)->next = new_task;
    }
}

void schedule_tasks(Task** head) {
    time_t now = time(NULL);
    int i = 0;

    for (Task* task = *head; task; task = task->next) {
        int estimated_execution_time = task->estimated_execution_time;
        int time_until_execution = estimated_execution_time - (int)now;

        if (time_until_execution > 0) {
            printf("%s will execute in %d minutes\n", task->name, time_until_execution / 60);
        } else {
            printf("%s is executing\n", task->name);
        }
    }
}

int main() {
    Task* head = NULL;

    add_task(&head, "Write a C Task Scheduler", 1, 60);
    add_task(&head, "Learn Assembly Language", 3, 120);
    add_task(&head, "Create a Turing Machine Simulator", 2, 80);

    schedule_tasks(&head);

    return 0;
}