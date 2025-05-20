//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

// Define the maximum number of tasks
#define MAX_TASKS 10

// Define the possible states of a task
typedef enum {
    TASK_PENDING,
    TASK_RUNNING,
    TASK_COMPLETED
} task_state;

// Define a task structure
typedef struct {
    int id;
    char *name;
    int priority;
    task_state state;
    void (*task_function)(void *);
    void *task_data;
} task;

// Define a linked list node structure
typedef struct node {
    task *task;
    struct node *next;
} node;

// Define the task scheduler structure
typedef struct {
    node *head;
    node *tail;
    int num_tasks;
} task_scheduler;

// Create a new task scheduler
task_scheduler *create_task_scheduler() {
    task_scheduler *scheduler = malloc(sizeof(task_scheduler));
    scheduler->head = NULL;
    scheduler->tail = NULL;
    scheduler->num_tasks = 0;
    return scheduler;
}

// Destroy a task scheduler
void destroy_task_scheduler(task_scheduler *scheduler) {
    node *current = scheduler->head;
    while (current != NULL) {
        node *next = current->next;
        free(current->task->name);
        free(current->task);
        free(current);
        current = next;
    }
    free(scheduler);
}

// Add a task to the task scheduler
void add_task(task_scheduler *scheduler, task *task) {
    node *new_node = malloc(sizeof(node));
    new_node->task = task;
    new_node->next = NULL;
    if (scheduler->head == NULL) {
        scheduler->head = new_node;
        scheduler->tail = new_node;
    } else {
        scheduler->tail->next = new_node;
        scheduler->tail = new_node;
    }
    scheduler->num_tasks++;
}

// Get the next task to run from the task scheduler
task *get_next_task(task_scheduler *scheduler) {
    if (scheduler->head == NULL) {
        return NULL;
    } else {
        task *task = scheduler->head->task;
        scheduler->head = scheduler->head->next;
        if (scheduler->head == NULL) {
            scheduler->tail = NULL;
        }
        scheduler->num_tasks--;
        return task;
    }
}

// Run the next task in the task scheduler
void run_next_task(task_scheduler *scheduler) {
    task *task = get_next_task(scheduler);
    if (task != NULL) {
        task->state = TASK_RUNNING;
        task->task_function(task->task_data);
        task->state = TASK_COMPLETED;
    }
}

// Create a new task
task *create_task(int id, char *name, int priority, void (*task_function)(void *), void *task_data) {
    task *task = malloc(sizeof(task));
    task->id = id;
    task->name = strdup(name);
    task->priority = priority;
    task->state = TASK_PENDING;
    task->task_function = task_function;
    task->task_data = task_data;
    return task;
}

// Destroy a task
void destroy_task(task *task) {
    free(task->name);
    free(task);
}

// Example task function
void example_task_function(void *data) {
    printf("Example task function called with data: %s\n", (char *)data);
}

// Main function
int main() {
    // Create a new task scheduler
    task_scheduler *scheduler = create_task_scheduler();

    // Create some tasks
    task *task1 = create_task(1, "Task 1", 1, example_task_function, "Task 1 data");
    task *task2 = create_task(2, "Task 2", 2, example_task_function, "Task 2 data");
    task *task3 = create_task(3, "Task 3", 3, example_task_function, "Task 3 data");

    // Add the tasks to the task scheduler
    add_task(scheduler, task1);
    add_task(scheduler, task2);
    add_task(scheduler, task3);

    // Run the tasks
    while (scheduler->num_tasks > 0) {
        run_next_task(scheduler);
    }

    // Destroy the task scheduler
    destroy_task_scheduler(scheduler);

    return 0;
}