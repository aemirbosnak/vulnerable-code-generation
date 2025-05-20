//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TASK_NAME 50
#define TIME_SLICE 2

typedef struct Task {
    char name[MAX_TASK_NAME];
    int burst_time;
    struct Task* next;
} Task;

typedef struct Scheduler {
    Task* head;
    Task* tail;
} Scheduler;

Scheduler* create_scheduler() {
    Scheduler* scheduler = (Scheduler*)malloc(sizeof(Scheduler));
    scheduler->head = NULL;
    scheduler->tail = NULL;
    return scheduler;
}

void add_task(Scheduler* scheduler, const char* name, int burst_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strncpy(new_task->name, name, MAX_TASK_NAME);
    new_task->burst_time = burst_time;
    new_task->next = NULL;

    if (scheduler->tail) {
        scheduler->tail->next = new_task;
    } else {
        scheduler->head = new_task;
    }
    scheduler->tail = new_task;
}

void execute_task(Task* task) {
    printf("Executing task: %s for %d seconds.\n", task->name, TIME_SLICE);
    sleep(TIME_SLICE); // Simulating task execution time
}

void run_scheduler(Scheduler* scheduler) {
    Task* current_task = scheduler->head;

    while (current_task) {
        if (current_task->burst_time > 0) {
            execute_task(current_task);
            current_task->burst_time -= TIME_SLICE; // Decrease burst time

            // Check if the task is complete
            if (current_task->burst_time <= 0) {
                printf("Task %s completed.\n", current_task->name);
                // Remove the completed task
                Task* temp = current_task;
                current_task = current_task->next;

                // Update linked list pointers
                if (scheduler->head == temp) {
                    scheduler->head = current_task;
                }
                // Point tail to last task if current_task is removed
                if (temp == scheduler->tail) {
                    scheduler->tail = NULL;
                }
                free(temp);
            } else {
                // Move to next task if incomplete
                current_task = current_task->next ? current_task->next : scheduler->head;
            }
        } else {
            // Move to next task if the current one has no burst time left
            current_task = current_task->next ? current_task->next : scheduler->head;
        }
    }
}

void free_scheduler(Scheduler* scheduler) {
    Task* current = scheduler->head;
    Task* next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    free(scheduler);
}

int main() {
    Scheduler* task_scheduler = create_scheduler();

    add_task(task_scheduler, "Task 1", 5);
    add_task(task_scheduler, "Task 2", 3);
    add_task(task_scheduler, "Task 3", 6);
    add_task(task_scheduler, "Task 4", 2);

    printf("Starting the task scheduler...\n");
    run_scheduler(task_scheduler);

    free_scheduler(task_scheduler);
    printf("All tasks have been completed.\n");

    return 0;
}