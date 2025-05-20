//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[50];
    time_t execution_time;
    struct Task* next;
} Task;

typedef struct TaskScheduler {
    Task* head;
} TaskScheduler;

void initialize_scheduler(TaskScheduler* scheduler) {
    scheduler->head = NULL;
}

void add_task(TaskScheduler* scheduler, const char* name, time_t execution_time) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strncpy(new_task->name, name, sizeof(new_task->name));
    new_task->execution_time = execution_time;
    new_task->next = NULL;

    if (scheduler->head == NULL || scheduler->head->execution_time > execution_time) {
        new_task->next = scheduler->head;
        scheduler->head = new_task;
    } else {
        Task* current = scheduler->head;
        while (current->next != NULL && current->next->execution_time < execution_time) {
            current = current->next;
        }
        new_task->next = current->next;
        current->next = new_task;
    }
}

void display_tasks(TaskScheduler* scheduler) {
    Task* current = scheduler->head;
    if (current == NULL) {
        printf("No tasks scheduled.\n");
        return;
    }
    printf("Scheduled Tasks:\n");
    while (current != NULL) {
        char time_str[26];
        ctime_r(&current->execution_time, time_str);
        time_str[strlen(time_str) - 1] = '\0'; // Remove newline character
        printf("Task Name: %s, Execution Time: %s\n", current->name, time_str);
        current = current->next;
    }
}

void execute_due_tasks(TaskScheduler* scheduler) {
    time_t now = time(NULL);
    Task* current = scheduler->head;
    Task* previous = NULL;

    while (current != NULL && current->execution_time <= now) {
        printf("Executing Task: %s\n", current->name);
        if (previous == NULL) {
            scheduler->head = current->next;
            free(current);
            current = scheduler->head;
        } else {
            previous->next = current->next;
            free(current);
            current = previous->next;
        }
    }
}

void free_scheduler(TaskScheduler* scheduler) {
    Task* current = scheduler->head;
    while (current != NULL) {
        Task* temp = current;
        current = current->next;
        free(temp);
    }
    scheduler->head = NULL;
}

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    time_t now = time(NULL);
    add_task(&scheduler, "Task 1", now + 5); // Execute in 5 seconds
    add_task(&scheduler, "Task 2", now + 10); // Execute in 10 seconds
    add_task(&scheduler, "Task 3", now + 3);  // Execute in 3 seconds
    add_task(&scheduler, "Task 4", now + 15); // Execute in 15 seconds

    display_tasks(&scheduler);

    printf("Waiting for tasks to execute...\n");
    while (scheduler.head != NULL) {
        sleep(1);
        execute_due_tasks(&scheduler);
    }

    free_scheduler(&scheduler);
    printf("All tasks have been executed. Scheduler is now empty.\n");

    return 0;
}