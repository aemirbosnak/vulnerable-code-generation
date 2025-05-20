//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

// Custom task structure
typedef struct task {
    // Task name
    char *name;

    // Function pointer to the task's execution logic
    void (*func)(void *arg);

    // Argument to be passed to the task
    void *arg;

    // Task's execution time in milliseconds
    int delay;
} task;

// Task queue
task *tasks = NULL;

// Task queue size
int task_count = 0;

// Task queue capacity
int task_capacity = 0;

// Function to add a task to the queue
void add_task(char *name, void (*func)(void *arg), void *arg, int delay) {
    // Increase task queue capacity if necessary
    if (task_count == task_capacity) {
        task_capacity *= 2;
        tasks = realloc(tasks, task_capacity * sizeof(task));
    }

    // Initialize new task
    tasks[task_count].name = name;
    tasks[task_count].func = func;
    tasks[task_count].arg = arg;
    tasks[task_count].delay = delay;

    task_count++;
}

// Function to execute all tasks in the queue
void execute_tasks() {
    // Iterate through the task queue
    for (int i = 0; i < task_count; i++) {
        // Get current time
        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        // Execute task
        tasks[i].func(tasks[i].arg);

        // Get execution time
        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        
        // Print task execution time
        printf("Task %s executed in %ld milliseconds\n", tasks[i].name, (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000);
    }
}

// Function to print the task queue
void print_tasks() {
    // Iterate through the task queue
    for (int i = 0; i < task_count; i++) {
        // Print task details
        printf("Task %d:\n", i + 1);
        printf("Name: %s\n", tasks[i].name);
        printf("Function: %p\n", tasks[i].func);
        printf("Argument: %p\n", tasks[i].arg);
        printf("Delay: %d milliseconds\n", tasks[i].delay);
        printf("\n");
    }
}

// Task 1: Print "Hello, world!"
void task1(void *arg) {
    printf("Hello, world!\n");
}

// Task 2: Print "Goodbye, world!"
void task2(void *arg) {
    printf("Goodbye, world!\n");
}

// Main function
int main() {
    // Add tasks to the queue
    add_task("Task 1", &task1, NULL, 1000);
    add_task("Task 2", &task2, NULL, 2000);

    // Print the task queue
    print_tasks();

    // Execute all tasks in the queue
    execute_tasks();

    return 0;
}