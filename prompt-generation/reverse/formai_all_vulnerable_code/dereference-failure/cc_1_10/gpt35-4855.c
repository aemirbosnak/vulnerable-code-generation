//FormAI DATASET v1.0 Category: Task Scheduler ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Define the task struct
typedef struct {
    void (*task)(void);  // function pointer to the task
    int interval;  // interval in seconds between each execution
    bool is_running;  // flag to indicate if task is currently running
} Task;

// Define a global array to store all tasks
Task tasks[10];

// Define the task function for Task 1
void task1() {
    printf("Task 1 is running!\n");
}

// Define the task function for Task 2
void task2() {
    printf("Task 2 is running!\n");
}

// Define the task scheduler function
void* task_scheduler(void* arg) {
    while (true) {
        // Loop through all tasks
        for (int i = 0; i < sizeof(tasks)/sizeof(Task); i++) {
            // Check if task is running
            if (!tasks[i].is_running) {
                // Set task as running
                tasks[i].is_running = true;
                // Execute the task
                tasks[i].task();
                // Wait for interval before executing again
                sleep(tasks[i].interval);
                // Set task as not running
                tasks[i].is_running = false;
            }
        }
    }
}

int main() {
    // Initialize tasks
    tasks[0] = (Task) {.task = &task1, .interval = 1, .is_running = false};
    tasks[1] = (Task) {.task = &task2, .interval = 3, .is_running = false};

    // Create a thread to run the task scheduler
    pthread_t tid;
    pthread_create(&tid, NULL, &task_scheduler, NULL);

    // Wait for thread to join
    pthread_join(tid, NULL);

    return 0;
}