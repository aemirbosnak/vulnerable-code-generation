//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

// Task structure
typedef struct task {
    void (*func)(void *);  // Function to be executed
    void *arg;            // Argument to be passed to the function
    time_t next_run;      // Next time to run the task
    int interval;         // Interval between executions
} task;

// Global task list
task *tasks = NULL;

// Number of tasks
int num_tasks = 0;

// Signal handler for SIGALRM
void sigalrm_handler(int signum) {
    // Check if there are any tasks to run
    if (num_tasks == 0) {
        return;
    }

    // Get the current time
    time_t now = time(NULL);

    // Iterate over the tasks
    for (int i = 0; i < num_tasks; i++) {
        // Check if the task is ready to run
        if (tasks[i].next_run <= now) {
            // Run the task
            tasks[i].func(tasks[i].arg);

            // Update the next run time
            tasks[i].next_run = now + tasks[i].interval;
        }
    }

    // Set the next alarm
    alarm(1);
}

// Add a task to the scheduler
void add_task(void (*func)(void *), void *arg, int interval) {
    // Allocate memory for the new task
    task *new_task = malloc(sizeof(task));
    if (new_task == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Initialize the new task
    new_task->func = func;
    new_task->arg = arg;
    new_task->next_run = time(NULL) + interval;
    new_task->interval = interval;

    // Add the new task to the task list
    tasks = realloc(tasks, (num_tasks + 1) * sizeof(task));
    if (tasks == NULL) {
        perror("realloc");
        exit(EXIT_FAILURE);
    }
    tasks[num_tasks++] = *new_task;
}

// Print the current tasks
void print_tasks() {
    printf("Tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("  - %s (%d seconds)\n", tasks[i].func, tasks[i].interval);
    }
}

// Example function to be executed by a task
void example_function(void *arg) {
    printf("Example function called with argument: %s\n", (char *)arg);
}

int main() {
    // Set up the signal handler
    signal(SIGALRM, sigalrm_handler);

    // Add some example tasks
    add_task(example_function, "Hello world 1", 1);
    add_task(example_function, "Hello world 2", 2);
    add_task(example_function, "Hello world 3", 3);

    // Print the tasks
    print_tasks();

    // Set the first alarm
    alarm(1);

    // Loop forever
    while (1) {
        pause();
    }

    return 0;
}