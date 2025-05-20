//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// Task structure
typedef struct task {
    char *name;             // Task name
    int priority;           // Task priority
    int interval;           // Task interval in seconds
    void (*function)();     // Task function
} task;

// Task queue
task *queue[100];
int queue_size = 0;

// Task scheduler
void schedule() {
    while (1) {
        // Find the next task to run
        int next_task = -1;
        for (int i = 0; i < queue_size; i++) {
            if (queue[i]->interval == 0) {
                next_task = i;
                break;
            }
        }

        // If no task found, wait for a second
        if (next_task == -1) {
            sleep(1);
            continue;
        }

        // Run the task
        queue[next_task]->function();

        // Increment the interval of the task
        queue[next_task]->interval++;

        // Check if the task is finished
        if (queue[next_task]->interval >= queue[next_task]->priority) {
            // Remove the task from the queue
            for (int i = next_task; i < queue_size - 1; i++) {
                queue[i] = queue[i + 1];
            }
            queue_size--;
        }
    }
}

// Task 1: Print "Hello, world!"
void task1() {
    printf("Hello, world!\n");
}

// Task 2: Print "Goodbye, world!"
void task2() {
    printf("Goodbye, world!\n");
}

// Task 3: Exit the program
void task3() {
    exit(0);
}

// Main function
int main() {
    // Add tasks to the queue
    queue[0] = malloc(sizeof(task));
    queue[0]->name = "Task 1";
    queue[0]->priority = 1;
    queue[0]->interval = 0;
    queue[0]->function = task1;

    queue[1] = malloc(sizeof(task));
    queue[1]->name = "Task 2";
    queue[1]->priority = 2;
    queue[1]->interval = 0;
    queue[1]->function = task2;

    queue[2] = malloc(sizeof(task));
    queue[2]->name = "Task 3";
    queue[2]->priority = 3;
    queue[2]->interval = 0;
    queue[2]->function = task3;

    queue_size = 3;

    // Start the scheduler
    schedule();

    return 0;
}