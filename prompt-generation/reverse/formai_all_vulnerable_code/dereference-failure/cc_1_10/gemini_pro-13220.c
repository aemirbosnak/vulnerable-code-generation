//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The task structure represents a single task to be executed.
typedef struct task {
    char *name;              // The name of the task.
    int priority;            // The priority of the task.
    void (*function)();      // The function to be executed.
    struct task *next;       // The next task in the list.
} task;

// The task scheduler structure represents the task scheduler.
typedef struct task_scheduler {
    task *head;              // The head of the task list.
    task *tail;              // The tail of the task list.
} task_scheduler;

// Create a new task.
task *task_create(char *name, int priority, void (*function)()) {
    task *new_task = malloc(sizeof(task));
    new_task->name = strdup(name);
    new_task->priority = priority;
    new_task->function = function;
    new_task->next = NULL;
    return new_task;
}

// Add a new task to the task scheduler.
void task_scheduler_add(task_scheduler *scheduler, task *new_task) {
    if (scheduler->head == NULL) {
        scheduler->head = new_task;
        scheduler->tail = new_task;
    } else {
        scheduler->tail->next = new_task;
        scheduler->tail = new_task;
    }
}

// Execute the next highest priority task in the task scheduler.
void task_scheduler_run(task_scheduler *scheduler) {
    task *current_task = scheduler->head;
    while (current_task != NULL) {
        if (current_task->priority > 0) {
            current_task->function();
            current_task->priority--;
        }
        current_task = current_task->next;
    }
}

// Create a new task scheduler.
task_scheduler *task_scheduler_create() {
    task_scheduler *new_scheduler = malloc(sizeof(task_scheduler));
    new_scheduler->head = NULL;
    new_scheduler->tail = NULL;
    return new_scheduler;
}

// Destroy a task scheduler.
void task_scheduler_destroy(task_scheduler *scheduler) {
    task *current_task = scheduler->head;
    while (current_task != NULL) {
        task *next_task = current_task->next;
        free(current_task->name);
        free(current_task);
        current_task = next_task;
    }
    free(scheduler);
}

// Example function to be executed by a task.
void example_function() {
    printf("Hello, world!\n");
}

int main() {
    // Create a task scheduler.
    task_scheduler *scheduler = task_scheduler_create();

    // Add some tasks to the task scheduler.
    task *task1 = task_create("Task 1", 10, example_function);
    task_scheduler_add(scheduler, task1);

    task *task2 = task_create("Task 2", 5, example_function);
    task_scheduler_add(scheduler, task2);

    task *task3 = task_create("Task 3", 1, example_function);
    task_scheduler_add(scheduler, task3);

    // Run the tasks in the task scheduler.
    while (scheduler->head != NULL) {
        task_scheduler_run(scheduler);
    }

    // Destroy the task scheduler.
    task_scheduler_destroy(scheduler);

    return 0;
}