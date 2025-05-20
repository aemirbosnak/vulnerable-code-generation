//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Define the task structure
typedef struct task {
    int id;
    time_t scheduled_time;
    void (*task_function)(void);
} task_t;

// Create a task queue
task_t *task_queue = NULL;
int task_queue_size = 0;

// Add a task to the queue
void add_task(task_t task) {
    // Reallocate the task queue if necessary
    if (task_queue_size == 0) {
        task_queue = malloc(sizeof(task_t));
    } else {
        task_queue = realloc(task_queue, (task_queue_size + 1) * sizeof(task_t));
    }

    // Add the task to the queue
    task_queue[task_queue_size++] = task;
}

// Remove a task from the queue
void remove_task(int id) {
    // Find the task in the queue
    int i;
    for (i = 0; i < task_queue_size; i++) {
        if (task_queue[i].id == id) {
            break;
        }
    }

    // If the task was found, remove it from the queue
    if (i < task_queue_size) {
        for (int j = i; j < task_queue_size - 1; j++) {
            task_queue[j] = task_queue[j + 1];
        }
        task_queue_size--;
    }
}

// Run the tasks in the queue
void run_tasks() {
    // Get the current time
    time_t now = time(NULL);

    // Iterate over the tasks in the queue
    int i;
    for (i = 0; i < task_queue_size; i++) {
        // If the task is scheduled to run now, run it
        if (task_queue[i].scheduled_time <= now) {
            task_queue[i].task_function();
            remove_task(task_queue[i].id);
        }
    }
}

// Create a task that prints a message
void print_message(int id) {
    printf("Task %d: Hello, world!\n", id);
}

// Create a task that sleeps for a specified number of seconds
void sleep_task(int id, int seconds) {
    printf("Task %d: Sleeping for %d seconds...\n", id, seconds);
    sleep(seconds);
    printf("Task %d: Woke up!\n", id);
}

// Main function
int main() {
    // Create some tasks
    task_t task1 = { .id = 1, .scheduled_time = time(NULL) + 1, .task_function = print_message };
    task_t task2 = { .id = 2, .scheduled_time = time(NULL) + 3, .task_function = sleep_task };

    // Add the tasks to the queue
    add_task(task1);
    add_task(task2);

    // Run the tasks
    while (1) {
        run_tasks();
        sleep(1);
    }

    return 0;
}