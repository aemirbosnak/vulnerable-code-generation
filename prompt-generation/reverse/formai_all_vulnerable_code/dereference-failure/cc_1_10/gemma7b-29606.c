//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10
#define TASK_STATE_NEW 0
#define TASK_STATE_RUNNING 1
#define TASK_STATE_COMPLETED 2

typedef struct Task {
    char *name;
    int state;
    int start_time;
    int end_time;
    struct Task *next;
} Task;

Task *head = NULL;

void schedule_task(char *name, int start_time, int end_time) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->name = name;
    new_task->state = TASK_STATE_NEW;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_task;
    }
}

void execute_scheduler() {
    time_t current_time = time(NULL);

    Task *current_task = head;
    while (current_task) {
        if (current_time >= current_task->start_time && current_time < current_task->end_time) {
            printf("Executing task: %s\n", current_task->name);
            current_task->state = TASK_STATE_RUNNING;
        } else if (current_task->state == TASK_STATE_NEW) {
            printf("Waiting for task: %s to start\n", current_task->name);
        }
        current_task = current_task->next;
    }
}

int main() {
    schedule_task("Task 1", 10, 20);
    schedule_task("Task 2", 15, 25);
    schedule_task("Task 3", 20, 30);

    execute_scheduler();

    return 0;
}