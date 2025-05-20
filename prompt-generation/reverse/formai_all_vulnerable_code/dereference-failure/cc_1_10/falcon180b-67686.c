//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Struct for task information
typedef struct {
    char *name; // Name of the task
    time_t start_time; // Start time of the task
    time_t end_time; // End time of the task
    int priority; // Priority of the task
    int duration; // Duration of the task
} Task;

// Function to compare tasks based on their start time
int compare_tasks(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;
    return difftime(task_a->start_time, task_b->start_time);
}

// Function to execute a task
void *execute_task(void *param) {
    Task *task = (Task *)param;
    time_t current_time = time(NULL);

    // Check if it is time to start the task
    if (current_time >= task->start_time) {
        // Execute the task
        printf("Executing task '%s' at %s\n", task->name, ctime(&current_time));
        sleep(task->duration);
    }

    return NULL;
}

// Function to schedule tasks
void schedule_tasks() {
    Task tasks[] = {
        {"Task 1", 1609459200, 1609462800, 1, 1800},
        {"Task 2", 1609466400, 1609470000, 2, 1800},
        {"Task 3", 1609473600, 1609477200, 3, 1800},
        {"Task 4", 1609480800, 1609484400, 1, 1800},
        {"Task 5", 1609488000, 1609491600, 2, 1800},
        {"Task 6", 1609495200, 1609498800, 3, 1800}
    };

    int num_tasks = sizeof(tasks) / sizeof(Task);

    // Sort tasks based on their start time
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    // Execute each task
    for (int i = 0; i < num_tasks; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_task, &tasks[i]);
    }
}

int main() {
    schedule_tasks();
    return 0;
}