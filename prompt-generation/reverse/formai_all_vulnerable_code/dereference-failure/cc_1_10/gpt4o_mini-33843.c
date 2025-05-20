//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Structure to define a task
typedef struct Task {
    char *description;
    int interval; // Interval in seconds
    int duration; // Duration in seconds
    struct Task *next;
} Task;

// Function to execute a task
void *execute_task(void *arg) {
    Task *task = (Task *)arg;
    printf("Executing task: %s\n", task->description);
    sleep(task->duration);
    printf("Task %s completed after %d seconds\n", task->description, task->duration);
    return NULL;
}

// Function to create a new task
Task *create_task(char *description, int interval, int duration) {
    Task *new_task = (Task *)malloc(sizeof(Task));
    new_task->description = description;
    new_task->interval = interval;
    new_task->duration = duration;
    new_task->next = NULL;
    return new_task;
}

// Function to schedule tasks
void schedule_tasks(Task *task_list) {
    Task *current_task = task_list;
    while (current_task != NULL) {
        pthread_t thread_id;
        int result = pthread_create(&thread_id, NULL, execute_task, current_task);
        if (result != 0) {
            fprintf(stderr, "Error creating thread for task: %s\n", current_task->description);
        }
        sleep(current_task->interval); // Wait for next interval before scheduling the next task
        current_task = current_task->next;
    }
}

// Function to clean up tasks
void cleanup_tasks(Task *task_list) {
    Task *current_task = task_list;
    while (current_task != NULL) {
        Task *temp = current_task;
        current_task = current_task->next;
        free(temp);
    }
}

// Main function to demonstrate task scheduling
int main() {
    printf("Simple Task Scheduler Example\n");

    // Create a list of tasks
    Task *task1 = create_task("Task 1: Data Collection", 2, 3); // Run every 2 seconds, takes 3 seconds
    Task *task2 = create_task("Task 2: Data Processing", 3, 2); // Run every 3 seconds, takes 2 seconds
    Task *task3 = create_task("Task 3: Data Analysis", 5, 4);   // Run every 5 seconds, takes 4 seconds

    // Link tasks
    task1->next = task2;
    task2->next = task3;

    // Schedule the tasks
    schedule_tasks(task1);

    // Wait for all threads to complete
    pthread_exit(NULL);

    // Clean up
    cleanup_tasks(task1);
    
    return 0;
}