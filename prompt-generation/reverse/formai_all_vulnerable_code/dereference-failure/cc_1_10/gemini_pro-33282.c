//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the task structure
typedef struct task {
    int id;
    char *name;
    time_t start_time;
    time_t end_time;
    int status; // 0: not started, 1: running, 2: completed
} task_t;

// Define the task scheduler structure
typedef struct task_scheduler {
    task_t *tasks;
    int num_tasks;
    int max_tasks;
} task_scheduler_t;

// Create a new task scheduler
task_scheduler_t *task_scheduler_create() {
    task_scheduler_t *scheduler = malloc(sizeof(task_scheduler_t));
    scheduler->tasks = NULL;
    scheduler->num_tasks = 0;
    scheduler->max_tasks = 10;
    return scheduler;
}

// Destroy a task scheduler
void task_scheduler_destroy(task_scheduler_t *scheduler) {
    for (int i = 0; i < scheduler->num_tasks; i++) {
        free(scheduler->tasks[i].name);
    }
    free(scheduler->tasks);
    free(scheduler);
}

// Add a task to the scheduler
int task_scheduler_add_task(task_scheduler_t *scheduler, task_t task) {
    if (scheduler->num_tasks >= scheduler->max_tasks) {
        return -1; // Error: task scheduler is full
    }

    scheduler->tasks = realloc(scheduler->tasks, sizeof(task_t) * (scheduler->num_tasks + 1));
    scheduler->tasks[scheduler->num_tasks] = task;
    scheduler->num_tasks++;

    return 0; // Success
}

// Remove a task from the scheduler
int task_scheduler_remove_task(task_scheduler_t *scheduler, int id) {
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].id == id) {
            // Found the task

            // Shift the tasks after the removed task to the left
            for (int j = i + 1; j < scheduler->num_tasks; j++) {
                scheduler->tasks[j - 1] = scheduler->tasks[j];
            }

            // Decrement the number of tasks
            scheduler->num_tasks--;

            return 0; // Success
        }
    }

    return -1; // Error: task not found
}

// Get a task by its ID
task_t *task_scheduler_get_task(task_scheduler_t *scheduler, int id) {
    for (int i = 0; i < scheduler->num_tasks; i++) {
        if (scheduler->tasks[i].id == id) {
            return &scheduler->tasks[i];
        }
    }

    return NULL; // Error: task not found
}

// Print the tasks in the scheduler
void task_scheduler_print_tasks(task_scheduler_t *scheduler) {
    printf("Tasks:\n");
    for (int i = 0; i < scheduler->num_tasks; i++) {
        printf("  - ID: %d\n", scheduler->tasks[i].id);
        printf("    - Name: %s\n", scheduler->tasks[i].name);
        printf("    - Start time: %s\n", ctime(&scheduler->tasks[i].start_time));
        printf("    - End time: %s\n", ctime(&scheduler->tasks[i].end_time));
        printf("    - Status: %d\n", scheduler->tasks[i].status);
    }
}

// Main function
int main() {
    // Create a task scheduler
    task_scheduler_t *scheduler = task_scheduler_create();

    // Add some tasks to the scheduler
    task_t task1 = {
        .id = 1,
        .name = "Task 1",
        .start_time = time(NULL),
        .end_time = time(NULL) + 600, // 10 minutes
        .status = 0,
    };
    task_scheduler_add_task(scheduler, task1);

    task_t task2 = {
        .id = 2,
        .name = "Task 2",
        .start_time = time(NULL) + 300, // 5 minutes from now
        .end_time = time(NULL) + 900, // 15 minutes from now
        .status = 0,
    };
    task_scheduler_add_task(scheduler, task2);

    task_t task3 = {
        .id = 3,
        .name = "Task 3",
        .start_time = time(NULL) + 600, // 10 minutes from now
        .end_time = time(NULL) + 1200, // 20 minutes from now
        .status = 0,
    };
    task_scheduler_add_task(scheduler, task3);

    // Print the tasks in the scheduler
    task_scheduler_print_tasks(scheduler);

    // Run the task scheduler
    while (1) {
        // Get the current time
        time_t now = time(NULL);

        // Check if any tasks are scheduled to start now
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i].status == 0 && scheduler->tasks[i].start_time <= now) {
                // Start the task
                scheduler->tasks[i].status = 1;

                printf("Starting task %s\n", scheduler->tasks[i].name);
            }
        }

        // Check if any tasks are scheduled to end now
        for (int i = 0; i < scheduler->num_tasks; i++) {
            if (scheduler->tasks[i].status == 1 && scheduler->tasks[i].end_time <= now) {
                // End the task
                scheduler->tasks[i].status = 2;

                printf("Ending task %s\n", scheduler->tasks[i].name);
            }
        }

        // Sleep for 1 second
        sleep(1);
    }

    // Destroy the task scheduler
    task_scheduler_destroy(scheduler);

    return 0;
}