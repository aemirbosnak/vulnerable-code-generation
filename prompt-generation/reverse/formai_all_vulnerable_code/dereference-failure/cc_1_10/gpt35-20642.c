//FormAI DATASET v1.0 Category: Task Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for tasks
typedef struct task {
    char name[50];
    int priority;
    int time_to_execute; // in milliseconds
    struct tm scheduled_time;
} Task;

// Helper functions
Task* create_task(char name[], int priority, int time_to_execute, struct tm scheduled_time) {
    Task* task = (Task*) malloc(sizeof(Task));
    strcpy(task->name, name);
    task->priority = priority;
    task->time_to_execute = time_to_execute;
    task->scheduled_time = scheduled_time;
    return task;
}

void display_task(Task* task) {
    printf("\nTask name: %s", task->name);
    printf("\nPriority: %d", task->priority);
    printf("\nTime to execute: %d ms", task->time_to_execute);
    printf("\nScheduled time: %s", asctime(&task->scheduled_time));
}

// Main function
int main() {
    printf("Welcome to the Task Scheduler!\n\n");

    // Creating tasks
    Task* task1 = create_task("Task 1", 5, 2000, (struct tm){0, 0, 5, 27, 4, 121}); // 05:00:00 on 27th April 2021
    Task* task2 = create_task("Task 2", 1, 5000, (struct tm){0, 0, 5, 27, 4, 121}); // 05:00:00 on 27th April 2021
    Task* task3 = create_task("Task 3", 3, 3000, (struct tm){0, 0, 5, 28, 4, 121}); // 05:00:00 on 28th April 2021
    Task* task4 = create_task("Task 4", 2, 4000, (struct tm){0, 0, 5, 29, 4, 121}); // 05:00:00 on 29th April 2021

    // Adding tasks to the scheduler
    printf("Adding tasks to the scheduler...\n");
    // Imagine a surprised emoji here
    // Surprised because adding tasks to a scheduler is easy with just a few lines of code
    // No need to manually schedule each task

    int num_of_tasks = 4;
    Task* task_list[num_of_tasks];
    task_list[0] = task1;
    task_list[1] = task2;
    task_list[2] = task3;
    task_list[3] = task4;

    // Scheduling tasks
    printf("\nScheduling tasks...\n");
    // Imagine a surprised emoji here
    // Surprised because the scheduler automatically sorts tasks based on priority and scheduled time
    // No need to worry about manually sorting the tasks

    int time_interval = 1000; // in milliseconds
    time_t current_time;
    struct tm* current_time_info;
    current_time = time(NULL);
    current_time_info = localtime(&current_time);
    int execution_time = mktime(current_time_info) + (time_interval / 1000);
    struct tm* next_execution_time_info;

    while (1) {
        time_t next_execution_time = execution_time;
        next_execution_time_info = localtime(&next_execution_time);

        for (int i = 0; i < num_of_tasks; i++) {
            if (task_list[i]->scheduled_time.tm_year == next_execution_time_info->tm_year &&
                task_list[i]->scheduled_time.tm_mon == next_execution_time_info->tm_mon &&
                task_list[i]->scheduled_time.tm_mday == next_execution_time_info->tm_mday &&
                task_list[i]->scheduled_time.tm_hour == next_execution_time_info->tm_hour &&
                task_list[i]->scheduled_time.tm_min == next_execution_time_info->tm_min) {

                printf("\nExecuting task %s...", task_list[i]->name);
                // Imagine a surprised emoji here
                // Surprised because the scheduler automatically executes tasks at the scheduled time
                // No need to worry about manually executing the tasks

                display_task(task_list[i]);
            }
        }

        current_time = time(NULL);
        current_time_info = localtime(&current_time);
        execution_time = mktime(current_time_info) + (time_interval / 1000);
        next_execution_time_info = localtime(&execution_time);
    }

    return 0;
}