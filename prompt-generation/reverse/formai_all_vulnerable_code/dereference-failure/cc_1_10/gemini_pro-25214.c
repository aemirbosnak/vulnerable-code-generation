//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the task struct
typedef struct task {
    int id;
    char *name;
    void (*func)(void *);
    void *args;
    time_t start_time;
    time_t end_time;
} task_t;

// Define the task queue
static task_t **task_queue;
static int task_queue_size = 0;
static int task_queue_capacity = 0;

// Define the task scheduler
static void task_scheduler(void) {
    while (task_queue_size > 0) {
        // Get the next task from the queue
        task_t *task = task_queue[0];

        // Execute the task
        task->func(task->args);

        // Remove the task from the queue
        for (int i = 0; i < task_queue_size - 1; i++) {
            task_queue[i] = task_queue[i + 1];
        }
        task_queue_size--;

        // Print a message about the task
        printf("Task %d (%s) completed at %s\n", task->id, task->name, ctime(&task->end_time));

        // Free the task
        free(task->name);
        free(task);
    }
}

// Define a function to add a task to the queue
static void add_task(int id, char *name, void (*func)(void *), void *args) {
    // Create a new task
    task_t *task = malloc(sizeof(task_t));
    task->id = id;
    task->name = name;
    task->func = func;
    task->args = args;
    task->start_time = time(NULL);

    // Add the task to the queue
    if (task_queue_size == task_queue_capacity) {
        task_queue_capacity *= 2;
        task_queue = realloc(task_queue, task_queue_capacity * sizeof(task_t *));
    }
    task_queue[task_queue_size++] = task;
}

// Define a function to run a task
static void run_task(task_t *task) {
    // Execute the task
    task->func(task->args);

    // Mark the task as completed
    task->end_time = time(NULL);
}

// Define a function to print a message
static void print_message(void *args) {
    char *message = (char *) args;
    printf("%s\n", message);
}

// Define a function to sleep for a specified number of seconds
static void sleep_seconds(void *args) {
    int seconds = *(int *) args;
    sleep(seconds);
}

// Define the main function
int main(void) {
    // Add some tasks to the queue
    add_task(1, "Task 1", print_message, "Hello from Task 1!");
    add_task(2, "Task 2", sleep_seconds, malloc(sizeof(int)));
    add_task(3, "Task 3", print_message, "Hello from Task 3!");

    // Run the task scheduler
    task_scheduler();

    return 0;
}