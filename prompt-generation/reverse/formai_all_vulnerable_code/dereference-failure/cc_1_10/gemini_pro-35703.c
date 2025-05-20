//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    int id;
    int delay;
    void (*func)(void);
} task;

// Task queue
static task *queue = NULL;
static int queue_len = 0;

// Task scheduler
void task_scheduler(void) {
    while (true) {
        // Get the current time
        time_t now = time(NULL);

        // Check for any tasks that are ready to run
        for (int i = 0; i < queue_len; i++) {
            task *t = &queue[i];

            // If the task is ready to run, call its function
            if (now >= t->delay) {
                t->func();

                // Remove the task from the queue
                for (int j = i; j < queue_len - 1; j++) {
                    queue[j] = queue[j + 1];
                }
                queue_len--;
            }
        }

        // Sleep for 1 second
        sleep(1);
    }
}

// Add a task to the queue
void task_add(int delay, void (*func)(void)) {
    // Allocate memory for the new task
    task *new_task = malloc(sizeof(task));

    // Initialize the new task
    new_task->id = queue_len + 1;
    new_task->delay = delay;
    new_task->func = func;

    // Add the new task to the queue
    queue = realloc(queue, sizeof(task) * (queue_len + 1));
    queue[queue_len] = *new_task;
    queue_len++;
}

// Task 1
void task_1(void) {
    printf("Task 1 running\n");
}

// Task 2
void task_2(void) {
    printf("Task 2 running\n");
}

// Main function
int main(void) {
    // Add tasks to the queue
    task_add(5, task_1);
    task_add(10, task_2);

    // Start the task scheduler
    task_scheduler();

    return 0;
}